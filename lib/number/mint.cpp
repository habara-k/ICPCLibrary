#include "../template.cpp"

template<int m>
struct mint {
    int x;
    mint(int x = 0) : x(((x % m) + m) % m) {}
    mint operator-() { return x ? m-x : 0; }
    mint &operator+=(mint r) {
        if ((x += r.x) >= m) x -= m;
        return *this;
    }
    mint &operator-=(mint r) {
        if ((x -= r.x) < 0) x += m;
        return *this;
    }
    mint &operator*=(mint r) {
        x = ((ll)x * r.x) % m;
        return *this;
    }
    mint inv() {
        int a = x, b = m, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return u;
    }
    mint &operator/=(mint r) { return *this *= r.inv(); }

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
    friend bool operator==(mint l, mint r) { return l.x == r.x; }
    friend bool operator!=(mint l, mint r) { return l.x != r.x; }
    friend ostream &operator<<(ostream &os, mint a) {
        return os << a.x;
    }
    friend istream &operator>>(istream &is, mint& a) {
        int x; is >> x; a = x; return is;
    }
};
