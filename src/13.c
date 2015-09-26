
int check(unsigned char const *s, int length) {
    int l = length - 1;
    unsigned char a[17] = {0};
    int sum = 141;
    for (int i = 0; i < l; ++i)
    {
        a[sum % 17] += s[i] + sum;
        sum ^= s[i];
    }
    unsigned char acc = 13;
    for (int i = 0; i < 17; ++i)
    {
        acc ^= a[i];
    }
    return s[length-1] == acc;
}
