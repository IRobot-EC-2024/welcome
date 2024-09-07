#include <stdio.h>
int main()
{
    int n;
    printf("please ensure your number:");
    scanf("%d",&n);
    int x[n],i,j,t;
    printf("please input your numbers:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            if(x[j]>x[j+1]){
                t=x[j+1];
                x[j+1]=x[j];
                x[j]=t;
            }
        }
    }
    printf("After sorting:");
    for(i=0;i<n;i++){
        printf("%d ",x[i]);
    }
    return 0;
}