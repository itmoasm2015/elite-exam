int check(unsigned char const *s, int length) {
    if (length < 5)
        return 0;
    for (int i = 0; i < (length + 1) >> 1; ++i)
    {
        if (s[i] != s[length - i - 1])
            return 0;
    }
    return 1;
}
