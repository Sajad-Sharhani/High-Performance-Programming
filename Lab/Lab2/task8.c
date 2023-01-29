#include <stdlib.h>
#include <stdio.h>

int main()
{
    double d = 1.0;
    int i = 1;
    char c = 'a';
    printf("double: %lf, address: %p, size: %lu \n", d, &d, sizeof(d));
    printf("int: %d, address: %p, size: %lu \n", i, &i, sizeof(i));
    printf("char: %c, address: %p, size: %lu \n", c, &c, sizeof(c));
    return 0;
}