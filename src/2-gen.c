#include <stddef.h>

void gen(int n, unsigned char *bytes, size_t *len)
{
    double *x = (void*)bytes;
    double *y = (void*)(bytes + sizeof(double));
    double *z = (void*)(bytes + 2 * sizeof(double));
    *len = 3 * sizeof(double);
    *x = n;
    *y = n + 0.1;
    *z = *x / *y;
}
