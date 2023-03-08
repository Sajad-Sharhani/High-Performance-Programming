#include <stdio.h>
#include <pthread.h>

void *the_thread_func(void *arg)
{
  printf("This is the thread function.\n");
  printf("the_thread_func() starting doing some work.\n");
  long int i;
  double sum;
  for (i = 0; i < 1000000000; i++)
    sum += 1e-7;
  printf("Result of work in the_thread_func(): sum = %f\n", sum);
  return NULL;
}
void *the_thread_func_B(void *arg)
{
  printf("This is the thread function B.\n");
  printf("the_thread_func_B() starting doing some work.\n");
  long int i;
  double sum;
  for (i = 0; i < 1000000000; i++)
    sum += 1e-7;
  printf("Result of work in the_thread_func_B(): sum = %f\n", sum);
  return NULL;
}

int main()
{
  printf("This is the main() function starting.\n");

  /* Start thread. */
  pthread_t thread;
  pthread_t *thread_B;

  pthread_create(&thread, NULL, the_thread_func, NULL);
  pthread_create(thread_B, NULL, the_thread_func_B, NULL);

  printf("This is the main() function after pthread_create()\n");

  printf("the main() function now calling pthread_create().\n");
  printf("main() starting doing some work.\n");
  long int i;
  double sum;
  for (i = 0; i < 10000000000; i++)
    sum += 1e-7;
  printf("Result of work in main(): sum = %f\n", sum);

  /* Wait for thread to finish. */
  printf("the main() function now calling pthread_join().\n");
  pthread_join(thread, NULL);
  printf("the main() function now calling pthread_join() for thread B.\n");
  pthread_join(*thread_B, NULL);

  return 0;
}
