#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// prime numbers computation with OpenMP
// compile with: gcc -fopenmp prime.c -o prime
// run with: ./prime <num_threads> <num_primes>
// example: ./prime 4 1000000

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

void *count_primes_A(void *arg)
{
    int i, start = ((int *)arg)[0], end = ((int *)arg)[1];
    for (i = start; i <= end; i++)
    {
        if (is_prime(i))
            count++;
    }
}

void *count_primes_B(void *arg)
{
    int i, start = ((int *)arg)[0], end = ((int *)arg)[1];
    for (i = start; i <= end; i++)
    {
        if (is_prime(i))
            count++;
    }
}

// use openmp
int main(int argc, char *argv[])
{
    // use openmp
    int num_threads = atoi(argv[1]);
    int num_primes = atoi(argv[2]);

    int i;
    int start = omp_get_wtime();
#pragma omp parallel num_threads(num_threads)
    {
        int id = omp_get_thread_num();
        int start = id * num_primes / num_threads + 1;
        int end = (id + 1) * num_primes / num_threads;
        if (id == 0)
            count_primes_A(&start, &end);
        else
            count_primes_B(&start, &end);
    }
    printf("Time elapsed: %f seconds \n", omp_get_wtime() - start);

    printf("There are %d prime numbers between 1 and %d.\n", count, num_primes);

    return 0;
}
