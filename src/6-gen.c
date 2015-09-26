
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

static unsigned char x[] = {20, 181, 181, 25, 48, 222, 124, 247, 220, 40, 109, 147, 159, 93, 188, 82, 83, 237, 47, 167, 105, 13, 226, 64, 149, 14, 171, 14, 190, 102, 232, 172, 187, 85, 105, 203, 0, 109, 253, 40, 138, 185, 72, 205, 141, 98, 215, 126, 71, 119, 197, 52, 149, 207, 185, 212, 46, 176, 164, 231, 174, 86, 224, 231, 247, 174, 45, 64, 109, 58, 113, 32, 173, 88, 226, 253, 252, 130, 70, 245, 1, 69, 242, 236, 202, 19, 120, 31, 10, 116, 107, 23, 138, 41, 210, 239, 222, 121, 111, 74, 179, 173, 97, 85, 151, 176, 25, 235, 172, 109, 217, 234, 98, 143, 127, 165, 195, 150, 94, 151, 144, 117, 21, 151, 123, 16, 234, 107, 214, 86, 245, 225, 203, 104, 31, 124, 29, 91, 191, 194, 231, 248, 17, 195, 165, 55, 162, 172, 245, 42, 25, 128, 224, 38, 113, 147, 169, 179, 78, 221, 80, 143, 155, 141, 50, 165, 20, 236, 67, 181, 14, 235, 236, 117, 13, 216, 43, 137, 14, 124, 147, 245, 144, 190, 171, 60, 122, 126, 68, 234, 78, 137, 116, 86, 44, 3, 255, 144, 47, 232, 95, 239, 221, 147, 225, 197, 226, 67, 88, 218, 128, 107, 52, 23, 97, 92, 235, 96, 85, 21, 124, 17, 142, 134, 159, 133, 21, 145, 6, 86, 88, 85, 227, 22, 247, 2, 123, 79, 206, 131, 101, 159, 190, 239, 45, 195, 157, 83, 166, 177, 183, 73, 243, 15, 17, 118};
void gen(int n, unsigned char *bytes, size_t *len)
{
    srand(n);
    *len = n + 1;
    unsigned char acc = 117;
    for (int i = 1; i < n + 1; ++i)
    {
        bytes[i] = rand();
        acc = x[acc] ^ bytes[i];

    }
    bytes[0] = acc;
}

