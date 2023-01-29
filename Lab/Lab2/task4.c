#include <stdlib.h>
#include <stdio.h>

int main()
{
    double a, b;
    char op;
    printf("Input: \n");
    scanf("%lf %c %lf", &a, &op, &b);
    switch (op)
    {
    case '+':
        printf("Output %lf + %lf = %lf \n", a, b, a + b);
        break;
    case '-':
        printf("Output %lf - %lf = %lf \n", a, b, a - b);
        break;
    case '*':
        printf("Output %lf * %lf = %lf \n", a, b, a * b);
        break;
    case '/':
        printf("Output %lf / %lf = %lf \n", a, b, a / b);
        break;
    default:
        printf("Invalid operation \n");
        break;
    }
    return 0;
}
