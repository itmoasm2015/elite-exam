
int check(unsigned char const *s, int length) {
    unsigned char sum = 123;
    for (int i = 0; i < length; ++i)
    {
        sum ^= s[i];
    }
    return sum == length;
}
