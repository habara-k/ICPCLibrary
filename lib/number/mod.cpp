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

ll totient(ll m) {
    ll ret = m;
    for (int i = 2; i*i <= m; ++i) {
        if (m % i == 0) {
            ret -= ret / i;
            while (m % i == 0) m /= i;
        }
    }
    if (m > 1) ret -= ret / m;
    return ret;
}

ll inv_coprime(ll a, ll m) {
    return powm(a, totient(m)-1, m);
}

/**
 * @brief 離散対数 BSGS O(sqrt(m))
 * @author habara-k
 * @date 2020/10/16
 * @return x^k == y mod m を満たす最小のk(>=0) (なければ-1)
 * @require gcd(x, m) = 1
 */
ll log_coprime(ll x, ll y, ll m) {
    ((x %= m) += m) %= m;
    ((y %= m) += m) %= m;
    if (y == 1 or m == 1) return 0;
    if (x == 0) return y == 0 ? 1 : -1;

    ll s = sqrt(m) + 1;
    map<ll,int> bs;
    ll b = 1;
    for (ll j = 0; j < s; ++j, (b *= x) %= m) {
        if (!bs.count(b)) bs[b] = j;
    }
    ll inv = inv_coprime(b, m);
    // m: 素数 のときは inv = invm(b, m) でよい
    for (ll g = 1, i = 0; i < s; ++i, (g *= inv) %= m) {
        if (bs.count((g * y) % m)) {
            ll k = i * s + bs[(g * y) % m];
            assert(powm(x, k, m) == y);
            return k;
        }
    }
    return -1;
}

/**
 * @brief 離散対数 O(sqrt(m))
 * https://codeforces.com/blog/entry/56264
 * @author habara-k
 * @date 2020/10/16
 * @return x^k == y mod m を満たす最小のk(>=0) (なければ-1)
 */
ll logm(ll x, ll y, ll m) {
    ((x %= m) += m) %= m;
    ((y %= m) += m) %= m;

    if (y == 1 or m == 1) return 0;
    if (x == 0) return y == 0 ? 1 : -1;

    map<ll,int> f1, f2;
    ll m1 = 1, m2 = 1;
    {
        ll tmp = m;
        for (ll p = 2; p*p <= m; ++p) {
            if (tmp % p) continue;
            while (tmp % p == 0) {
                tmp /= p;
                ++(x % p ? f2 : f1)[p];
                (x % p ? m2 : m1) *= p;
            }
        }
        if (tmp > 1) {
            ++(x % tmp ? f2 : f1)[tmp];
            (x % tmp ? m2 : m1) *= tmp;
        }
    }

    int K = 0;
    for (auto& tp : f1) chmax(K, tp.second);
    for (ll a = 1, k = 0; k < K; ++k, (a *= x) %= m) {
        if (a == y) return k;
    }
    if (y % m1 != 0) return -1;

    ll ret = log_coprime(x, y * powm(inv_coprime(x, m2), K, m2), m2);
    if (ret == -1) return ret;
    else return ret + K;
}

/**
 * @brief
 * 平方剰余 O(log(p)^2) ?
 * http://kirika-comp.hatenablog.com/entry/2018/03/12/210446
 * @author habara-k
 * @date 2020/10/16
 * @return x^2 == a mod p を満たすx (なければ-1)
 * @require p: 素数
 */
ll modsqrt(ll a, ll p) {
    a %= p;
    auto legendre = [&](ll a) {
        return powm(a, (p-1)/2, p);
    };
    if (a == 0) return 0;
    if (p == 2) return a;
    if (legendre(a) != 1) return -1;
    ll q = p-1, s = 0;
    while (q % 2 == 0) q >>= 1, ++s;
    mt19937 mt;
    ll z;
    do {z = mt() % p;} while (legendre(z) != p-1);

    ll m = s, c = powm(z, q, p), t = powm(a, q, p), r = powm(a, (q+1)/2, p);
    while (m > 1) {
        ll k = 0, tmp = t;
        while (tmp != 1) (tmp *= tmp) %= p, ++k;
        assert(k < m);
        (t *= powm(c, 1ll<<(m-k), p)) %= p;
        (r *= powm(c, 1ll<<(m-k-1), p)) %= p;
        c = powm(c, 1ll<<(m-k), p);
        m = k;
    }
    assert((r * r) % p == a);
    return r;
}

