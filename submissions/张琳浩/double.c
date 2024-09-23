#include<stdio.h>
int main()
{
	int arr[8] = { 75,0,61,0,5,7,9,1 };
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		printf("%d\t", arr[i]);
	}
	return 0;
}
