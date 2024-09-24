#include <stdio.h>  
#include <stdlib.h>   
#include <string.h>  
  
#define MAX_NUMBERS 100  
#define MAX_LINE_LENGTH 1024 

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
  
  
int main() {  
    char line[MAX_LINE_LENGTH];  
    int numbers[MAX_NUMBERS];  
    int numCount = 0;   
    int numRead;  
  
    printf("请输入数字（用空格分隔，换行结束）：\n");  
    if (fgets(line, sizeof(line), stdin) != NULL) {    
        size_t len = strlen(line);  
        if (len > 0 && line[len-1] == '\n') {  
            line[len-1] = '\0';  
        }  
    
        char *p = line; 
        while ((numRead = sscanf(p, "%d%n", &numbers[numCount], &len)) == 1) {  
            p += len;
            if (*p == ' ' || *p == '\0') { // 如果当前字符是空格或字符串结束符，则继续  
                numCount++;  
                if (*p == '\0') break; // 如果是字符串结束符，则退出循环  
                p++; // 跳过空格  
            } else {  
                printf("输入格式错误，请输入用空格分隔的数字。\n");  
                return 1;  
            }  
        }  
  
    bubbleSort(numbers,numCount);
    int i; 
    for (i = 0; i < numCount; i++) {  
            printf("%d ", numbers[i]);  
        }  
        printf("\n");  
    } else {  
        printf("读取输入时发生错误。\n");  
    }  
  
    return 0;  
}
