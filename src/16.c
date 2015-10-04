int check(unsigned char const *s, int length) {
    if (length < 2)
        return 0;
    unsigned char acc = s[0];
    for (int i = 1; i < length; ++i)
    {
        unsigned char newAcc = s[i] ^ acc;
        if (newAcc <= acc)
            return 0;
        acc = newAcc;
    }

    return 1;
}
