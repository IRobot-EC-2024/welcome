#include<stdio.h>

int main()
    int a;
    scanf("%d", &a); 
    int number[10];
    for(int i = 0; i < a; i++)
    {
        scanf("%d", &number[i]);
    }
    for(int i = 0; i < a; i++)
    {
        for(int j = i + 1; j < a; j++)
        {
            if(number[i] > number[j])
            {
                int temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }
    for(int i = 0; i < a; i++)
    {
        printf("%d ", number[i]);
    }
    printf("\n");
    return 0;
}
