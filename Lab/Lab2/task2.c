#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c", i == 0 || i == n - 1 || j == 0 || j == m - 1 ? '*' : '.');
        }
        printf("\n");
    }
    return 0;
}