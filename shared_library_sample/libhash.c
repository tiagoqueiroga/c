#include "libhash.h"

unsigned long hash(unsigned char *str)
{

    unsigned long h = 5381;
    int c;

    while ((c = *str++))
    {
        // Example: 'a' = 172192 + 5381 + 97
        h = ((h << 5) + h) + c;
    }

    return h;
}
