#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;
    printf("Input: \n");
    scanf("%d", &n);
    int reversed = 0;
    int original = n;
    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    printf("Output: %d is %s a palindrome \n", original, original == reversed ? "" : "not");
    return 0;
}
