#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        fprintf(stderr, "Usage %s <seed>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Seed
    srand(time(0));

    const int max = atoi(argv[1]);

    printf("Random number:%d", (rand() % max) + 1);

    exit(EXIT_SUCCESS);

    return 0;
};