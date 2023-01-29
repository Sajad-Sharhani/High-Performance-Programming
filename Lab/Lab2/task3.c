#include <stdlib.h>
#include <stdio.h>

int sumOrProduct()
{
    int a, b;
    printf("Enter 2 numbers: \n");
    scanf("%d %d", &a, &b);
    if (a % 2 == 0 && b % 2 == 0)
    {
        printf("%d + %d = %d \n", a, b, a + b);
    }
    else
    {
        printf("%d * %d = %d \n ", a, b, a * b);
    }
    return 0;
}

int maxAbs()
{
    double a, b, c;
    printf("Enter 3 numbers: \n");
    scanf("%lf %lf %lf", &a, &b, &c);
    double max = a;
    if (abs(b) > abs(max))
    {
        max = b;
    }
    if (abs(c) > abs(max))
    {
        max = c;
    }
    printf("max = %lf \n", max);
    return 0;
}

int secondMaxAbs()
{
    double a, b, c;
    printf("Enter 3 numbers: \n");
    scanf("%lf %lf %lf", &a, &b, &c);
    double max = a;
    double secondMax = a;
    if (abs(b) > abs(max))
    {
        secondMax = max;
        max = b;
    }
    if (abs(c) > abs(max))
    {
        secondMax = max;
        max = c;
    }
    printf("secondMax = %lf \n", secondMax);
    return 0;
}

// main function
int main()
{
    int choice;
    // ask user to choose which function to run
    printf("Choose which function to run: \n");
    printf("1. sumOrProduct \n");
    printf("2. maxAbs \n");
    printf("3. secondMaxAbs \n");
    // ask user input and store it in choice
    scanf("%d", &choice);

    // switch statement to run the function chosen by the user
    switch (choice)
    {
    case 1:
        sumOrProduct();
        break;
    case 2:
        maxAbs();
        break;
    case 3:
        secondMaxAbs();
        break;
    default:
        printf("choice = %d \n", choice);
        printf("Invalid choice \n");
        break;
    }

    return 0;
}
