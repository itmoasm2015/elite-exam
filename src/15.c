
int check(unsigned char const *s, int length) {
    if (length == 0)
        return 0;
    for (int i = 0; i < length; ++i)
    {
        unsigned char a = i * 10 + 50;
        unsigned char b = i * 20 + 60;
        if (a > b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        if (s[i] < a || s[i] > b)
            return 0;
    }
    return 1;
}
