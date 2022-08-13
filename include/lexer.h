#ifndef _LEXER_H
#define _LEXER_H 1

#include <string.h>
#include "position.h"
#include "utils.h"
#include "token.h"
#include "error.h"

typedef struct
{
	char *file_name;
	char *source;
	size_t position;
	int line;
	int column;
	char current_char;
} Lexer;

Lexer *lexer_new_lexer(char *file_name, char *source);
Token *lexer_get_next_token(Lexer *lexer);
void lexer_advance(Lexer *lexer);
void lexer_update_position(Lexer *lexer);
void lexer_skip_whitespace(Lexer *lexer);
void lexer_skip_comment(Lexer *lexer);
char *lexer_get_int_token(Lexer *lexer);
char *lexer_get_id_token(Lexer *lexer);

#endif

