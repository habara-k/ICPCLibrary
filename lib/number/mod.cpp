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


/**
 * @brief
 * 離散対数 O(sqrt(m))
 * @author habara-k
 * @date 2020/05/18
 * @verify https://atcoder.jp/contests/arc042/submissions/13372745
 *
 * @param[in] a: 0 < a < m
 * @param[in] b: 0 <= b < m
 * @param[in] m: prime
 * @return:
 *     minimum x >= 0 s.t. a^x == b mod m
 *     if no x satisfies the condition, return -1
 */

ll logm(ll a, ll b, ll m) {

    ll sm = sqrt(m);

    map<ll,int> mp;
    for (ll t = 1, r = 0; r < sm; (t *= a) %= m, ++r) {
        if (!mp.count(t)) mp[t] = r;
    }

    ll A = invm(powm(a, sm, m), m);
    for (ll t = b, p = 0; p <= sm; (t *= A) %= m, ++p) {
        if (mp.count(t)) {
            return sm * p + mp[t];
        }
    }
    return -1;
}
