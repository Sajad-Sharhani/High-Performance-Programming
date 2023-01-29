#include <stdlib.h>
#include <stdio.h>

int CmpDouble(const void *a, const void *b)
{
    double *x = (double *)a;
    double *y = (double *)b;

    printf("Now the following two values are compared: %f and %f\n", *x, *y);

    if (*x > *y)
    {
        return -1;
    }
    else if (*x < *y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    double arrDouble[] = {9.3, -2.3, 1.2, -0.4, 2, 9.2, 1, 2.1, 0, -9.2};
    int arrlen = 10;
    qsort(arrDouble, arrlen, sizeof(double), CmpDouble);
    for (int i = 0; i < arrlen; i++)
    {
        printf("%f ", arrDouble[i]);
    }
    printf("\n");
    return 0;
}
