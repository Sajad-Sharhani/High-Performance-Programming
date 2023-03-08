#include <stdio.h>
#include <pthread.h>

// Modify the code in threadtest.c so that it dynamically allocates some memory
// (call malloc()) and puts some values in that memory block. Then return the
// pointer to that memory block { instead of \return NULL"
void *the_thread_func(void *arg)
{

  printf("This is the_thread_func() function starting.\n");

  /* Do something here. */
  int *ptr = (int *)malloc(5 * sizeof(int));
  ptr[0] = 1;
  ptr[1] = 2;
  ptr[2] = 3;
  ptr[3] = 4;
  ptr[4] = 5;

  printf("This is the_thread_func() function returning.\n");
  return ptr;
}

int main()
{
  printf("This is the main() function starting.\n");

  /* Start thread. */
  pthread_t thread;
  printf("the main() function now calling pthread_create().\n");
  if (pthread_create(&thread, NULL, the_thread_func, NULL) != 0)
  {
    printf("ERROR: pthread_create failed.\n");
    return -1;
  }

  printf("This is the main() function after pthread_create()\n");

  /* Do something here? */
  int *ptr = (int *)the_thread_func(NULL);
  printf("The values in the memory block are: %d, %d, %d, %d, %d\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4]);

  /* Wait for thread to finish. */
  printf("the main() function now calling pthread_join().\n");
  if (pthread_join(thread, NULL) != 0)
  {
    printf("ERROR: pthread_join failed.\n");
    return -1;
  }

  pthread_join(thread, *ptr);

  return 0;
}
