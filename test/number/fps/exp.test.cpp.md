---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/fps.cpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':heavy_check_mark:'
    path: lib/number/mint.cpp
    title: lib/number/mint.cpp
  - icon: ':heavy_check_mark:'
    path: lib/number/ntt.cpp
    title: NTT
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_formal_power_series
  bundledCode: "#line 1 \"test/number/fps/exp.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\
    \n\n#line 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i, n) for\
    \ (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n); ++i)\n\
    #define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n\
    #define ALL(x) (x).begin(),(x).end()\n\n#define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\
    #define DEBUG(x) cerr<<#x<<\" = \"<<(x)<<\" (L\"<<__LINE__<<\")\"<<endl;\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const vector <T> &v) {\n    os << \"[\"\
    ;\n    REP(i, SZ(v)) {\n        if (i) os << \", \";\n        os << v[i];\n  \
    \  }\n    return os << \"]\";\n}\n\ntemplate<class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair <T, U> &p) {\n    return os << \"(\" << p.first << \" \" <<\
    \ p.second << \")\";\n}\n\ntemplate<class T>\nbool chmax(T &a, const T &b) {\n\
    \    if (a < b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ntemplate<class T>\nbool chmin(T &a, const T &b) {\n    if (b < a) {\n   \
    \     a = b;\n        return true;\n    }\n    return false;\n}\n\nusing ll =\
    \ long long;\nusing ull = unsigned long long;\nusing ld = long double;\nusing\
    \ P = pair<int, int>;\nusing vi = vector<int>;\nusing vll = vector<ll>;\nusing\
    \ vvi = vector<vi>;\nusing vvll = vector<vll>;\n\nconst ll MOD = 1e9 + 7;\nconst\
    \ int INF = INT_MAX / 2;\nconst ll LINF = LLONG_MAX / 2;\nconst ld eps = 1e-9;\n\
    \n/*\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    cout\
    \ << fixed << setprecision(10);\n\n    // ifstream in(\"in.txt\");\n    // cin.rdbuf(in.rdbuf());\n\
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/mint.cpp\"\n\ntemplate<int m>\n\
    struct mint {\n    int x;\n    mint(ll x = 0) : x(((x % m) + m) % m) {}\n    mint\
    \ operator-() const { return x ? m-x : 0; }\n    mint &operator+=(mint r) {\n\
    \        if ((x += r.x) >= m) x -= m;\n        return *this;\n    }\n    mint\
    \ &operator-=(mint r) {\n        if ((x -= r.x) < 0) x += m;\n        return *this;\n\
    \    }\n    mint &operator*=(mint r) {\n        x = ((ll)x * r.x) % m;\n     \
    \   return *this;\n    }\n    mint inv() const { return pow(m-2); }\n    mint\
    \ &operator/=(mint r) { return *this *= r.inv(); }\n\n    friend mint operator+(mint\
    \ l, mint r) { return l += r; }\n    friend mint operator-(mint l, mint r) { return\
    \ l -= r; }\n    friend mint operator*(mint l, mint r) { return l *= r; }\n  \
    \  friend mint operator/(mint l, mint r) { return l /= r; }\n    mint pow(ll n)\
    \ const {\n        mint ret = 1, tmp = *this;\n        while (n) {\n         \
    \   if (n & 1) ret *= tmp;\n            tmp *= tmp, n >>= 1;\n        }\n    \
    \    return ret;\n    }\n    friend bool operator==(mint l, mint r) { return l.x\
    \ == r.x; }\n    friend bool operator!=(mint l, mint r) { return l.x != r.x; }\n\
    \    friend ostream &operator<<(ostream &os, mint a) {\n        return os << a.x;\n\
    \    }\n    friend istream &operator>>(istream &is, mint& a) {\n        ll x;\
    \ is >> x; a = x; return is;\n    }\n};\n\n#line 2 \"lib/number/ntt.cpp\"\n\n\
    /*\n * @brief NTT\n * @ref https://ei1333.github.io/library/math/fft/number-theoretic-transform-friendly-mod-int.cpp\n\
    \ * @author habara-k\n * @usage\n *   vector<NTT<>::Int> a, b;\n *   auto c =\
    \ NTT<>::multiply(a, b);\n *\n * root\u306E\u63A2\u7D22\n * int root = 2;\n *\
    \ while (Int{root}.pow((mod-1)/2) == 1) ++root;\n */\ntemplate<int mod = 998244353,\
    \ int root = 3>\nstruct NTT {\n    using Int = mint<mod>;\n    constexpr static\
    \ int sz = __builtin_ctz(mod-1);\n\n    static void ntt(vector<Int> &a) {\n  \
    \      const int n = (int) a.size();\n        assert((n & (n - 1)) == 0);\n  \
    \      assert(__builtin_ctz(n) <= sz);\n        Int dw[sz];\n        REP(i, sz)\
    \ {\n            dw[i] = -Int{root}.pow((mod-1) >> (i+2));\n        }\n      \
    \  for (int m = n; m >>= 1;) {\n            Int w = 1;\n            for (int s\
    \ = 0, k = 0; s < n; s += 2 * m) {\n                for (int i = s, j = s + m;\
    \ i < s + m; ++i, ++j) {\n                    auto x = a[i], y = a[j] * w;\n \
    \                   a[i] = x + y, a[j] = x - y;\n                }\n         \
    \       w *= dw[__builtin_ctz(++k)];\n            }\n        }\n    }\n\n    static\
    \ void intt(vector<Int> &a) {\n        const int n = (int) a.size();\n       \
    \ assert((n & (n - 1)) == 0);\n        assert(__builtin_ctz(n) <= sz);\n     \
    \   Int idw[sz];\n        REP(i, sz) {\n            idw[i] = (-Int{root}.pow((mod-1)\
    \ >> (i+2))).inv();\n        }\n        for (int m = 1; m < n; m *= 2) {\n   \
    \         Int w = 1;\n            for (int s = 0, k = 0; s < n; s += 2 * m) {\n\
    \                for (int i = s, j = s + m; i < s + m; ++i, ++j) {\n         \
    \           auto x = a[i], y = a[j];\n                    a[i] = x + y, a[j] =\
    \ (x - y) * w;\n                }\n                w *= idw[__builtin_ctz(++k)];\n\
    \            }\n        }\n        Int inv_n = Int{n}.inv();\n        REP(i, n)\
    \ a[i] *= inv_n;\n    }\n\n    static vector<Int> multiply(vector<Int> a, vector<Int>\
    \ b) {\n        int need = SZ(a) + SZ(b) - 1;\n        int n = 1;\n        while\
    \ (n < need) n <<= 1;\n        a.resize(n);\n        b.resize(n);\n        ntt(a);\n\
    \        ntt(b);\n        REP(i, n) a[i] *= b[i];\n        intt(a);\n        a.resize(need);\n\
    \        return a;\n    }\n};\n\n#line 4 \"lib/number/fps.cpp\"\n\n/*\n * @brief\
    \ \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @ref https://ei1333.github.io/library/math/fps/formal-power-series.cpp\n\
    \ * @author habara-k\n * @date 2020/10/23\n * @details\n * \u591A\u9805\u5F0F\u306E\
    \u7D2F\u4E57\u304CO(nlog n)\u3067\u3067\u304D\u308B\u6700\u4F4E\u9650\u306E\u5B9F\
    \u88C5\u306B\u3057\u3066\u3042\u308B\n * @usage\n *     vector<FPS<>::Int> a(n);\n\
    \ *     REP(i, n) cin >> a[i];\n *     auto ans = FPS<>(a).pow(m).a;\n */\ntemplate<int\
    \ mod = 998244353, int root = 3>\nstruct FPS {\n    using Int = mint<mod>;\n \
    \   int n = 0;\n    vector<Int> a;\n\n    FPS(const vector<Int> &a) : n(a.size()),\
    \ a(a) {}\n\n    FPS &operator*=(Int x) {\n        REP(i, n) a[i] *= x;\n    \
    \    return *this;\n    }\n\n    FPS operator*(Int x) const {\n        return\
    \ FPS(*this) *= x;\n    }\n\n    FPS operator*(const FPS &r) const {\n       \
    \ return NTT<mod,root>::multiply(a, r.a);\n    }\n\n    static void ntt(vector<Int>&\
    \ F) {\n        NTT<mod,root>::ntt(F);\n    }\n\n    static void intt(vector<Int>&\
    \ F) {\n        NTT<mod,root>::intt(F);\n    }\n\n    FPS pre(int sz) const {\n\
    \        return FPS({a.begin(), a.begin() + min(sz, n)});\n    }\n\n    FPS diff()\
    \ const {\n        if (n == 0) return *this;\n        vector<Int> ret(n - 1);\n\
    \        FOR(i, 1, n) ret[i - 1] = a[i] * i;\n        return ret;\n    }\n\n \
    \   FPS integral() const {\n        vector<Int> ret(n + 1);\n        REP(i, n)\
    \ ret[i + 1] = a[i] / (i + 1);\n        return ret;\n    }\n\n    FPS inv(int\
    \ deg = -1) const {\n        assert(!a.empty() and a[0] != 0);\n        if (deg\
    \ == -1) deg = n;\n        vector<Int> ret{a[0].inv()};\n        for (int d =\
    \ 1; d < n; d <<= 1) {\n            vector<Int> f(2 * d), g(2 * d);\n        \
    \    REP(j, min(n, 2*d)) f[j] = a[j];\n            REP(j, d) g[j] = ret[j];\n\
    \            ntt(f);\n            ntt(g);\n            REP(j, 2*d) f[j] *= g[j];\n\
    \            intt(f);\n            REP(j, d) f[j] = 0, f[j+d] = -f[j+d];\n   \
    \         ntt(f);\n            REP(j, 2*d) f[j] *= g[j];\n            intt(f);\n\
    \            REP(j, d) f[j] = ret[j];\n            ret = f;\n        }\n     \
    \   return FPS(ret).pre(n);\n    }\n\n    FPS log(int deg = -1) const {\n    \
    \    assert(!a.empty() and a[0] == 1);\n        if (deg == -1) deg = n;\n    \
    \    return (diff() * inv(deg)).pre(deg - 1).integral();\n    }\n\n    FPS exp(int\
    \ deg = -1) const {\n        assert(a.empty() or a[0] == 0);\n        if (deg\
    \ == -1) deg = n;\n        auto inplace_integral = [&](vector<Int>& F) -> void\
    \ {\n            F.insert(F.begin(), 0);\n            FOR(i, 1, SZ(F)) F[i] /=\
    \ i;\n        };\n\n        auto inplace_diff = [](vector<Int>& F) -> void {\n\
    \            if (F.empty()) return;\n            F.erase(F.begin());\n       \
    \     REP(i, SZ(F)) F[i] *= i+1;\n        };\n\n        vector<Int> b{1, n > 1\
    \ ? a[1] : 0}, c{1}, z1, z2{1, 1};\n        for (int m = 2; m < deg; m *= 2) {\n\
    \            auto y = b;\n            y.resize(2 * m);\n            ntt(y);\n\
    \            z1 = z2;\n            vector<Int> z(m);\n            REP(i, m) z[i]\
    \ = y[i] * z1[i];\n            intt(z);\n            fill(z.begin(), z.begin()\
    \ + m / 2, 0);\n            ntt(z);\n            REP(i, m) z[i] *= -z1[i];\n \
    \           intt(z);\n            c.insert(c.end(), z.begin() + m / 2, z.end());\n\
    \            z2 = c;\n            z2.resize(2 * m);\n            ntt(z2);\n  \
    \          vector<Int> x(a.begin(), a.begin() + min(n, m));\n            inplace_diff(x);\n\
    \            x.emplace_back(0);\n            ntt(x);\n            REP(i, m) x[i]\
    \ *= y[i];\n            intt(x);\n            REP(i, m-1) x[i] -= b[i+1] * (i+1);\n\
    \            x.resize(2 * m);\n            REP(i, m-1) x[m+i] = x[i], x[i] = 0;\n\
    \            ntt(x);\n            REP(i, 2*m) x[i] *= z2[i];\n            intt(x);\n\
    \            x.pop_back();\n            inplace_integral(x);\n            FOR(i,\
    \ m, min(n, 2*m)) x[i] += a[i];\n            fill(x.begin(), x.begin() + m, 0);\n\
    \            ntt(x);\n            REP(i, 2*m) x[i] *= y[i];\n            intt(x);\n\
    \            b.insert(b.end(), x.begin() + m, x.end());\n        }\n        return\
    \ FPS({b.begin(), b.begin() + deg});\n    }\n\n    FPS pow(ll k, int deg = -1)\
    \ {\n        if (deg == -1) deg = n;\n        REP(i, n) {\n            if (a[i]\
    \ == 0) continue;\n            vector<Int> ret(deg);\n            if (i * k >=\
    \ deg) return ret;\n            FPS C = ((FPS({a.begin() + i, a.end()}) * a[i].inv()).log()\
    \ * k).exp() * a[i].pow(k);\n            for (int j = 0; j + i * k < deg and j\
    \ < C.n; ++j) {\n                ret[j + i * k] = C.a[j];\n            }\n   \
    \         return ret;\n        }\n        return *this;\n    }\n};\n\n#line 4\
    \ \"test/number/fps/exp.test.cpp\"\n\nint main() {\n    int n; cin >> n;\n   \
    \ vector<FPS<>::Int> a(n);\n    REP(i, n) cin >> a[i];\n    auto ans = FPS<>(a).exp().a;\n\
    \    REP(i, n) {\n        if (i) cout << ' ';\n        cout << ans[i];\n    }\n\
    \    cout << endl;\n\n    return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\
    \n\n#include \"../../../lib/number/fps.cpp\"\n\nint main() {\n    int n; cin >>\
    \ n;\n    vector<FPS<>::Int> a(n);\n    REP(i, n) cin >> a[i];\n    auto ans =\
    \ FPS<>(a).exp().a;\n    REP(i, n) {\n        if (i) cout << ' ';\n        cout\
    \ << ans[i];\n    }\n    cout << endl;\n\n    return 0;\n}\n\n"
  dependsOn:
  - lib/number/fps.cpp
  - lib/template.cpp
  - lib/number/mint.cpp
  - lib/number/ntt.cpp
  isVerificationFile: true
  path: test/number/fps/exp.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 19:29:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/fps/exp.test.cpp
layout: document
redirect_from:
- /verify/test/number/fps/exp.test.cpp
- /verify/test/number/fps/exp.test.cpp.html
title: test/number/fps/exp.test.cpp
---
