#include <stdio.h>
#include <omp.h>

void thread_func()
{
  printf("This is inside thread_func()!\n");
}

int main(int argc, char **argv)
{

  int get_num_threads = omp_get_num_threads();
  int get_max_threads = omp_get_max_threads();
  int get_thread_num = omp_get_thread_num();
  printf("num threads: %d \n", get_num_threads);
  printf("max threads: %d \n", get_max_threads);
  printf("thread num: %d \n", get_thread_num);
#pragma omp parallel num_threads(4)
  {
    thread_func();
  }
  printf("max threads: %d \n", omp_get_max_threads());

  return 0;
}
