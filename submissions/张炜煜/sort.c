#include <stdio.h>

int main()
{
	int arr[1024]={0};
    int num,i=0,j=0,count=0,temp=0;
    do{
        scanf("%d",&num);
        arr[i++]=num;
		count++;
    }while( getchar()!='\n');

	 for(i=0;i<count-1;i++){     
       for (j=0;j<count-i-1;j++){ 
           if (arr[j]>arr[j+1]){ 
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
           }
       }
   }
	for(i=0;i<count;i++){
		printf("%d ",arr[i]);
	}
 	return 0;	
}