#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    char product[50];
    double price;
    char filename[50];
    strcpy(filename, argv[1]);
    file = fopen(filename, "r");
    while (fscanf(file, "%s %lf", product, &price) != EOF)
        // do not print the the line if it contains only number
        if (product[0] >= 'A' && product[0] <= 'Z')
            printf("%s %.1lf \n", product, price);

    fclose(file);
    return 0;
}
