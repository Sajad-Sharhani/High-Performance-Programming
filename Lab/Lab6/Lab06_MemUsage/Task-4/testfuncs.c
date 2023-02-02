#include "testfuncs.h"
#include <stdio.h>

void transform_std(float *dest,
                   const float *src,
                   const float *params,
                   int n,
                   int np)
{
  int i, j;
  int k = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < np; j++)
    {
      dest[k] = params[j] * src[k] + params[j] * src[k] * src[k];
      k++;
    }
}
const int NP = 2;

void transform_opt(float *__restrict dest,
                   const float *__restrict src,
                   const float *__restrict params,
                   int n,
                   int np)
{
  // In this case, the keyword const doesn't make any difference since the value of NP is defined inside the transform_opt function and cannot be changed from outside the function. The value of NP is also not being passed as an argument, so it does not need to be declared const.
  // const int NP = 2;

  // if (np != NP)
  // {
  //   printf("ERROR: np must be same as NP.\n");
  //   return;
  // }
  int i, j;
  int k = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < NP; j++)
    {
      dest[k] = params[j] * src[k] + params[j] * src[k] * src[k];
      k++;
    }
}
