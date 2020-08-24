#include "../template.cpp"

#define SNIPPET_ONLY

template<typename Field>
struct Combination {
    vector<Field> _fact, _rfact, _inv;

    Combination(int n) : _fact(n), _rfact(n), _inv(n) {
        _fact[0] = _rfact[n-1] = 1;
        for (int i = 1; i < n; ++i) _fact[i] = _fact[i-1] * i;
        _rfact[n-1] /= _fact[n-1];
        for (int i = n-1; i > 0; --i) _rfact[i-1] = _rfact[i] * i;
        for (int i = 1; i < n; ++i) _inv[i] = _rfact[i] * _fact[i-1];
    }

    inline Field fact(int k) const { return _fact.at(k); }

    inline Field rfact(int k) const { return _rfact.at(k); }

    inline Field inv(int k) const { assert(k != 0); return _inv.at(k); }

    Field P(int n, int r) const {
        if (r < 0 or n < r) return 0;
        return fact(n) * rfact(n-r);
    }

    Field C(int n, int r) const {
        if (r < 0 or n < r) return 0;
        return fact(n) * rfact(r) * rfact(n-r);
    }

    Field H (int n, int r) const {
        return (n == 0 and r == 0) ? 1 : C(n+r-1, r);
    }
};

