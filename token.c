#include "include/token.h"

Token *token_new_token(Token_Type type, char *value, Position *position)
{
	Token *token = new(Token);
	token->type = type;
	token->value = value;
	token->position = position;

	return token;
}

char *token_token_type_as_cstr(Token_Type type)
{
	switch (type)
	{
		case TT_EOF:      return "eof";
		case TT_INT:      return "int";
		case TT_ID:       return "identifier";
		case TT_PLUS:     return "+";
		case TT_MINUS:    return "-";
		case TT_ASTERISK: return "*";
		case TT_SLASH:    return "/";
		case TT_LPAREN:   return "(";
		case TT_RPAREN:   return ")";

		default:
			assert(0 && "unreachable statement");
	}

	return "";
}

