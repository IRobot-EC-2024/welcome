#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int get_ints(char s[], int a[]);
int sort(int a[], int n);
int print(int a[], int n);
int main()
{
	printf("��������Ҫ��������������ݣ��������ַ���Ϊ��������س���������");
	char b[100000];//����
	gets(b);
	int a[1000], n;
	n = get_ints(b, a);
	print(a, n);//�����ȡ������
	sort(a, n);
	print(a, n);//�������������
	return 0;
}
//��ȡ����
int get_ints(char s[], int a[])
{
	int k = -1;
	int num1 = 0;
	int num = 0;
	for (int i = 0;s[i] != '\0';i++)
	{
		char c = s[i];
		if ('0' <= c && c <= '9')
		{
			num = num * 10 + (c - '0');	
			if (num1 == 0)
			{
				k++;
			}
			num1 = 1;
		}
		else
		{
			if (num1 == 1)
			{
				a[k] = num;
				num = 0;
			}
			num1 = 0;
		}
	}
	if (num1 == 1)
	{
		a[k] = num;	
	}
	k++;
	return k;
}
//ð������
int sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	return 0;
}
//������
int print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return n;
}
