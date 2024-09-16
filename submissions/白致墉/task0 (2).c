#include <stdio.h>
#include <windows.h> // 为什么会乱码呢？

void sorting(int box[], int num) {
    int swap;
    
    for (int i = 0; i < num - 1; i++) {
        swap = 0; // 重置
        
        for (int j = 0; j < num - i - 1; j++) {
            if (box[j] > box[j + 1]) {
               int temp = box[j];
                
                box[j] = box[j + 1];
                
                box[j + 1] = temp;
                
                swap = 1; // 有交换发生
            }
        }
        
        if (swap == 0) {break;}
    }
}

int main() {
    int box[100]; // 好像超了100会越界
    int num = 0; 
    int input; 
    
    SetConsoleOutputCP(65001); // 反正我中文乱码了

    printf("请输入最多 %d 个数字(输入114514就能结束了哦):\n", 100);
    
    while (num < 100) {
        printf("请输入第 %d 个数字: ", num + 1);
        
        scanf("%d", &input);
        
        if (input == 114514) {break;}
        
        box[num] = input; 
        
        num++; 
    }
    
    sorting(box, num);

    printf("排序后:\n");
    
    for (int i = 0; i < num; i++) {
        printf("%d ", box[i]);
    }
    
    return 0;
}
