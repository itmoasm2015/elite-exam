#include <stddef.h>
#include <stdint.h>

void gen(int n, unsigned char *bytes, size_t *len)
{
    *len = (1 + n % 5) * 16;
    for (int i = 0; i < 1 + n % 5; ++i)
    {
        double x = n * 0.1 + i;
        double y = 3.1415926535 - x;
        uint32_t *cx = (void*)&x;
        uint32_t *cy = (void*)&y;
        
        *(uint32_t*)(bytes + i * 16 + 0) = cx[1];
        *(uint32_t*)(bytes + i * 16 + 4) = cy[0];
        *(uint32_t*)(bytes + i * 16 + 8) = cy[1];
        *(uint32_t*)(bytes + i * 16 + 12) = cx[0];
    }
}
