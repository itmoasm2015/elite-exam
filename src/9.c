
int check(unsigned char const *s, int length) {
    if (length % 7 != 4)
        return 0;
    for (int i = 0; i < length - 1; ++i)
    {
        if (s[i] <= s[i+1])
            return 0;
    }
    return 1;
}
