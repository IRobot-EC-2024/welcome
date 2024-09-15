#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(int arr[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
            }
        }
    }
}

int main()
{
    char input[1000];
    int arr[100];
    int n = 0;

    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    while (token != NULL)
    {
        arr[n++] = atoi(token);
        token = strtok(NULL, " ");
    }

    bubble(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
