
#include "str_utils.h"

#include <stdio.h>

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

int get_word_from_line(char*line, char*string, int word_number)
{
	int start = 0, word = 0;
	while (word < word_number)
	{
		if (end_of_string(line[start]))
			word++;
		start++;
	}
	for (int i = start; i <= strlen(line); i++)
	{
		string[i-start] = line[i];
		if (end_of_string(string[i-start]))
		{
			string[i-start] = 0;
			break;
		}
	}
	return 0;
}

void reverse_string(char* string)
{
	int length = strlen(string);
	for (int i = 0; i < length/2; i++)
	{
		char t = string[i];
		string[i] = string[length-i-1];
		string[length-i-1] = t;
	}
}

/*
int main()
{
	char m[] = "mehrdad";
	char n[] = "12345678";
}
*/