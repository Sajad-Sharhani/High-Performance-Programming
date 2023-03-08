#include <stdio.h>
#include <pthread.h>

void *the_thread_func(void *arg)
{
  // cast the input argument arg to (double*)
  double *data = (double *)arg;
  // use printf to print the three values there.
  printf("This is the thread function.\n");
  printf("data[0] = %f \n", data[0]);
  printf("data[1] = %f \n", data[1]);
  printf("data[2] = %f \n", data[2]);
  return NULL;
}

void *the_thread_func_B(void *arg)
{
  // cast the input argument arg to (double*)
  double *data = (double *)arg;
  // use printf to print the three values there.
  printf("This is the thread function B.\n");
  printf("data[0] = %f \n", data[0]);
  printf("data[1] = %f \n", data[1]);
  printf("data[2] = %f \n", data[2]);
  return NULL;
}

int main()
{
  printf("This is the main() function starting.\n");

  double data_for_thread[3];
  data_for_thread[0] = 5.7;
  data_for_thread[1] = 9.2;
  data_for_thread[2] = 1.6;

  double data_for_thread_B[3];
  data_for_thread_B[0] = 8.7;
  data_for_thread_B[1] = 2.2;
  data_for_thread_B[2] = 3.6;

  /* Start thread. */
  pthread_t thread;
  pthread_t thread_B;
  printf("the main() function now calling pthread_create().\n");
  pthread_create(&thread, NULL, the_thread_func, data_for_thread);
  pthread_create(&thread_B, NULL, the_thread_func_B, data_for_thread_B);

  printf("This is the main() function after pthread_create()\n");

  /* Do something here? */

  /* Wait for thread to finish. */
  printf("the main() function now calling pthread_join().\n");
  pthread_join(thread, NULL);
  pthread_join(thread_B, NULL);

  return 0;
}
