#include "../template.cpp"

#define SNIPPET_ONLY

template<typename Field>
struct Combination {
    int _n = 1;
    vector<Field> _fact{1}, _rfact{1}, _inv{1};

    void extend(int n) {
        _fact.resize(n);
        _rfact.resize(n);
        _inv.resize(n);
        for (int i = _n; i < n; ++i) _fact[i] = _fact[i - 1] * i;
        _rfact[n - 1] = 1 / _fact[n - 1];
        for (int i = n - 1; i > _n; --i) _rfact[i - 1] = _rfact[i] * i;
        for (int i = _n; i < n; ++i) _inv[i] = _rfact[i] * _fact[i - 1];
        _n = n;
    }

    Field fact(int k) {
        if (_n <= k) extend(k + 1);
        return _fact.at(k);
    }

    Field rfact(int k) {
        if (_n <= k) extend(k + 1);
        return _rfact.at(k);
    }

    Field inv(int k) {
        assert(k != 0);
        if (_n <= k) extend(k + 1);
        return _inv.at(k);
    }

    Field P(int n, int r) {
        if (r < 0 or n < r) return 0;
        return fact(n) * rfact(n - r);
    }

    Field C(int n, int r) {
        if (r < 0 or n < r) return 0;
        return fact(n) * rfact(r) * rfact(n - r);
    }

    Field H(int n, int r) {
        return (n == 0 and r == 0) ? 1 : C(n + r - 1, r);
    }
};

