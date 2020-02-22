#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int i;
	int hour1, minute1, second1;
	int hour2, minute2, second2;
	char time1[8];
	char time2[8];
	int timeValid, rangeValid;
	int timeElapsed;
	int distance;
	int velocity;
	
	do
	{
		rangeValid = 1;
		
		do
		{
			printf("Input inisial waktu (hh:mm:ss): ");
			scanf("%s", time1);
			while (getchar() != '\n');
		
			timeValid = 1;
			hour1 = 0;
			minute1 = 0;
			second1 = 0;
			
			if (strlen(time1) != 8 || (time1[2] != ':' || time1[5] != ':'))
			{
				printf("Format waktu tidak valid\n");
				timeValid = 0;
			}
			
			if (isdigit(time1[0]) && isdigit(time1[1]))
			{
				hour1 += (time1[0] - '0') * 10;
				hour1 += (time1[1] - '0');
				
				if (hour1 < 0 || hour1 > 23)
				{
					printf("Jam harus sesuai range 0..23\n");
					timeValid = 0;
				}
			}
			else
				timeValid = 0;
			
			if (isdigit(time1[3]) && isdigit(time1[4]))
			{
				minute1 += (time1[3] - '0') * 10;
				minute1 += (time1[4] - '0');
				
				if (minute1 < 0 || minute1 > 59)
				{
					printf("Menit harus sesuai range 0..59\n");
					timeValid = 0;
				}
			}
			else
				timeValid = 0;
			
			if (isdigit(time1[6]) && isdigit(time1[7]))
			{
				second1 += (time1[6] - '0') * 10;
				second1 += (time1[7] - '0');
				
				if (second1 < 0 || second1 > 59)
				{
					printf("Detik harus sesuai range 0..59\n");
					timeValid = 0;
				}
			}
			else
				timeValid = 0;
		}
		while (timeValid == 0);
		
		do
		{
			printf("Input akhir waktu (hh:mm:ss): ");
			scanf("%s", time2);
			while (getchar() != '\n');
		
			timeValid = 1;
			hour2 = 0;
			minute2 = 0;
			second2 = 0;
			
			if (strlen(time2) != 8 || (time2[2] != ':' || time2[5] != ':'))
			{
				printf("Format waktu tidak valid\n");
				timeValid = 0;
			}
			
			if (isdigit(time2[0]) && isdigit(time2[1]))
			{
				hour2 += (time2[0] - '0') * 10;
				hour2 += (time2[1] - '0');
				
				if (hour2 < 0 || hour2 > 23)
				{
					printf("Jam harus sesuai range 0..23\n");
					timeValid = 0;
				}
			}
			else
				timeValid = 0;
			
			if (isdigit(time2[3]) && isdigit(time2[4]))
			{
				minute2 += (time2[3] - '0') * 10;
				minute2 += (time2[4] - '0');
				
				if (minute2 < 0 || minute2 > 59)
				{
					printf("Menit harus sesuai range 0..59\n");
					timeValid = 0;
				}
			}
			else
				timeValid = 0;
			
			if (isdigit(time2[6]) && isdigit(time2[7]))
			{
				second2 += (time2[6] - '0') * 10;
				second2 += (time2[7] - '0');
				
				if (second2 < 0 || second2 > 59)
				{
					printf("Detik harus sesuai range 0..59\n");
					timeValid = 0;
				}
			}
			else
				timeValid = 0;
		}
		while (timeValid == 0);
		
		timeElapsed = ((hour2 - hour1) * 60 * 60) + ((minute2 - minute1) * 60) + (second2 - second1);
		if (timeElapsed < 0)
		{
			printf("Range waktu tidak valid\n\n");
			rangeValid = 0;
		}
	}
	while (rangeValid == 0);
	
	velocity = 6;
	distance = 0;
	for (i = 1; i <= timeElapsed; i++)
	{
		if (i == 11)
			velocity++;
		else if (i > 11 && i % 10 == 1)
			velocity++;
			
		distance += velocity;
	}
	
	printf("Jarak Tempuh: %dm", distance);
	
	getchar();
	return 0;
}
