#include <stdio.h>
int main()
{
	int a[8] = {0}; int i, j;
	for(i=0;i<8;i++)
	{
		scanf("%d ",&a[i]);
	}
	for (i = 0; i < 7; i++)
	{
		for (j = i + 1; j <=7; j++)
		{
			if (a[i] <a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}

		}
	}
	for (i = 0; i <8; i++)
	{
		printf("%d", a[i]);
	}
	return 0;
}
