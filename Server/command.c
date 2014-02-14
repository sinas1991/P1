
#include <command.h>
#include <timer.h>

#include <string.h>

int execute_command(char*line, char*result)
{
	if (strcmp(line, "Get Stocks List") == 0)
	{
		return get_stocks_list(result);
	}
}

int get_stocks_list(char *result)
{
	strcpy(result, "------------Stocks List-------------\n");
	strcat(result, "Time : ");
	char time[20], date[20];
	get_time(time);
	get_date(date);
	strcat(result, date);
	strcat(result, ", ");
	strcat(result, time);
	strcat(result, "\n");
	strcat(result, "Company---Stocks Num- Price\n");
}
