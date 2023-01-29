#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// One way of checking the relative precision of
// oating-point numbers is to try adding
// a very small number to 1 and check if the result is greater than 1. Write a small
// program doing such a test: keep a small number in a variable e.g. epsilon and
// in a loop make epsilon smaller and smaller, for example by multipluing it by
// 0.5 each loop iteration. In each loop iteration, do a little test where you compute
// epsilon + 1 and store that result in another variable, and then check if it is greater
// than 1.

void test_epsilon()
{
    float epsilon = 1.0;
    float one = 1.0;
    float result;
    int i;
    for (i = 0; i < 100; i++)
    {
        result = epsilon + one;
        printf("Iteration = %d  epsilon = %e, result = %e \n", i, epsilon, result);
        epsilon *= 0.5;
    }
}

// Write a small program that tests what happens when a number becomes too small
// or too large: initialize a float or double variable to some value and then use a
// loop where you increase the number by e.g. a factor of 100 each time, and use
// printf to print the number each time.

int main(int argc, char **argv)
{
    float f = 1.0;
    double d = 1.0;
    int i;
    for (i = 0; i < 200; i++)
    {
        f *= 100;
        d *= 100;

        printf("Iteration = %d  f = %e, d = %e \n", i, f, d);
    }

    //     test producing a \not-a-number" (NaN) result by e.g. calling sqrt() for a negative
    // number, and printing the result.

    float f2 = -1.0;
    double d2 = -1.0;
    printf("sqrt(-1.0) = %e, sqrt(-1.0) = %e \n", sqrt(f2), sqrt(d2));

    // What happens if you continue to do operations on a NaN or infinity?
    // Try to find out what happens by e.g. adding a number to a NaN or infinity.

    float f3 = 1.0 / 0.0;
    double d3 = 1.0 / 0.0;
    printf("1.0 / 0.0 = %e, 1.0 / 0.0 = %e \n", f3, d3);

    float f4 = 0.0 / 0.0;
    double d4 = 0.0 / 0.0;
    printf("0.0 / 0.0 = %e, 0.0 / 0.0 = %e \n", f4, d4);

    float f5 = 1.0 / 0.0 + 1.0;
    double d5 = 1.0 / 0.0 + 1.0;
    printf("1.0 / 0.0 + 1.0 = %e, 1.0 / 0.0 + 1.0 = %e \n", f5, d5);

    float f6 = 0.0 / 0.0 + 1.0;
    double d6 = 0.0 / 0.0 + 1.0;
    printf("0.0 / 0.0 + 1.0 = %e, 0.0 / 0.0 + 1.0 = %e \n", f6, d6);

    test_epsilon();

    return 0;
}

// Hadoop Standalone Mode
// In this mode, none of the Hadoop daemons are started(Namenode, Datanode, Secondary Namenode, Jobtracker, Tasktracker). Instead, the Hadoop daemons are run on single machine as Java processes. This mode is useful for testing and debugging Hadoop applications. It is not intended for production use. Hadoop Standalone mode is the default mode of Hadoop and it is faster than other modes.

// Hadoop Pseudo-Distributed Mode
// In this mode we have a single node cluster and it is simulated which means that all the processes will run independently on a single machine. All the Hadoop daemons will run as a separate process on separate JVM. This mode is useful for testing and debugging Hadoop applications. we can use HDFS(Hadoop Distributed File System) commands to interact with the Hadoop file system.