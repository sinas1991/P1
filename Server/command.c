
#include <command.h>
#include <timer.h>

#include <string.h>

int execute_command(char*line, char*result)
{
	char command[20];
	char arg1[20], arg2[20];
	get_word_from_line(line, command, 0);
	get_word_from_line(line, arg1, 1);
	get_word_from_line(line, arg2, 2);

	if (strcmp(command, "Introduction") == 0 && strcmp(arg1, "Customer") == 0)
	{
		return create_customer(line, result);
	}

	if (strcmp(command, "Get") == 0 && strcmp(arg1, "Status") == 0)
	{
		return get_status(arg2, result);
	}

	if (strcmp(command, "Buy") == 0)
	{
		return buy_stock(line, result);
	}

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

int create_customer(char* input, char* result)
{
	char customer_name[30];
	char main_budget_str[20];
	get_word_from_line(input, customer_name, 0);
	get_word_from_line(input, main_budget_str, 1);
	int main_budget = atoi(main_budget_str);
}

int buy_stock(char *line, char *result)
{
}


int get_status(char *customer_name, char *result)
{
}
