#include <stdio.h>



int main()
{
	int arr[8] = { 0 };
	int i,j = 0;
	int mid = 0;
	for (i = 0; i < 8; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 7; i>0; i--)
	{
		for (j=7;j>7-i;j--)
		{
			if (arr[j] < arr[j - 1])
			{
				mid = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = mid;
			}
		}
	}
	for (i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	return 0;
}
