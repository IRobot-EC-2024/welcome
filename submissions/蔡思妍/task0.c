#include <stdio.h>
void main()
{
	int a[10], i, j, p;
	printf("Enter 10 integers:\n");
	for (i = 0; i < 10; i++)
		scanf_s("%d", &a[i]);
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
			if (a[j] > a[j + 1])
			{
				p = a[j + 1];
				a[j + 1] = a[j];
				a[j] = p;
			}
	}
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
}