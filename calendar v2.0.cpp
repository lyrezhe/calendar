//编写日历
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int get_days_in_month(int year, int month);
int get_first_day(int year, int month);
void print_calendar(int week, int days);
void clearScreen();
int main()
{
	int year, month;
	scanf("%d%d", &year, &month);
	while (1)
	{
		clearScreen();
		printf("%d年%d月\n", year, month);
		printf("一 二 三 四 五 六 日 \n");
		int days = get_days_in_month(year, month);
		int week = get_first_day(year, month);
		print_calendar(week, days);
		printf("\n按 ↑ 增加月份，按 ↓ 减少月份，按 q 退出。\n");
		int key = _getch();
		if (key == 224) 
		{         
			int arrowKey = _getch();
			if (arrowKey == 72) 
			{
				month++;
				if (month > 12) 
				{
					month = 1;
					year++;
				}
			}
			else if (arrowKey == 80) 
			{
				month--;
				if (month < 1) 
				{
					month = 12;
					year--;
				}
			}
		}
		else if (key == 'q' || key == 'Q')
		{
			break;
		}
	}
	return 0;
}
int get_days_in_month(int year, int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if ((month == 2 && year % 4 == 0 && year % 100 != 0) || (month == 2 && year % 400 == 0))
		return 29;
	else
		return 28;
}
int get_first_day(int year,int month)
{
	if (month == 1)
		month = 13, year -= 1;
	if (month == 2)
		month = 14, year -= 1;
	int c = year / 100;//c>15;
	int y = year % 100;
	int week = ((c / 4) - 2 * c + y + (y / 4) + (26 * (month + 1) / 10)) % 7;
	if (week < 0)
		week += 7;
	if (week == 0)
		week = 7;
	return week;
}
void print_calendar(int week,int days)
{
	int i = 1, j = 1, k = 0;
	while (i < week)
	{
		printf("   ");
		i++;
		k += 3;
	}
	for (j = 1; j <= days; j++)
	{
		printf("%-3d", j);
		k += 3;
		if (k == 21)
		{
			printf("\n");
			k = 0;
		}
	}
}
void clearScreen() 
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}