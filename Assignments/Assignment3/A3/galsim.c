#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

// struct for data that will be on the files
typedef struct star
{
    double x, y;
    double m;
    double vx, vy;
    double brightness;

} star;

// typedef struct {
//     double ax,ay;

// } vector;

static double get_wall_seconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double seconds = tv.tv_sec + (double)tv.tv_usec / 1000000;
    return seconds;
}

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);            // Number of stars to simulate
    char *fileName = strdup(argv[2]); // filename
    int nsteps = atoi(argv[3]);       // number of steps
    double delta_t = atof(argv[4]);   // timestep
    const double epsilon = 1e-3;      // force modification
    double G = 100.0 / N;             // Gravitational constant
    double r, rx, ry, ax, ay;         // registers to caclulate the the distance vectors

    star *stars = (struct star *)malloc(N * sizeof(star));
    FILE *fp;
    fp = fopen(fileName, "rb");

    if (fp == NULL)
    {
        printf("The file was not created.\n");
        exit(EXIT_FAILURE);
    }
    fread(stars, N * sizeof(star), 1, fp);
    fclose(fp);

    double time1 = get_wall_seconds();
    for (int n = 0; n < nsteps; n++) // loop through all the time stepts
    {

        for (int i = 0; i < N; i++)
        {

            register double ax = 0;
            register double ay = 0;
            double denominator;
            // for (int j = 0; j < i; j++)
            // {

            //     rx = stars[i].x - stars[j].x;
            //     ry = stars[i].y - stars[j].y;
            //     r = sqrt((rx * rx) + (ry * ry)) + epsilon;
            //     denominator = 1.0 / (r * r * r);
            //     ax += (-G * stars[j].m * rx) * denominator;
            //     ay += (-G * stars[j].m * ry) * denominator;
            // }

            // for (int j = i + 1; j < N; j++)
            // {

            //     rx = stars[i].x - stars[j].x;
            //     ry = stars[i].y - stars[j].y;
            //     r = sqrt((rx * rx) + (ry * ry)) + epsilon;
            //     denominator = 1.0 / (r * r * r);
            //     ax += (-G * stars[j].m * rx) * denominator;
            //     ay += (-G * stars[j].m * ry) * denominator;
            // }

            // loop unrolling the above loop
            for (int j = 0; j < i; j += 4)
            {

                rx = stars[i].x - stars[j].x;
                ry = stars[i].y - stars[j].y;
                r = sqrt((rx * rx) + (ry * ry)) + epsilon;
                denominator = 1.0 / (r * r * r);
                ax += (-G * stars[j].m * rx) * denominator;
                ay += (-G * stars[j].m * ry) * denominator;

                rx = stars[i].x - stars[j + 1].x;
                ry = stars[i].y - stars[j + 1].y;
                r = sqrt((rx * rx) + (ry * ry)) + epsilon;
                denominator = 1.0 / (r * r * r);
                ax += (-G * stars[j + 1].m * rx) * denominator;
                ay += (-G * stars[j + 1].m * ry) * denominator;

                rx = stars[i].x - stars[j + 2].x;
                ry = stars[i].y - stars[j + 2].y;
                r = sqrt((rx * rx) + (ry * ry)) + epsilon;
                denominator = 1.0 / (r * r * r);
                ax += (-G * stars[j + 2].m * rx) * denominator;
                ay += (-G * stars[j + 2].m * ry) * denominator;

                rx = stars[i].x - stars[j + 3].x;
                ry = stars[i].y - stars[j + 3].y;
                r = sqrt((rx * rx) + (ry * ry)) + epsilon;
                denominator = 1.0 / (r * r * r);
                ax += (-G * stars[j + 3].m * rx) * denominator;
                ay += (-G * stars[j + 3].m * ry) * denominator;
            }
            // loop unrolling the above loop
            for (int j = i + 1; j < N; j += 4)
            {

                rx = stars[i].x - stars[j].x;
                ry = stars[i].y - stars[j].y;
                r = sqrt((rx * rx) + (ry * ry)) + epsilon;
                denominator = 1.0 / (r * r * r);
                ax += (-G * stars[j].m * rx) * denominator;
                ay += (-G * stars[j].m * ry) * denominator;

                rx = stars[i].x - stars[j + 1].x;
                ry = stars[i].y - stars[j + 1].y;
                r = sqrt((rx * rx) + (ry * ry)) + epsilon;
                denominator = 1.0 / (r * r * r);
                ax += (-G * stars[j + 1].m * rx) * denominator;
                ay += (-G * stars[j + 1].m * ry) * denominator;

                rx = stars[i].x - stars[j + 2].x;
                ry = stars[i].y - stars[j + 2].y;
                r = sqrt((rx * rx) + (ry * ry)) + epsilon;
                denominator = 1.0 / (r * r * r);
                ax += (-G * stars[j + 2].m * rx) * denominator;
                ay += (-G * stars[j + 2].m * ry) * denominator;

                rx = stars[i].x - stars[j + 3].x;
                ry = stars[i].y - stars[j + 3].y;
                r = sqrt((rx * rx) + (ry * ry)) + epsilon;
                denominator = 1.0 / (r * r * r);
                ax += (-G * stars[j + 3].m * rx) * denominator;
                ay += (-G * stars[j + 3].m * ry) * denominator;
            }

            stars[i].vx += delta_t * ax;
            stars[i].vy += delta_t * ay;
        }
        for (int i = 0; i < N; i++)
        {
            stars[i].x += delta_t * stars[i].vx;
            stars[i].y += delta_t * stars[i].vy;
        }
    }
    printf("Simulating %7.5f wall seconds.\n", get_wall_seconds() - time1);

    FILE *fp2 = fopen("results.gal", "w+b");

    fwrite(stars, N * 6 * sizeof(double), 1, fp);
    fclose(fp2);
    free(stars);
    free(fileName);
    return 1;
}