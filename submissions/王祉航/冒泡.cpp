#include "stdio.h"

int main ()
{
	//定义数组，并且进行数组长度的计算 
	int arr[]={3,5,2,1,4,66,55,234,34,23,2003,12,12,5201314};
	int len=sizeof(arr)/sizeof(int);
	//利用冒泡排序，把数字之中的数据进行按照升序排列
	//可以用for循环的嵌套
	 
	 for(int i=0;i<len-1;i++)
	 {
	 
	for(int j=0;j<len-1-i;j++)
	{
		//i与i+1的相互进行比较,相邻的元素两两进行比较，小的在前面，大的在后面 
		if(arr[j]>arr[j+1])
		{
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		} 
	}
}
	
	 
	for(int i=0;i<len;i++)
	{
		printf ("%d\n",arr[i]);
	}
}
