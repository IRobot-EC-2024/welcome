#include "bits/stdc++.h"
using namespace std;

int bubble(int b)
{
        int a[b];
        for (int i = 0; i < b; i++)
                scanf("%d", &a[i]);
        for (int i = 0; i < b; i++)
        {
                for (int j = i; j < b; j++)
                {
                        if (a[i] > a[j])
                                swap(a[i], a[j]);
                }
        }
        for (int i = 0; i < b; i++)
                printf("%d ", a[i]);
        return 0;
}
int main()
{
        int n;
        printf("please  input the number of the numbers\n");
        scanf("%d", &n);
        bubble(n);
        return 0;
}