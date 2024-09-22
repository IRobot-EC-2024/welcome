#include<stdio.h>
int main()
{
    int a[10],n,i,j=0,t=0;
    scanf("%d",&n);//输入排序数字个数
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);//排序数据输入
    }
    for(i=0;i<n-1;i++)//外层循环控制趟数
    {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])//内层循环控制每趟比较次数
                {
                        t=a[j];
                        a[j]=a[j+1];
                        a[j+1]=t;
                }
            }
    }
    for(i=0;i<n;i++)
    {
        printf("%d",&a[i]);//按序输出排序后的数据
    }
    return 0;
}