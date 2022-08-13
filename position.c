#include "include/position.h"

Position *position_new_position(char *file_name, int line, int column)
{
	Position *position = new(Position);
	position->file_name = file_name;
	position->line = line;
	position->column = column;

	return position;
}

