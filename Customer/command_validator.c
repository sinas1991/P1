
#include <command_validator.h>

int validate_command(char*line)
{
	if (strcmp(line, "Get Stocks List") == 0)
		return 1;
	return 1;
}
