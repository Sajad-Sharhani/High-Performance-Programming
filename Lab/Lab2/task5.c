#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter a number: \n");
    scanf("%d", &n);
    int root = sqrt(n);
    printf("%d is %s a perfect square \n", n, root * root == n ? "" : "not");
    return 0;
}
