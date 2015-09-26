#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void gen(int n, unsigned char *s, size_t *len)
{
    srand(n);
    int l = n + 1;
    *len = l + 1;
    unsigned char a[17] = {0};
    int sum = 141;
    for (int i = 0; i < l; ++i)
    {
        s[i] = rand();
        a[sum % 17] += s[i] + sum;
        sum ^= s[i];
    }
    unsigned char acc = 13;
    for (int i = 0; i < 17; ++i)
    {
        acc ^= a[i];
    }
    s[l] = acc;
}
