#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//��ȡ�������������
	char b[1000];
	printf("��������Ҫ��������������ݣ��������ַ���Ϊ��������س���������");
	gets(b);
	//��ʽת��
	int a[1000], m;
	m = get_ints(b, a);
	print(a, m);
	getchar();//��ֹ����ʱ���ٽ���
	return 0;
}
int get_ints(char s[], int a[])
{
	//��ȡ����
	int n = 0;
	int num = 0;
	int k = -1;
	for (int i = 0; s[i] != '\0'; i++)
	{
		char c = s[i];
		if ('0' <= c && c <= '9')
		{
			num = num * 10 + (c - '0');
			if (n == 0)
			{
				k++;
			}
			n = 1;
		}
		else
		{
			if (n == 1)
			{
				a[k] = num;
				num = 0;
			}
			n = 0;
		}
	}
	if (n == 1)
	{
		a[k] = num;
	}
	k++;
	//��������
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = 0; j < k - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	return k;
}
//������
int print(int a[], int p)
{
	for (int i = 0; i < p; i++)
		printf("%d\ ", a[i]);
}