
#include <command_validator.h>

#include <../Utils/str_utils.h>

int validate_command(char *line, char *customer_name)
{
	char command[20];
	char arg1[20];
	get_word_from_line(line, command, 0);
	get_word_from_line(line, arg1, 1);

	if (strcmp(command, "Introduction") == 0 && strcmp(arg1, "Customer") == 0)
		return 1;
	if (strcmp(line, "Get Stocks List") == 0)
		return 1;
	if (strcmp(line, "Get Status") == 0)
	{
		strcat(line, " Customer ");
		strcat(line, customer_name);
		return 1;
	}

	return 1;
}
