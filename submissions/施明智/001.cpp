#include <stdio.h>

void bubble(int arr[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
            }
        }
    }
}


int main() {
    int numbers[8];
    printf("请输入8个数字，我可以帮你排序""\n");

    for (int i = 0; i < 8; i++) {
        scanf_s("%d", &numbers[i]);
    }

    bubble(numbers, 8);

    printf("排序后的结果为:");
    for (int i = 0; i < 8; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}