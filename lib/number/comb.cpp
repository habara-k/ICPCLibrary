#include "../template.cpp"

#define SNIPPET_ONLY

template<typename T>
struct Combination {
    int _n = 1;
    vector<T> _fact{1}, _rfact{1};

    void extend(int n) {
        if (n <= _n) return;
        _fact.resize(n);
        _rfact.resize(n);
        for (int i = _n; i < n; ++i) _fact[i] = _fact[i - 1] * i;
        _rfact[n - 1] = 1 / _fact[n - 1];
        for (int i = n - 1; i > _n; --i) _rfact[i - 1] = _rfact[i] * i;
        _n = n;
    }

    T fact(int k) {
        extend(k + 1);
        return _fact.at(k);
    }

    T rfact(int k) {
        extend(k + 1);
        return _rfact.at(k);
    }

    T P(int n, int r) {
        if (r < 0 or n < r) return 0;
        return fact(n) * rfact(n - r);
    }

    T C(int n, int r) {
        if (r < 0 or n < r) return 0;
        return fact(n) * rfact(r) * rfact(n - r);
    }

    T H(int n, int r) {
        return (n == 0 and r == 0) ? 1 : C(n + r - 1, r);
    }

    // O(k logn)
    // スターリング数
    // Stirling(n, k) := n 個の区別できるボールを k 個の区別できない箱にいれる場合の数
    //                   それぞれの箱には少なくとも一つボールをいれる
    T Stirling(ll n, int k) {
        T ret = 0;
        for (int l = 0; l <= k; ++l) {
            ret += C(k, l) * T{k-l}.pow(n) * (l & 1 ? -1 : 1);
        }
        return ret / fact(k);
    }

    // O(k^2 logn)
    // ベル数
    // Bell(n, k) := n 個の区別できるボールを k 個の区別できない箱にいれる場合の数
    T Bell(ll n, int k) {
        T ret = 0;
        for (int l = 0; l <= k; ++l) {
            ret += Stirling(n, l);
        }
        return ret;
    }

};


// O(kn)
// Partition[k][n] := n 個の区別できないボールを k 個の区別できない箱にいれる場合の数
template<typename T>
vector<vector<T>> Partition(int k, int n) {
    vector<vector<T>> ret(k+1, vector<T>(n+1));
    ret[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j-i >= 0) {
                ret[i][j] = ret[i-1][j] + ret[i][j-i];
            } else {
                ret[i][j] = ret[i-1][j];
            }
        }
    }
    return ret;
}

// O(n)
// Montmort[n] := 1, ..., n の撹乱順列の総数(n > 0)
template<typename T>
vector<T> Montmort(int n) {
    vector<T> ret(n+1);
    ret[2] = 1;
    for (int k = 3; k <= n; ++k) {
        ret[k] = (k-1) * (ret[k-1] + ret[k-2]);
    }
    return ret;
}
