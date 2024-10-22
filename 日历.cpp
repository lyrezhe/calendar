//编写日历
#include<stdio.h>
int main()
{
	int year, month;
	scanf("%d%d", &year, &month);
	printf("%d年%d月\n", year,month );
	printf("一 二 三 四 五 六 日 \n");
	int days=28;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		days = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		days = 30;
	if ((month == 2 && year % 4 == 0 && year % 100 != 0)||(month==2&&year%400==0))
		days = 29;
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
	int i = 1,j=1,k=0;
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
	return 0;
}