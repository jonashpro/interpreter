#include "include/lexer.h"

Lexer *lexer_new_lexer(char *file_name, char *source)
{
	Lexer *lexer = new(Lexer);
	lexer->file_name = file_name;
	lexer->source = source;

	lexer->position = -1;
	lexer->line = 1;
	lexer->column = 1;

	lexer_advance(lexer);
	return lexer;
}

Token *lexer_get_next_token(Lexer *lexer)
{
	Token_Type type;
	char *value;

	lexer_skip_comment(lexer);
	lexer_skip_whitespace(lexer);

	if (lexer->current_char == '\0')
	{
		type = TT_EOF;
	}

	else if (IS_NUMBER(lexer->current_char))
	{
		type = TT_INT;
		value = lexer_get_int_token(lexer);
	}

	else if (IS_ALPHA(lexer->current_char))
	{
		type = TT_ID;
		value = lexer_get_id_token(lexer);
	}

	else if (lexer->current_char == '+')
	{
		type = TT_PLUS;
		lexer_advance(lexer);
	}

	else if (lexer->current_char == '-')
	{
		type = TT_MINUS;
		lexer_advance(lexer);
	}

	else if (lexer->current_char == '*')
	{
		type = TT_ASTERISK;
		lexer_advance(lexer);
	}

	else if (lexer->current_char == '/')
	{
		type = TT_SLASH;
		lexer_advance(lexer);
	}

	else if (lexer->current_char == '(')
	{
		type = TT_LPAREN;
		lexer_advance(lexer);
	}

	else if (lexer->current_char == ')')
	{
		type = TT_RPAREN;
		lexer_advance(lexer);
	}

	else
	{
		ILLEGAL_CHARACTER_ERROR(
			lexer->file_name,
			lexer->line, lexer->column,
			lexer->current_char
		);
	}

	return token_new_token(type, value, position_new_position(
		lexer->file_name,
		lexer->line,
		lexer->column
	));
}

void lexer_skip_comment(Lexer *lexer)
{
	while (lexer->current_char == '#')
	{
		while (lexer->current_char != '\n' && lexer->current_char != '\0')
			lexer_advance(lexer);

		lexer_advance(lexer);  /* # */
	}
}

void lexer_skip_whitespace(Lexer *lexer)
{
	while (lexer->current_char == ' '
	    || lexer->current_char == '\n'
	    || lexer->current_char == '\r'
	    || lexer->current_char == '\t')
	{
		lexer_advance(lexer);
	}
}

void lexer_advance(Lexer *lexer)
{
	lexer_update_position(lexer);

	if (lexer->position < strlen(lexer->source))
		lexer->current_char = lexer->source[lexer->position];
	
	else
		lexer->current_char = '\0';
}

void lexer_update_position(Lexer *lexer)
{
	lexer->position++;

	if (lexer->current_char != '\0')
	{
		if (lexer->current_char == '\n')	
		{
			lexer->line++;
			lexer->column = 1;
		}

		else
			lexer->column++;
	}
}

char *lexer_get_int_token(Lexer *lexer)
{
	char *token = (char*)calloc(1, sizeof(char));
	int position = 0;

	while (IS_NUMBER(lexer->current_char))
	{
		token[position++] = lexer->current_char;
		token = (char*)realloc(token, position + 1);
		lexer_advance(lexer);
	}

	return token;
}

char *lexer_get_id_token(Lexer *lexer)
{
	char *token = (char*)calloc(1, sizeof(char));
	int position = 0;

	while (IS_ALPHA(lexer->current_char) || IS_NUMBER(lexer->current_char))
	{
		token[position++] = lexer->current_char;
		token = (char*)realloc(token, position + 1);
		lexer_advance(lexer);
	}

	return token;
}

