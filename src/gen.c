#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void gen(int n, unsigned char *bytes, size_t *len);

void print(unsigned char const *bytes, size_t len)
{
    for (size_t i = 0; i < len; ++i)
    {
        printf("%02hhx", bytes[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    int n = 0;
    if (sscanf(argv[1], "%d", &n) != 1)
        return 2;
    unsigned char bytes[1024];
    size_t len = 0;
    gen(n, bytes, &len);
    print(bytes, len);
    return 0;
}
