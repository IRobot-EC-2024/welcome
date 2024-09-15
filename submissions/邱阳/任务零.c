#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//获取所需排序的内容
	char b[1000];
	printf("请输入需要将数字排序的内容（可任意字符作为间隔，按回车结束）：");
	gets(b);
	//格式转换
	int a[1000], m;
	m = get_ints(b, a);
	print(a, m);
	getchar();//防止运行时快速结束
	return 0;
}
int get_ints(char s[], int a[])
{
	//提取数字
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
	//进行排序
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
//输出结果
int print(int a[], int p)
{
	for (int i = 0; i < p; i++)
		printf("%d\ ", a[i]);
}