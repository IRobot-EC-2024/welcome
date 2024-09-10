#include <stdio.h>

int main() 
{
    int i = 0 ,j = 0;
    int group[8];
    printf("Please input 8 numbers:\n");
    for (i = 0; i < 8; i++){
        scanf("%d", &group[i]);   //读数 
    }
    int k ;
    for (j = 0; j < 8; j++){
        for  (i = 0 ; i < 7-j ;i++)
		{
		  	if (group[i] >= group[i+1]){  //排序 
                k = group[i];
                group[i] = group[i+1];
                group[i+1] = k;
    		}	
	    }
    }
    printf("After sorting:\n");

    for (i = 0; i < 8; i++){
       printf("%d ", group[i]);
    }
    return 0;
}