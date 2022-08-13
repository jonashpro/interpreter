#ifndef _TOKEN_H
#define _TOKEN_H 1

#include <assert.h>
#include "utils.h"
#include "position.h"

typedef enum
{
	TT_EOF,
	TT_INT,
	TT_ID,
	TT_PLUS,
	TT_MINUS,
	TT_ASTERISK,
	TT_SLASH,
	TT_LPAREN,
	TT_RPAREN,
} Token_Type;

typedef struct
{
	Token_Type type;
	char *value;
	Position *position;
} Token;

Token *token_new_token(Token_Type type, char *value, Position *position);
char *token_token_type_as_cstr(Token_Type type);

#endif

