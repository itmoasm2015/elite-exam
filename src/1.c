// easy
// x:y:z -> x * y = z

int check(unsigned char const *s, int length) {
    if (length != 3 * sizeof(double))
        return 0;
    double *x = (void*)s;
    double *y = (void*)(s + sizeof(double));
    double *z = (void*)(s + 2 * sizeof(double));
    return *x * *y == *z;
}
