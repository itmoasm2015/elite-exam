#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef unsigned char (*func)(unsigned char x, unsigned char y);

static unsigned char f1(unsigned char x, unsigned char y)
{
    return x + y;
}

static unsigned char f2(unsigned char x, unsigned char y)
{
    return ((int)x * y) ^ 0xdeadbeef;
}

static unsigned char f3(unsigned char x, unsigned char y)
{
    return x * x;
}

static unsigned char f4(unsigned char x, unsigned char y)
{
    return x ^ y;
}

static volatile func x[] = {
    f1, f2, f3, f4
};

void gen(int n, unsigned char *s, size_t *len)
{
    srand(n);
    *len = n + 1;
    unsigned char acc = 239;
    for (int i = 1; i < n+1; ++i) 
    {
        s[i] = rand();
        acc = x[s[i] & 3](acc, s[i]);
    }
    s[0] = acc;
}
