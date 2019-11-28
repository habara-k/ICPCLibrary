#include "../template.cpp"

long long powm(long long a, long long n, long long m) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= a) %= m;
        (a *= a) %= m;
        n >>= 1;
    }
    return ret;
}

long long invm(long long a, long long m) {
    return powm(a, m-2, m);
}
