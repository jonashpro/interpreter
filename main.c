#include <stdio.h>
#include <stdlib.h>
#include "include/error.h"
#include "include/utils.h"
#include "include/lexer.h"
#include "include/token.h"
#include "include/parser.h"
#include "include/interpreter.h"

void compile_from_file(char *file_name)
{
	char *source = utils_read_file(file_name);

	if (source == NULL)
	{
		fprintf(stderr, "no such file %s\n", file_name);
		exit(1);
	}

	Lexer *lexer = lexer_new_lexer(file_name, source);
	Parser *parser = parser_new_parser(lexer);

	interpreter_run(parser);

	free(parser);
	free(lexer);
	free(source);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "usage: %s <file>\n", argv[0]);
		return 1;
	}

	compile_from_file(argv[1]);

	return 0;
}

