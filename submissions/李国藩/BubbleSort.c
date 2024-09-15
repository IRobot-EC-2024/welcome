#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // 交换两个数字
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[8];
    printf("Please input 8 numbers:\n");
    // 接受用户输入的8个数字
    for (int i = 0; i < 8; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 调用冒泡排序函数
    bubbleSort(arr, 8);
    
    // 输出排序后的数字
    printf("After sorting: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
