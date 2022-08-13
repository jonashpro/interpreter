#ifndef _ERROR_H
#define _ERROR_H 1

#include <stdio.h>
#include <stdlib.h>

#define ERROR(file, line, column, fmt, ...) { \
	fprintf(stderr, "%s:%.2d:%.2d: error: ", file, line, column); \
	fprintf(stderr, fmt, ##__VA_ARGS__); \
	fprintf(stderr, "\n"); \
	exit(1); \
}

#define ILLEGAL_CHARACTER_ERROR(file, line, column, character) { \
	ERROR(file, line, column, "illegal character \"%c\"", character); \
}

#define EXPECTED_ERROR(file, line, column, expected) { \
	ERROR(file, line, column, "%s expected", expected); \
}

#define SYNTAX_ERROR(file, line, column, token) { \
	ERROR(file, line, column, "invalid syntax: %s", token); \
}

#endif

