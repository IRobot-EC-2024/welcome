#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//ÓÃµÄvs2022Ð´µÄ
int main()
{
	int k,fre=0;
	int num[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &num[i]);
	for (int q = 0; q < 10-fre; q++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (num[j] >num[j + 1])
			{
				k = num[j];
				num[j] = num[j + 1];
				num[j + 1] = k;
			}

		}
		fre++;
	}
	for (int h = 0; h < 10; h++)
	{
		printf("%d ", num[h]);
	}
	return 0;
}
