#include "stdio.h"
#include "stdlib.h"
#include "algorithm"
using namespace std;

int main()
{
        int n;
        printf("please  input the number of the numbers\n");
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
                scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
        {
                for (int j = i; j < n; j++)
                {
                        if (a[i] > a[j])
                                swap(a[i], a[j]);
                }
        }
        for (int i = 0; i < n; i++)
                printf("%d ", a[i]);
        return 0;
}
