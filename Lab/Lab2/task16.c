#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    typedef struct product
    {
        char name[50];
        double price;
    } product_t;
    product_t *arr_of_prod;
    char product[50];
    double price;
    char filename[50];
    strcpy(filename, argv[1]);
    file = fopen(filename, "r");
    int i = 0;
    int n;
    fscanf(file, "%d", &n);

    arr_of_prod = (product_t *)malloc(n * sizeof(product_t));
    while (fscanf(file, "%s %lf", product, &price) != EOF)
    {
        // do not print the the line if it contains only number
        if (product[0] >= 'A' && product[0] <= 'Z')
        {
            strcpy(arr_of_prod[i].name, product);
            arr_of_prod[i].price = price;
            ++i;
        }
    }
    for (int j = 0; j < i; ++j)
        printf("%s %.1lf \n", arr_of_prod[j].name, arr_of_prod[j].price);

    fclose(file);
    return 0;
}