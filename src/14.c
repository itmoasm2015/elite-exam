
int check(unsigned char const *s, int length) {
    if (length < 4 || (length & 1))
        return 0;
    for (int i = 2; i < length; i += 2)
    {
        if (s[i-2] < s[i])
            return 0;
    }
    for (int i = 3; i < length; i += 2)
    {
        if (s[i - 2] > s[i])
            return 0;
    }
    unsigned char sum = 33;
    for (int i = 0; i < length; ++i)
    {
        sum ^= s[i];
    }
    return sum == 239;
}
