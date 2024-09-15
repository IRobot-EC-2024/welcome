#include <stdio.h>
int main()
{
    //冒泡排序
    int arr[6] = { 5,2,4,6,1,3 };
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6 - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t;
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
    //输出结果
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
