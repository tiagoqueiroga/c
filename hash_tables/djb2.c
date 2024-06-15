
#include <stdio.h>

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
    {
        // Example: 'a' = 172192 + 5381 + 97
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}