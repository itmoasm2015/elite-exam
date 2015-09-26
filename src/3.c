
int check(unsigned char const *s, int length) {
    if (length <= 0)
        return 0;
    int sum = 0;
    for (int i = 0; i < length; ++i)
    {
        sum += (int)s[i];
    }
    sum /= length;
    return sum > 5 && sum < 100; 
}
