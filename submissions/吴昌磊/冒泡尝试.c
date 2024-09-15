/*
	名称：冒泡排序
	作者：CMeSummer
	时间：2024/9/11
	作用：对输入的八个整数进行从小到大排序
*/
#include<stdio.h>

int main(void)
{
	int sz[8];//声明一个八元数组
	
	printf("Please input 8 numbers:\n");
	
	for(int i=1;i<9;i++)
	{
		scanf("%d",&sz[i]);//循环控制输入八个数字
	}
	
	
	for(int i=0;i<8;i++)//八个数字要循环七次，最小的不用再排序
	{
		for(int i=1;i<8;i++)//从第一个开始，依次比对此项和下一项的数值，然后根据大小判断是否交换位置
		{
			if(sz[i]>sz[i+1])
			{
				int z=sz[i];
				sz[i]=sz[i+1];
				sz[i+1]=z;//控制位置的交换
			}
		}
	}
	
	
	for(int i=1;i<9;i++)
	{	
		printf("%d,",sz[i]);//输出排序结果并用逗号隔开
	}
	
	
	return 0;
}
