#include <stdio.h>

int main() {
    int n;
    
    // 获取用户输入的数字数量
    printf("请输入要排序的数字个数: ");
    scanf("%d", &n);
    
    // 创建数组存储用户输入的数字
    int arr[n];
    
    // 获取用户输入的数字
    printf("请输入 %d 个数字:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 冒泡排序和打印数组
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // 交换 arr[j] 和 arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // 打印排序后的结果
    printf("排序后的数字是:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
