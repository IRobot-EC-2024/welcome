#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // 冒泡排序算法
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // 交换相邻元素
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    // 输入数组大小
    printf("请输入数字的个数: ");
    scanf("%d", &n);

    int arr[n];
    // 输入数组元素
    printf("请输入 %d 个整数:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 调用冒泡排序函数
    bubbleSort(arr, n);

    // 输出排序后的数组
    printf("排序后的数组是: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
