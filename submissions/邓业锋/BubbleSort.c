#include <stdio.h>

//函数声明 
void bubbleSort(int array[], int size);
void printArray(int array[], int size);

int main(void)
{
    int n = 0;

    // 获取用户输入的数组大小
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // 分配数组内存
    int array[n];

    // 获取用户输入的数组元素
    printf("Enter %d numbers: ", n);
    for(int i = 0; i < n; i ++)
	{
       scanf("%d", &array[i]);
    }

    // 调用排序函数
    bubbleSort(array, n);

    // 打印排序后的数组
    printf("Result: ");
    printArray(array, n);

    return 0;
}

// 冒泡排序
void bubbleSort(int array[], int size)
{
    for(int i = 0; i < size-1; i ++)
	{
        for(int j = 0; j < size-i-1; j ++)
		{
            if(array[j] > array[j+1])
			{
                // 交换两个元素的位置
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// 打印数组
void printArray(int array[], int size)
{
    for(int i = 0; i < size; i ++)
	{
        printf("%d ", array[i]);
    }
    printf("\n");
}
