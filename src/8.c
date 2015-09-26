
typedef unsigned char (*func)(unsigned char x, unsigned char y);

static unsigned char hello(unsigned char x, unsigned char y)
{
    return x + y;
}

static unsigned char fuck(unsigned char x, unsigned char y)
{
    return ((int)x * y) ^ 0xdeadbeef;
}

static unsigned char itmo(unsigned char x, unsigned char y)
{
    return x * x;
}

static unsigned char lol(unsigned char x, unsigned char y)
{
    return x ^ y;
}

static volatile func x[] = {
    hello, fuck, itmo, lol
};

int check(unsigned char const *s, int length) {
    if (length < 1)
        return 0;
    unsigned char acc = 239;
    for (int i = 1; i < length; ++i) 
    {
        acc = x[s[i] & 3](acc, s[i]);
    }
    return acc == s[0];
}
