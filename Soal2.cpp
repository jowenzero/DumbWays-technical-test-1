#include <iostream>
using namespace std;

void sortArray(char data[][10], int size);
void printArray(char data[][10], int size);

int main()
{
	char data[][10] = {
		{'J','M','I','N','L','K'},
		{'H','G','F'}
	};
	char dataLain[][10] = {
		{'g','h','i','j'},
		{'a','c','b','e','d'},
		{'g','e','f'}
	};
	
	printf("Unsorted Array:\n");
	printf("Data:\n");
	printArray(data, sizeof(data)/sizeof(data[0]));
	printf("Data Lain:\n");
	printArray(dataLain, sizeof(dataLain)/sizeof(dataLain[0]));

	puts("\n");
	sortArray(data, sizeof(data)/sizeof(data[0]));
	sortArray(dataLain, sizeof(dataLain)/sizeof(dataLain[0]));
	
	printf("Sorted Array:\n");
	printf("Data:\n");
	printArray(data, sizeof(data)/sizeof(data[0]));
	printf("Data Lain:\n");
	printArray(dataLain, sizeof(dataLain)/sizeof(dataLain[0]));
	
	getchar();
	return 0;
}

void sortArray(char data[][10], int size)
{
	int dataCount[size] = {0};
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (data[i][j] == NULL)
				break;
			else
				dataCount[i]++;
		}
	}
	
	for (int i = 0; i < size; i++) {
		int smallest = i;

		for (int j = i + 1; j < size; j++)
			if (dataCount[j] < dataCount[smallest])
				smallest = j;

		int temp = dataCount[i];
		dataCount[i] = dataCount[smallest];
		dataCount[smallest] = temp;
		
		for (int j = 0; j < 10; j++)
		{
			if (data[i][j] == NULL && data[i][smallest] == NULL)
				break;
			else
			{
				char temp = data[i][j];
				data[i][j] = data[smallest][j];
				data[smallest][j] = temp;
			}
		}
	}	
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (data[i][j] == NULL)
				break;
			else
			{
				int smallest = j;

				for (int k = j + 1; k < 10; k++)
					if (data[i][k] < data[i][smallest])
						smallest = k;
						
				
				char temp = data[i][j];
				data[i][j] = data[i][smallest];
				data[i][smallest] = temp;
			}
		}
	}
}

void printArray(char data[][10], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%c ", data[i][j]);
		}
		puts("");
	}
}
