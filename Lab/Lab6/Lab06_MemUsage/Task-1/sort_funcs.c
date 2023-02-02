#include <stdlib.h>
#include "sort_funcs.h"

#define MIN_LEN_FOR_BUBBLE_SORT 5

void bubble_sort(int *list, int N)
{
  int i, j;
  for (i = 0; i < N - 1; i++)
    for (j = 1 + i; j < N; j++)
    {
      if (list[i] > list[j])
      {
        // Swap
        int tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
      }
    }
}

void merge_sort(int *list_to_sort, int N)

{
  if (N <= MIN_LEN_FOR_BUBBLE_SORT)
  {
    // Use bubble sort for small lists
    bubble_sort(list_to_sort, N);
    return;
  }
  int n1 = N / 2;
  int n2 = N - n1;
  // Allocate a single buffer
  // int *buf = (int *)malloc((n1 + n2) * sizeof(int));
  // Set list1 and list2 by pointing into that buffer
  // int *list1 = buf;
  // int *list2 = buf + n1;
  // Allocate new lists on the stack
  // By placing the list1 and list2 buffers on the stack, the memory will be automatically deallocated once the function returns. This eliminates the need to call free() and makes the code simpler and more efficient.
  // N=2000000 results in a stack overflow
  int list1[n1];
  int list2[n2];
  int i;
  for (i = 0; i < n1; i++)
    list1[i] = list_to_sort[i];
  for (i = 0; i < n2; i++)
    list2[i] = list_to_sort[n1 + i];
  // Sort list1 and list2
  merge_sort(list1, n1);
  merge_sort(list2, n2);
  // Merge!
  int i1 = 0;
  int i2 = 0;
  i = 0;
  while (i1 < n1 && i2 < n2)
  {
    if (list1[i1] < list2[i2])
    {
      list_to_sort[i] = list1[i1];
      i1++;
    }
    else
    {
      list_to_sort[i] = list2[i2];
      i2++;
    }
    i++;
  }
  while (i1 < n1)
    list_to_sort[i++] = list1[i1++];
  while (i2 < n2)
    list_to_sort[i++] = list2[i2++];
  // free(buf);
}