#include "include/utils.h"


char *utils_string_copy(char *src)
{
	char *result = (char*)calloc(strlen(src) + 1, sizeof(char));	
	strcpy(result, src);

	return result;
}

char *utils_read_file(char *file_name)
{
	FILE *fp = fopen(file_name, "r");

	if (fp == NULL)
		return NULL;
	
	/* get the file size */
	fseek(fp, 0L, SEEK_END);
	size_t file_size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	char *data = (char*)calloc(file_size, sizeof(char));

	char current_ch;
	size_t position = 0;

	while ((current_ch = getc(fp)) != EOF)
		data[position++] = current_ch;

	return data;
}

