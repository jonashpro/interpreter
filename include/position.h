#ifndef _POSITION_H
#define _POSITION_H 1

#include "utils.h"

typedef struct
{
	char *file_name;
	int line;
	int column;
} Position;

Position *position_new_position(char *file_name, int line, int column);

#endif

