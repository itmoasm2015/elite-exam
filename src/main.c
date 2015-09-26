#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *hex2bytes(const char *s) {
    int len = strlen(s);
    if (len & 1)
        return 0;
    unsigned char *r = malloc(len / 2);
    char dig[3];
    dig[2] = 0;
    for (int i = 0; i < len / 2; ++i) {
        dig[0] = s[i * 2];
        dig[1] = s[i * 2 + 1];
        if (sscanf(dig, "%hhx", r + i) != 1)
            goto fail;
    }
    return r;
fail:
    free(r);
    return 0;
}

int check(unsigned char const *s, int length);

int main(int argc, char ** argv) {
    unsigned char *bytes = 0;
    if (argc != 2) {
        goto fail;
    }

    bytes = hex2bytes(argv[1]);
    if (!bytes)
        goto fail;

    int length = strlen(argv[1]) / 2;

    if (!check(bytes, length))
        goto fail;

    printf("OK\n");
    return 0;
fail:
    printf("FAIL\n");
    if (bytes)
        free(bytes);
    return 1;
}
