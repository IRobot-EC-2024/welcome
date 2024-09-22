#include <stdio.h>

		
int main()
{
   
	int n,i;
	printf("请输入整数个数：\n");
	scanf("%d/n",&n);
	int arr[n]; 
	printf("请输入%d个整数:\n",n);
	for(i = 0;i < n;i++)
	{	scanf("%d",&arr[i]);
		}	
	 
	
	for(int i = 0; i< n - 1; i++)
			{for(int j = 0;j < n - i -1; j++)
				{
				if (arr[j] > arr[j + 1])
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1]= temp;
				}
			}
	
    
	for (i = 0;i < n; i++ )	
	{	printf("%d ",arr[i]);
	}   
   return 0;
}
