#include <stddef.h>
#include <stdlib.h>

void gen(int n, unsigned char *s, size_t *len)
{
    *len = 0;
    if (n > 240)
        return;
    *len = 10;
    s[0] = n;
    unsigned char acc = s[0];
    for (int i = 1; i < 10; ++i)
    {
        s[i] = acc ^ (n + i);
        acc = n + i;
    }
}
