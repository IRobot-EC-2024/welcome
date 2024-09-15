#include<stdio.h>

int main()
{
int numbers[8];
int i,j,x;
printf("Please input 8 numbers:");
for(i=0;i<8;i++)
{
    scanf("%d",&numbers[i]);
}

for(i=0;i<8;i++)
{
    for(j=0;j<8-i;j++)
    {
        if(numbers[j]>numbers[j+1])
       {
        x = numbers[j];
        numbers[j] = numbers[j+1];
        numbers[j+1] = x;
        x=0;
       }
    }
}
printf("Afer sorting:");
for(i=0;i<8;i++)
{
printf("%d ",numbers[i]);
}

    return 0;
}
