#include <stddef.h>
#include <stdlib.h>

void gen(int n, unsigned char *bytes, size_t *len)
{
    srand(n);
    *len = n;
    for (int i = 0; i < n; ++i)
    {
        unsigned char a = i * 10 + 50;
        unsigned char b = i * 20 + 60;
        if (a > b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        bytes[i] = rand() % (b - a + 1) + a;
    }
}
