#include "../template.cpp"

template<int64_t mod>
class modint {
    int64_t x;

public:
    modint(int64_t x = 0) : x(x < 0 ? ((x % mod) + mod) % mod : x % mod) {}

    const modint operator-() const { return x ? mod - x : 0; }

    modint& operator+=(const modint& rhs) {
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }
    modint& operator-=(const modint& rhs) {
        return *this += -rhs;
    }
    modint& operator*=(const modint& rhs) {
        (x *= rhs.x) %= mod;
        return *this;
    }
    modint& operator/=(const modint& rhs) {
        return *this *= rhs.pow(mod - 2);
    }

    friend const modint operator+(modint lhs, const modint& rhs) {
        return lhs += rhs;
    }
    friend const modint operator-(modint lhs, const modint& rhs) {
        return lhs -= rhs;
    }
    friend const modint operator*(modint lhs, const modint& rhs) {
        return lhs *= rhs;
    }
    friend const modint operator/(modint lhs, const modint& rhs) {
        return lhs /= rhs;
    }

    const modint pow(int64_t n) const {
        modint ret = 1, tmp = *this;
        while (n) {
            if (n & 1) ret *= tmp;
            tmp *= tmp; n >>= 1;
        }
        return ret;
    }

    friend bool operator==(const modint& lhs, const modint& rhs) {
        return lhs.x == rhs.x;
    }
    friend bool operator!=(const modint& lhs, const modint& rhs) {
        return !(lhs == rhs);
    }

    friend ostream& operator<<(ostream& os, const modint& a) {
        return os << a.x;
    }
    friend istream& operator>>(istream& is, modint& a) {
        int64_t tmp; is >> tmp; a = tmp;
        return is;
    }
};

