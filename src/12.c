
int check(unsigned char const *s, int length) {
    int count[256] = {0};
    for (int i = 0; i < length; ++i)
    {
        count[s[i]] += 1;
    }
    int max = 0;
    int min = 0;
    for (int i = 0; i < 256; ++i)
    {
        if (count[i] > count[max])
            max = i;
        if (count[i] < count[min])
            min = i;
    }
    if (count[max] != 3)
        return 0;
    if (max == 255 || max == 0)
        return 0;
    if (count[max + 1] == 0 || count[max - 1] == 0)
        return 0;
    for (int i = max + 1; i < 256; ++i)
    {
        if (count[i] > count[i-1])
            return 0;
    }
    for (int i = max - 1; i >= 0; --i)
    {
        if (count[i] > count[i+1])
            return 0;
    }
    return 1;
}
