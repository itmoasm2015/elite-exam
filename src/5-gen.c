#include <stddef.h>
#include <stdint.h>

void gen(int n, unsigned char *bytes, size_t *len)
{
    *len = (1 + n % 5) * 32;
    for (int i = 0; i < 1 + n % 5; ++i)
    {
        double e = 2.718281828;
        double x = n * 0.1 + i;
        double y = n * 0.2 + 10*i;
        double z = n * i + 1.2;
        double u = 5.0 - (x * z - e) / y;
        // x * z + y * u > e
        // u > -(x * z - e) / y
        uint32_t *cx = (void*)&x;
        uint32_t *cy = (void*)&y;
        uint32_t *cz = (void*)&z;
        uint32_t *cu = (void*)&u;
        
        *(uint32_t*)(bytes + i * 32 + 0) = cy[1];
        *(uint32_t*)(bytes + i * 32 + 4) = cy[0];
        *(uint32_t*)(bytes + i * 32 + 8) = cx[0];
        *(uint32_t*)(bytes + i * 32 + 12) = cx[1];

        *(uint32_t*)(bytes + i * 32 + 16) = cz[0];
        *(uint32_t*)(bytes + i * 32 + 20) = cu[0];
        *(uint32_t*)(bytes + i * 32 + 24) = cz[1];
        *(uint32_t*)(bytes + i * 32 + 28) = cu[1];
    }
}
