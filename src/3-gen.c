#include <stddef.h>

void gen(int n, unsigned char *bytes, size_t *len)
{
    *len = n < 1024 ? n : 1024;
    for (size_t i = 0; i < n; ++i)
    {
        bytes[i] = 6 + n % 90;
    }
}
