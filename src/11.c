unsigned char x[] = {32, 225, 179, 244, 137, 94, 39, 231, 99, 189, 161, 128, 163, 52, 166, 40, 252, 104, 222, 245, 9, 208, 79, 144, 222, 235, 120, 204, 62, 216, 22, 89, 251, 173, 135, 123, 185, 23, 7, 238, 68, 155, 137, 204, 82, 52, 127, 228, 179, 252, 97, 238, 28, 239, 204, 7, 32, 128, 249, 48, 5, 167, 97, 180, 133, 235, 31, 138, 151, 70, 168, 90, 154, 201, 20, 49, 139, 57, 239, 52, 38, 60, 3, 207, 156, 161, 238, 202, 4, 249, 69, 254, 130, 116, 251, 188, 21, 51, 104, 47, 212, 201, 52, 59, 226, 59, 208, 112, 106, 183, 184, 128, 59, 118, 179, 135, 90, 68, 47, 0, 7, 130, 163, 228, 251, 102, 194, 184, 243, 23, 207, 46, 18, 219, 23, 144, 233, 226, 116, 161, 217, 233, 69, 160, 187, 214, 215, 97, 49, 166, 232, 20, 72, 248, 2, 77, 101, 243, 70, 219, 98, 234, 81, 161, 89, 134, 213, 75, 113, 43, 14, 206, 74, 242, 14, 14, 39, 152, 229, 194, 223, 6, 145, 38, 11, 243, 239, 187, 40, 31, 59, 137, 183, 20, 215, 99, 205, 95, 2, 106, 36, 70, 109, 149, 6, 159, 56, 26, 161, 107, 93, 176, 46, 55, 75, 202, 26, 103, 16, 27, 77, 209, 239, 246, 146, 0, 104, 1, 251, 157, 255, 113, 74, 64, 4, 203, 200, 42, 26, 25, 54, 160, 224, 4, 33, 137, 161, 17, 128, 189, 75, 240, 73, 238, 13, 178};

int check(unsigned char const *s, int length) {
    if (length < 4 || (length & 1))
        return 0;
    int steps = *(unsigned short*)s;
    int index = 2;
    int base = length - 3;
    unsigned char sum = 99;
    for (int i = 0; i < steps; ++i)
    {
        sum ^= s[index];
        index = (index * x[sum]) % base + 2;
    }
    return s[length-1] == sum;
}
