#include <stdlib.h>
#include <stdio.h>

// Write a C program that creates a matrix of dimension n ×n of the form below and
// displays it:
// 0 1 1 1 1
// −1 0 1 1 1
// −1 −1 0 1 1
// −1 −1 −1 0 1
// −1 −1 −1 −1 0

// Note. Use statically allocated two-dimensional arrays. First store the matrix as a
// two-dimensional array in memory, and then use the values from the array to print
// the matrix.

int main(void)
{
    int n = 6;
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

       for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 0;
            }
            else if (i > j)
            {
                matrix[i][j] = -1;
            }
            else
            {
                matrix[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}