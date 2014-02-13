
#include <unistd.h>

#include "io_utils.h"

#include <stdio.h>

int read_int()
{
	return fread_int(STD_STREAM);
}

int fread_int(int fd)
{
	char str[100];
	fread_str(fd, str);
	return atoi(str);
}

int read_str(char *str)
{
	return fread_str(STD_STREAM, str);
}

int fread_str(int fd, char* str)
{
	for (int i = 0; i < 100; i++)
	{
		read(fd, &str[i], 1);
		if (end_of_string(str[i]))
		{
			str[i] = 0;
			break;
		}
	}
	return 0;
}

int read_line(char* str)
{
	return fread_line(STD_STREAM, str);
}

int fread_line(int fd, char* str)
{
	for (int i = 0; i < 100; i++)
	{
		read(fd, &str[i], 1);
		if (end_of_line(str[i]))
		{
			str[i] = 0;
			break;
		}
	}
	return 0;
}

float read_float()
{
	fread_float(STD_STREAM);
}

float fread_float(int fd)
{
	char str[100];
	fread_str(fd, str);
	float result = 0.f;
	int start = 0;
	int end = strlen(str);
	int sign = 1;
	if (str[0] == '-')
	{
		start = 1;
		sign = -1;
	}

	for (int i = start; i < strlen(str); i++)
	{
		if (str[i] == '.')
		{
			end = i;
			break;
		}
	}
	float pow = 1;
	float pow_mult = 10;
	for (int j = end-1; j >= start; j--)
	{
		result += pow * (str[j] - '0');
		pow *= pow_mult;
	}
	pow = 0.1;
	pow_mult = 0.1;
	for (int j = end+1; j < strlen(str); j++)
	{
		result += pow * (float)(str[j] - '0');
		pow *= pow_mult;
	}

	return sign * result;
}

/*
int main()
{
	while(1)
	{
//		int t = read_int();
//		printf("read:%d\n", t);
		float f = read_float();
		printf("read:%f\n", f);
	}
}
*/