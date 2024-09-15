#include <stdio.h>
#include <stdlib.h>

int main()
{
    //冒泡排序 
    int n ;
    printf("请输入想要排序的数字个数:\n");
    scanf("%d", &n);
    int a[n]; 
    int i, j, k;
    printf("请输入%d个数字:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    

    for (i = 0; i < n; i++){ 
        for (j = 0; j < n - 1 - i; j++){
            if (a[j] > a[j + 1]){
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }

    printf("排序后的结果:\n");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
    //结束
}