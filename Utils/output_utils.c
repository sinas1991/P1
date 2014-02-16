
#include <output_utils.h>
#include <str_utils.h>

#include <unistd.h>

#include <stdio.h>

int write_int(int _int)
{
	return fwrite_int(STDOUT_STREAM, _int);
}

int write_str(char* str)
{
	return fwrite_str(STDOUT_STREAM, str);
}

int write_line(char* str)
{
	return fwrite_line(STDOUT_STREAM, str);
}

int write_float(float _float)
{
	return fwrite_float(STDOUT_STREAM, _float);
}

int fwrite_int(int fd, int n)
{
	char buffer[100];
	int i = 0;
	while(n > 0)
	{
		buffer[i] = '0' + n%10;
		n /= 10;
		i++;
	}
	buffer[i] = 0;
	reverse_string(buffer);
	write(fd, buffer, strlen(buffer));
	return 0;
}

int fwrite_str(int fd, char* str)
{
	write(fd, str, strlen(str));
}

int fwrite_line(int fd, char* line)
{
	write(fd, line, strlen(line));
	char eol[] = "\n";
	write(fd, eol, 1);
}

int fwrite_float(int fd, float f)
{
	return 0;
}
