#include <stdlib.h>
#include <stdio.h>

void print100to0()
{
    for (int i = 100; i >= 0; i -= 4)
    {
        printf("%d ", i);
    }
    printf("\n");
}

void print100to0while()
{
    int i = 100;
    while (i >= 0)
    {
        printf("%d ", i);
        i -= 4;
    }
    printf("\n");
}

void print100to0dowhile()
{
    int i = 100;
    do
    {
        printf("%d ", i);
        i -= 4;
    } while (i >= 0);
    printf("\n");
}

int main()
{
    print100to0();
    print100to0while();
    print100to0dowhile();
    return 0;
}