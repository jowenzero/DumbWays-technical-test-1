#include <stdio.h>

void diamondPrint(int amountOfStars);

int main()
{
	int amountOfStars;
	
	do
	{
		printf("Jumlah Bintang: ");
		scanf("%d", &amountOfStars);
		while (getchar() != '\n');
	}
	while (amountOfStars < 0);
	
	diamondPrint(amountOfStars);
	
	getchar();
	return 0;
}

void diamondPrint(int amountOfStars)
{
	int row, column;
	int leftPointer, rightPointer;
	int isReverse;
	
	isReverse = 0;
	for (column = 1; column <= amountOfStars; column++)
	{
		for (row = 1; row <= amountOfStars; row++)
		{
			if (amountOfStars % 2 == 1)
			{
				if ((column == 1 || column == amountOfStars) && (row == (amountOfStars / 2) + 1))
				{
					printf("*");
					leftPointer = (amountOfStars / 2) + 1;
					rightPointer = leftPointer;
				}
				else if (row == leftPointer || row == rightPointer)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
			else 
			{
				if ((column == 1 || column == amountOfStars) && row == (amountOfStars / 2))
				{
					printf("*");
					leftPointer = (amountOfStars / 2);
					rightPointer = leftPointer + 1;
				}
				else if ((column == 1 || column == amountOfStars) && row == (amountOfStars / 2) + 1)
				{
					printf("*");
				}
				else if (row == leftPointer || row == rightPointer)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
		}
		//printf ("    left: %d  right: %d", leftPointer, rightPointer);
		puts("");
		
		if ((leftPointer == 1 || rightPointer == amountOfStars) && amountOfStars % 2 == 0 && isReverse == 0)
		{
			isReverse = 1;
			continue;
		}
		else if ((leftPointer == 1 || rightPointer == amountOfStars) || isReverse == 1)
		{
			leftPointer++;
			rightPointer--;
			isReverse = 1;
		}
		else if (isReverse == 0)
		{
			leftPointer--;
			rightPointer++;
		}
	}
}
