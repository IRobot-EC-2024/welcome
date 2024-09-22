#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("����������Ĵ�С: ");
    scanf("%d", &n);
    int arr[n];
    printf("�����������е�Ԫ��: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("����ǰ������: \n");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("����������: \n");
    printArray(arr, n);
    
    return 0;
}
