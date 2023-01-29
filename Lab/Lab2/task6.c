#include <stdlib.h>
#include <stdio.h>

int main()
{
    int dividend, divisor;
    printf("Enter dividend: \n");
    scanf("%d", &dividend);
    printf("Enter divisor: \n");
    scanf("%d", &divisor);
    printf("Quotient = %d \n", dividend / divisor);
    printf("Remainder = %d \n", dividend % divisor);
    return 0;
}