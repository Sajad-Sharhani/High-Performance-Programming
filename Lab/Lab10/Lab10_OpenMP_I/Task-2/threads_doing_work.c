#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void do_some_work()
{
  printf("Now I am going to do some work...\n");
  long int i;
  long int j = 0;
  for (i = 0; i < 3000000000; i++)
  {
    j += 3;
  }
  printf("Work done! My result j = %ld\n", j);
}
// Start by rewriting the code so that the number of threads to use is given as a
// command-line input argument to the program. So, instead of
// #pragma omp parallel num_threads(3)
// you write
// #pragma omp parallel num_threads(n)
int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Usage: %s <number of threads> \n", argv[0]);
    return 1;
  }
  int n = atoi(argv[1]);
  printf("Using %d threads to do some work...\n", n);
  double start_time = omp_get_wtime();
#pragma omp parallel num_threads(n)
  {
    do_some_work();
  }
  printf("Time elapsed: %f seconds \n", omp_get_wtime() - start_time);

  return 0;
}

// how to use omp_get_wtime() to measure time
// https://stackoverflow.com/questions/10192922/how-to-measure-time-in-openmp
