
#include <time.h>

#include <timer.h>
#include <../Utils/str_utils.h>

#include <stdio.h>

int is_leap_year(int year)
{
	int r = year % 33;
	if (r==1 || r==5 || r==9 || r==13 || r==17 || r==22 || r==26 || r==30)
		return 1;
	return 0;
}

int get_date(char* result)
{
	int second = time(NULL);
	int days = second / 60 / 60 / 24;
	strcpy(result, "10/10/1388");
	return 0;
}

int get_time(char* result)
{
	int second = time(NULL);
	printf("%d\n", second);
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

