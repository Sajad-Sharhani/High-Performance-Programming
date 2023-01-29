#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *arr;
    int n = 0;
    int sum = 0;
    arr = (int *)malloc(n * sizeof(int));
    printf("Input: ");
    while (scanf("%d", &arr[n]) == 1)
    {
        sum += arr[n];
        ++n;
        arr = (int *)realloc(arr, (n + 1) * sizeof(int));
    }
    printf("Output: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\nSum: %d \n", sum);
    return 0;
}
