
#include <time.h>

#include <timer.h>
#include <../Utils/str_utils.h>

#include <stdio.h>

int get_date(char* result)
{
	int second = time(NULL);
	strcpy(result, "10/10/1388");
	return 0;
}

int get_time(char* result)
{
	int second = time(NULL);
	second += 3.5 * 60 * 60; // time-zone +3.5
	int hour = second / 3600;
	int day = hour / 24;
	int day_second = second - day * 24 * 3600;
	hour = day_second / 3600;
	int min = (day_second / 60) % 60;
	second = day_second % 60;

	char str_hour[10], str_second[10], str_min[10];
	to_string(str_hour, hour);
	to_string(str_min, min);
	to_string(str_second, second);
	strcpy(result, str_hour);
	strcat(result, ":");
	strcat(result, str_min);
	strcat(result, ":");
	strcat(result, str_second);
	return 0;
}

