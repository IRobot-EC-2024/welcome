#include <stdio.h>
int main()
{	
	int a[100],number,i,t,j;
	printf("请输入需要排序的数字个数（100以内）\n");
	scanf("%d",&number);
	printf("请输入需要排序的数字\n");
	for(i=0;i<number;i++)
	{	scanf("%d",&a[i]);
	}
	for(j=0;j<number;j++)
	{	for(i=0;i<number-1;i++)
		{	if(a[i]>a[i+1])
		    {	t=a[i];
		    	a[i]=a[i+1];
		    	a[i+1]=t;	
			}
		}
	}
	printf("排序结果为：\n");
	for(i=0;i<number;i++)
	{printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}