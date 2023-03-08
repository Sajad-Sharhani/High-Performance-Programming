#include <pthread.h>
#include <stdio.h>

int m;
int count = 0;

int is_prime(int n)
{
    int i;
    if (n <= 1)
        return 0;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void *count_primes(void *arg)
{
    int i, start = ((int *)arg)[0], end = ((int *)arg)[1];
    for (i = start; i <= end; i++)
    {
        if (is_prime(i))
            count++;
    }
    printf("Number of prime numbers from %d to %d: %d (thread %lu) \n", start, end, count, pthread_self());
    pthread_exit(0);
}

int main()
{

    pthread_t thread1, thread2;
    printf("Enter the value of m: ");
    scanf("%d", &m);
    int i, range = m / 2;
    int start1 = 2, end1 = range;
    int start2 = range + 1, end2 = m;
    int arg1[2] = {start1, end1};
    int arg2[2] = {start2, end2};
    pthread_create(&thread1, NULL, count_primes, &arg1);
    pthread_create(&thread2, NULL, count_primes, &arg2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Number of prime numbers from 1 to %d: %d\n", m, count);
    return 0;
}