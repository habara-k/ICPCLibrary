#include "../template.cpp"

int64_t powm(int64_t a, int64_t n, int64_t m) {
    int64_t ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= a) %= m;
        (a *= a) %= m;
        n >>= 1;
    }
    return ret;
}

int64_t invm(int64_t a, int64_t m) {
    return powm(a, m-2, m);
}
