#include "../template.cpp"

template<ll m>
struct mint {
    ll x;
    mint(ll x = 0) : x(((x % m) + m) % m) {}
    mint operator-() { return x ? m-x : 0; }
    mint &operator+=(mint r) {
        if ((x += r.x) >= m) x -= m;
        return *this;
    }
    mint &operator-=(mint r) { return *this += -r; }
    mint &operator*=(mint r) {
        (x *= r.x) %= m;
        return *this;
    }
    mint &operator/=(mint r) { return *this *= r.pow(m-2); }

    friend mint operator+(mint l, mint r) { return l += r; }
    friend mint operator-(mint l, mint r) { return l -= r; }
    friend mint operator*(mint l, mint r) { return l *= r; }
    friend mint operator/(mint l, mint r) { return l /= r; }
    mint pow(ll n) {
        mint ret = 1, tmp = *this;
        while (n) {
            if (n & 1) ret *= tmp;
            tmp *= tmp, n >>= 1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, mint a) {
        return os << a.x;
    }
    friend istream &operator>>(istream &is, mint& a) {
        ll x; is >> x; a = x; return is;
    }
};

