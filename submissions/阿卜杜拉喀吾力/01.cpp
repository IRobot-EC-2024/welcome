#include <stdio.h>

int main() {
    int n;
    
    // ��ȡ�û��������������
    printf("������Ҫ��������ָ���: ");
    scanf("%d", &n);
    
    // ��������洢�û����������
    int arr[n];
    
    // ��ȡ�û����������
    printf("������ %d ������:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // ð������ʹ�ӡ����
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // ���� arr[j] �� arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // ��ӡ�����Ľ��
    printf("������������:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
