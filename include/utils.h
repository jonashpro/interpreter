#ifndef _UTILS_H
#define _UTILS_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define new(STRUCT) (STRUCT*)malloc(sizeof(STRUCT))
#define DEBUG(message) printf("%s:%.2d: %s: DEBUG: %s\n",  \
	__FILE__, \
	__LINE__, \
	__func__, \
	message \
);

#define IS_NUMBER(ch) (((ch) >= '0') && ((ch) <= '9'))
#define IS_ALPHA(ch) ((((ch) >= 'a') && ((ch) <= 'z')) \
	|| (((ch) >= 'A') && ((ch) <= 'Z')))


char *utils_format_string(char *fmt, ...);
char *utils_string_copy(char *src);
char *utils_read_file(char *file_name);

#endif

