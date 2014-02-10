
#include "str_utils.h"

int strlen(char* str)
{
	int len;
	for (len = 0; str[len] != 0; len++);
	return len;
}

int end_of_string(char c)
{
	if (c == 0 || c == ' ' || c == '\n' || c == ' ' || c == '\t')
		return 1;
	return 0;
}

int end_of_line(char c)
{
	if (c == 0 || c == '\n')
		return 1;
	return 0;
}

/*
int main()
{
	char m[] = "mehrdad";
	char n[] = "12345678";
}
*/