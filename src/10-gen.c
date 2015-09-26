#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void gen(int n, unsigned char *s, size_t *len)
{
    srand(n);
    *len = n & 0xff;
    unsigned char sum = 123 ^ *len;
    for (size_t i = 0; i < *len - 1; ++i)
    {
        s[i] = rand();
        sum ^= s[i];
    }
    s[*len - 1] = sum;
}
