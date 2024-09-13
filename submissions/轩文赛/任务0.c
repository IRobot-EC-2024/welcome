#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main()
{
    int* a;
    int number, i, t, j;
    printf("请输入需要排序的数字个数：\n");
    scanf("%d", &number);

    a = (int*)malloc(number * sizeof(int));
    printf("请输入需要排序的数字：\n");
    for (i = 0; i < number; i++)
    {
        scanf("%d", &a[i]);
    }

    for (j = 0; j < number; j++)
    {
        for (i = 0; i < number - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
        }
    }

    printf("排序结果为：\n");
    for (i = 0; i < number; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}
