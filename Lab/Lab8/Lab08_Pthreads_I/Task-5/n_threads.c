#include <pthread.h>
#include <stdio.h>

void *print_thread(void *arg)
{
    int *index = (int *)arg;
    printf("This is thread %d \n", *index);
    return NULL;
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    pthread_t threads[n];
    int i;
    for (i = 0; i < n; i++)
    {
        pthread_create(&threads[i], NULL, print_thread, &i);
    }
    for (i = 0; i < n; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
}