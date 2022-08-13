#ifndef _PARSER_H
#define _PARSER_H 1

#include "node.h"
#include "token.h"
#include "lexer.h"
#include "utils.h"
#include "error.h"

typedef struct
{
	Lexer *lexer;
	Token *current_token;
} Parser;

Parser *parser_new_parser(Lexer *lexer);
void parser_match(Parser *parser, Token_Type type);
Node *parser_get_next_node(Parser *parser);
Node *parser_expr(Parser *parser);
Node *parser_term(Parser *parser);
Node *parser_factor(Parser *parser);

#endif

