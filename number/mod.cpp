#include "../template.cpp"

ll powm(ll a, ll n, ll m) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= a) %= m;
        (a *= a) %= m;
        n >>= 1;
    }
    return ret;
}

ll invm(ll a, ll m) {
    return powm(a, m-2, m);
}
