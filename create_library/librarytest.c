#include "libhash.c"
#include <stdio.h>

int main()
{
    unsigned char string[6] = "tiago";

    unsigned long hashed = hash(string);

    printf("hashed:%ld\n", hashed);

    return 0;
}