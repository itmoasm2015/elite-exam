#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void gen(int n, unsigned char *s, size_t *len)
{
    *len = n * 7 + 4;
    s[0] = 0xff;
    for (int i = 1; i < *len; ++i)
    {
        s[i] = s[i-1] - 1;
    }
}
