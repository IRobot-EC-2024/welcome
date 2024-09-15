#include <stdio.h>
int main()
{

	printf("Please input 8 numbers:");
	int a[8];
	int m = 0;
	for (m = 0; m < 8; m++)
	{
		scanf("%d", &a[m]);

	}
	for (m = 1; m <=8; m++)
	{
		int j = 0;
		for (j = 0; j < 8-m; j++)
		{
			int tempera = 0;
				if (a[j] > a[j + 1])
				{
					tempera = a[j + 1];
					a[j + 1] = a[j];
					a[j] = tempera;
				}
		}
	}
	printf("After sorting:");
	for (m = 0; m < 8; m++)
	{
		printf("%d ", a[m]);
	}
	return 0;
}