#include <stdio.h>,
int main()
{
    int arr[10] = { 1,3,8,6,4,2,9,11,18,10 };
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}