#include "include/parser.h"

Parser *parser_new_parser(Lexer *lexer)
{
	Parser *parser = new(Parser);
	parser->lexer = lexer;
	parser->current_token = lexer_get_next_token(parser->lexer);

	return parser;
}

void parser_match(Parser *parser, Token_Type type)
{
	if (parser->current_token->type == type)
		parser->current_token = lexer_get_next_token(parser->lexer);
	
	else
		EXPECTED_ERROR(
			parser->current_token->position->file_name,
			parser->current_token->position->line,
			parser->current_token->position->column,
			token_token_type_as_cstr(type)
		);
}

Node *parser_get_next_node(Parser *parser)
{
	if (parser->current_token->type == TT_EOF)
		return node_new_node(NT_EOF);

	else
		return parser_expr(parser);
}

Node *parser_expr(Parser *parser)
{
	Node *left = parser_term(parser);

	if (
		parser->current_token->type == TT_PLUS
		|| parser->current_token->type == TT_MINUS)
	
	{	
		/* op */
		Token_Type op = parser->current_token->type;
		parser_match(parser, op);

		Node *right = parser_expr(parser);
		
		Node *binary_op = node_new_node(NT_BINARY_OP);
		binary_op->op = op;
		binary_op->right = right;
		binary_op->left = left;
		return binary_op;
	}

	return left;
}

Node *parser_term(Parser *parser)
{
	Node *left = parser_factor(parser);

	if (
		parser->current_token->type == TT_ASTERISK
		|| parser->current_token->type == TT_SLASH)
	
	{
		/* op */
		Token_Type op = parser->current_token->type;
		parser_match(parser, op);

		Node *right = parser_term(parser);
		Node *binary_op = node_new_node(NT_BINARY_OP);
		binary_op->op = op;
		binary_op->right = right;
		binary_op->left = left;
		return binary_op;
	}

	return left;
}

Node *parser_factor(Parser *parser)
{
	if (parser->current_token->type == TT_INT)
	{
		Node *node = node_new_node(NT_INT);
		node->int_value = atoi(parser->current_token->value);
		parser_match(parser, TT_INT);
		return node;
	}

	else if (parser->current_token->type == TT_LPAREN)
	{
		parser_match(parser, TT_LPAREN);
		Node *node = parser_expr(parser);
		parser_match(parser, TT_RPAREN);
		return node;
	}

	else
		SYNTAX_ERROR(
			parser->current_token->position->file_name,
			parser->current_token->position->line,
			parser->current_token->position->column,
			token_token_type_as_cstr(parser->current_token->type)
		);
}

