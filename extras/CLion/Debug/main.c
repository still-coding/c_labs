#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define N 10

int main()
{
    unsigned long seed;
    read(open("/dev/random", O_RDONLY), &seed, sizeof(seed));
    srand(seed);

    int a[N], i, s = 0;
    printf("My array:");
    for (i = 0; i < N; ++i)
    {
        a[i] = rand() % N;
        s += a[i];
        printf("%2d",  a[i]);
    }
    printf("\nSumm: %d\n", s);
    return 0;
}