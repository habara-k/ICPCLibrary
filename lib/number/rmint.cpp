#include "../template.cpp"

template<typename T=int>
struct rmint {
    static T &m() {
        static T m = 0;
        return m;
    }
    static void set_mod(T md) { m() = md; }
    T x;
    rmint(ll x = 0) : x(((x % m()) + m()) % m()) {}
    rmint operator-() const { return x ? m()-x : 0; }
    rmint &operator+=(rmint r) {
        if ((x += r.x) >= m()) x -= m();
        return *this;
    }
    rmint &operator-=(rmint r) {
        if ((x -= r.x) < 0) x += m();
        return *this;
    }
    rmint &operator*=(rmint r) {
        x = ((ll)x * r.x) % m();
        return *this;
    }
    rmint inv() const { return pow(m-2); }
    rmint &operator/=(rmint r) { return *this *= r.inv(); }

    friend rmint operator+(rmint l, rmint r) { return l += r; }
    friend rmint operator-(rmint l, rmint r) { return l -= r; }
    friend rmint operator*(rmint l, rmint r) { return l *= r; }
    friend rmint operator/(rmint l, rmint r) { return l /= r; }
    rmint pow(T n) const {
        rmint ret = 1, tmp = *this;
        while (n) {
            if (n & 1) ret *= tmp;
            tmp *= tmp, n >>= 1;
        }
        return ret;
    }
    friend bool operator==(rmint l, rmint r) { return l.x == r.x; }
    friend bool operator!=(rmint l, rmint r) { return l.x != r.x; }
    friend ostream &operator<<(ostream &os, rmint a) {
        return os << a.x;
    }
    friend istream &operator>>(istream &is, rmint& a) {
        ll x; is >> x; a = x; return is;
    }
};

