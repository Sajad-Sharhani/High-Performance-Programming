#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Write a C program which sorts an array of strings in alphabetic order using the
// qsort function. You should write a function CmpString which follows the prototype
// of compar and compare two elements of the array, such that the following code sorts
// elements of the array arrStr in alphabetic order:
// char *arrStr[] = {"daa", "cbab", "bbbb", "bababa", "ccccc", "aaaa"};
// int arrStrLen = sizeof(arrStr) / sizeof(char *);
// qsort(arrStr, arrStrLen, sizeof(char *), CmpString);
// Hint. Use the strcmp function for comparison of strings.

int CmpString(const void *a, const void *b)
{
    char **x = (char **)a;
    char **y = (char **)b;

    return strcmp(*x, *y);
}

int main(void)
{
    char *arrStr[] = {"daa", "cbab", "bbbb", "bababa", "ccccc", "aaaa"};
    int arrStrLen = sizeof(arrStr) / sizeof(char *);
    qsort(arrStr, arrStrLen, sizeof(char *), CmpString);
    for (int i = 0; i < arrStrLen; i++)
    {
        printf("%s ", arrStr[i]);
    }
    printf("\n");
    return 0;
}
