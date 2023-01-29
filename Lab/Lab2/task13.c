#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *file;
    char product[50];
    double price;
    file = fopen("./data.txt", "r");
    while (fscanf(file, "%s %lf", product, &price) != EOF)
        // do not print the the line if it contains only number
        if (product[0] >= 'A' && product[0] <= 'Z')
            printf("%s %.1lf \n", product, price);

    fclose(file);
    return 0;
}
