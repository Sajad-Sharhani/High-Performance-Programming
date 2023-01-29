#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *arr;
    int *new_arr;
    int n;
    int new_n = 0;
    printf("Input: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    new_arr = (int *)malloc(new_n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; ++i)
    {
        int is_prime = 1;
        for (int j = 2; j < arr[i]; ++j)
            if (arr[i] % j == 0)
            {
                is_prime = 0;
                break;
            }
        if (is_prime == 0)
        {
            new_arr[new_n] = arr[i];
            ++new_n;
            new_arr = (int *)realloc(new_arr, (new_n + 1) * sizeof(int));
        }
    }
    printf("Output: ");
    for (int i = 0; i < new_n; ++i)
        printf("%d ", new_arr[i]);
    printf("\nSize: %d \n", new_n);
    return 0;
}