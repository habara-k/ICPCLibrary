---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/number/mint.cpp
    title: lib/number/mint.cpp
  - icon: ':heavy_check_mark:'
    path: lib/number/ntt.cpp
    title: NTT
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/number/fps/exp.test.cpp
    title: test/number/fps/exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/fps/inv.test.cpp
    title: test/number/fps/inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/fps/log.test.cpp
    title: test/number/fps/log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/fps/pow.test.cpp
    title: test/number/fps/pow.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
    links:
    - https://ei1333.github.io/luzhiled/snippets/math/formal-power-series.html
  bundledCode: "#line 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\n#define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i,\
    \ n) for (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n);\
    \ ++i)\n#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x)\
    \ ((int)(x).size())\n#define ALL(x) (x).begin(),(x).end()\n\n#define DUMP(x) cerr<<#x<<\"\
    \ = \"<<(x)<<endl\n#define DEBUG(x) cerr<<#x<<\" = \"<<(x)<<\" (L\"<<__LINE__<<\"\
    )\"<<endl;\n\ntemplate<class T>\nostream &operator<<(ostream &os, const vector\
    \ <T> &v) {\n    os << \"[\";\n    REP(i, SZ(v)) {\n        if (i) os << \", \"\
    ;\n        os << v[i];\n    }\n    return os << \"]\";\n}\n\ntemplate<class T,\
    \ class U>\nostream &operator<<(ostream &os, const pair <T, U> &p) {\n    return\
    \ os << \"(\" << p.first << \" \" << p.second << \")\";\n}\n\ntemplate<class T>\n\
    bool chmax(T &a, const T &b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ntemplate<class T>\nbool chmin(T &a, const\
    \ T &b) {\n    if (b < a) {\n        a = b;\n        return true;\n    }\n   \
    \ return false;\n}\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\nusing P = pair<int, int>;\nusing vi = vector<int>;\n\
    using vll = vector<ll>;\nusing vvi = vector<vi>;\nusing vvll = vector<vll>;\n\n\
    const ll MOD = 1e9 + 7;\nconst int INF = INT_MAX / 2;\nconst ll LINF = LLONG_MAX\
    \ / 2;\nconst ld eps = 1e-9;\n\n/*\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(10);\n\n    // ifstream in(\"in.txt\");\n \
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/mint.cpp\"\
    \n\ntemplate<int m>\nstruct mint {\n    int x;\n    mint(int x = 0) : x(((x %\
    \ m) + m) % m) {}\n    mint operator-() { return x ? m-x : 0; }\n    mint &operator+=(mint\
    \ r) {\n        if ((x += r.x) >= m) x -= m;\n        return *this;\n    }\n \
    \   mint &operator-=(mint r) {\n        if ((x -= r.x) < 0) x += m;\n        return\
    \ *this;\n    }\n    mint &operator*=(mint r) {\n        x = ((ll)x * r.x) % m;\n\
    \        return *this;\n    }\n    mint inv() {\n        int a = x, b = m, u =\
    \ 1, v = 0, t;\n        while (b > 0) {\n            t = a / b;\n            swap(a\
    \ -= t * b, b);\n            swap(u -= t * v, v);\n        }\n        return u;\n\
    \    }\n    mint &operator/=(mint r) { return *this *= r.inv(); }\n\n    friend\
    \ mint operator+(mint l, mint r) { return l += r; }\n    friend mint operator-(mint\
    \ l, mint r) { return l -= r; }\n    friend mint operator*(mint l, mint r) { return\
    \ l *= r; }\n    friend mint operator/(mint l, mint r) { return l /= r; }\n  \
    \  mint pow(ll n) {\n        mint ret = 1, tmp = *this;\n        while (n) {\n\
    \            if (n & 1) ret *= tmp;\n            tmp *= tmp, n >>= 1;\n      \
    \  }\n        return ret;\n    }\n    friend bool operator==(mint l, mint r) {\
    \ return l.x == r.x; }\n    friend bool operator!=(mint l, mint r) { return l.x\
    \ != r.x; }\n    friend ostream &operator<<(ostream &os, mint a) {\n        return\
    \ os << a.x;\n    }\n    friend istream &operator>>(istream &is, mint& a) {\n\
    \        int x; is >> x; a = x; return is;\n    }\n};\n#line 2 \"lib/number/ntt.cpp\"\
    \n\n/*\n * @brief NTT\n * @author habara-k\n * @usage\n *   vector<NTT<>::Int>\
    \ a, b;\n *   NTT<> ntt;\n *   auto c = ntt.multiply(a, b);\n * \u6709\u540D\u306A\
    mod, root\u306E\u7D44\n * 998244353, 3\n * 163577857, 23\n * 167772161, 3\n *\
    \ 469762049, 3\n */\ntemplate<int mod=998244353, int root=3>\nstruct NTT {\n \
    \   using Int = mint<mod>;\n    int n;\n    Int r;\n    void ensure(int need)\
    \ {\n        n = 1;\n        while (n < need) n <<= 1;\n        r = Int{root}.pow((mod-1)\
    \ / n);\n    }\n\n    vector<Int> multiply(vector<Int> a, vector<Int> b) {\n \
    \       int need = SZ(a) + SZ(b) - 1;\n        ensure(need);\n        ntt(a);\n\
    \        ntt(b);\n        REP(i, n) (a[i] *= b[i]) /= n;\n        reverse(a.begin()\
    \ + 1, a.end());\n        ntt(a); a.resize(need);\n        return a;\n    }\n\n\
    \    void ntt(vector<Int>& a) {\n        a.resize(n);\n        int p = 0;\n  \
    \      FOR(i, 1, n-1) {\n            for (int k = n >> 1; k > (p ^= k); k >>=\
    \ 1);\n            if (i < p) swap(a[i], a[p]);\n        }\n        for (int k\
    \ = 1; k < n; k <<= 1) {\n            Int base = r.pow(n / (2*k));\n         \
    \   Int z = 1;\n            REP(j, k) {\n                for (int i = j; i < n;\
    \ i += 2*k) {\n                    Int v = a[i+k] * z;\n                    a[i+k]\
    \ = a[i] - v;\n                    a[i] += v;\n                }\n           \
    \     z *= base;\n            }\n        }\n    }\n};\n\n#line 4 \"lib/number/fps.cpp\"\
    \n\n/*\n * @brief \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @ref https://ei1333.github.io/luzhiled/snippets/math/formal-power-series.html\n\
    \ * @author habara-k\n * @date 2020/10/23\n * @details\n * \u591A\u9805\u5F0F\u306E\
    \u7D2F\u4E57\u304CO(nlog n)\u3067\u3067\u304D\u308B\u6700\u4F4E\u9650\u306E\u5B9F\
    \u88C5\u306B\u3057\u3066\u3042\u308B\n * @usage\n *     vector<FPS<>::Int> a(n);\n\
    \ *     REP(i, n) cin >> a[i];\n *     auto ans = FPS(a).pow(m).a;\n */\ntemplate<int\
    \ mod=998244353, int root=3>\nstruct FPS {\n    using Int = mint<mod>;\n    int\
    \ n=0;\n    vector<Int> a;\n    FPS(const vector<Int>& a) : n(a.size()), a(a)\
    \ {}\n\n    FPS& operator+=(Int x) {\n        a[0] += x;\n        return *this;\n\
    \    }\n    FPS operator+(Int x) const {\n        return FPS(*this) += x;\n  \
    \  }\n    FPS& operator*=(Int x) {\n        REP(i, n) a[i] *= x;\n        return\
    \ *this;\n    }\n    FPS operator*(Int x) const {\n        return FPS(*this) *=\
    \ x;\n    }\n\n    FPS& operator+=(const FPS& r) {\n        if (chmax(n, r.n))\
    \ a.resize(n);\n        REP(i, r.n) a[i] += r.a[i];\n        return *this;\n \
    \   }\n    FPS operator-() const {\n        vector<Int> ret = a;\n        REP(i,\
    \ n) ret[i] = -ret[i];\n        return ret;\n    }\n    FPS& operator-=(const\
    \ FPS& r) {\n        if (chmax(n, r.n)) a.resize(n);\n        REP(i, r.n) a[i]\
    \ -= r.a[i];\n        return *this;\n    }\n    FPS operator+(const FPS& r) const\
    \ {\n        return FPS(a) += r;\n    }\n    FPS operator-(const FPS& r) const\
    \ {\n        return FPS(a) -= r;\n    }\n\n    FPS operator*(const FPS& r) const\
    \ {\n        return NTT<mod,root>().multiply(a, r.a);\n    }\n\n    FPS pre(int\
    \ sz) const {\n        return FPS({a.begin(), a.begin() + min(sz,n)});\n    }\n\
    \    FPS diff() const {\n        if (n == 0) return *this;\n        vector<Int>\
    \ ret(n-1);\n        FOR(i, 1, n) ret[i-1] = a[i] * i;\n        return ret;\n\
    \    }\n    FPS integral() const {\n        vector<Int> ret(n+1);\n        REP(i,\
    \ n) ret[i+1] = a[i] / (i+1);\n        return ret;\n    }\n    FPS inv(int deg\
    \ = -1) const {\n        assert(!a.empty() and a.at(0) != 0);\n        FPS ret({1\
    \ / a[0]});\n        if (deg == -1) deg = n;\n        for (int i = 1; i < deg;\
    \ i<<=1) {\n            ret = (ret * 2 - ret * ret * pre(i<<1)).pre(i<<1);\n \
    \       }\n        return ret.pre(deg);\n    }\n    FPS log(int deg = -1) const\
    \ {\n        assert(!a.empty() and a.at(0) == 1);\n        if (deg == -1) deg\
    \ = n;\n        return (diff() * inv(deg)).pre(deg-1).integral();\n    }\n   \
    \ FPS exp(int deg = -1) const {\n        assert(!a.empty() and a.at(0) == 0);\n\
    \        if (deg == -1) deg = n;\n        FPS ret({1});\n        for (int i =\
    \ 1; i < deg; i<<=1) {\n            ret = (ret * (pre(i<<1) + 1 - ret.log(i<<1))).pre(i<<1);\n\
    \        }\n        return ret.pre(deg);\n    }\n    FPS pow(ll k, int deg = -1)\
    \ {\n        if (deg == -1) deg = n;\n        REP(i, n) {\n            if (a[i]\
    \ == 0) continue;\n            vector<Int> ret(deg);\n            if (i * k >=\
    \ deg) return ret;\n            FPS C = ((FPS({a.begin() + i, a.end()}) * a[i].inv()).log()\
    \ * k).exp() * a[i].pow(k);\n            for (int j = 0; j + i * k < deg and j\
    \ < C.n; ++j) {\n                ret[j + i * k] = C.a[j];\n            }\n   \
    \         return ret;\n        }\n        return *this;\n    }\n};\n\n"
  code: "#include \"../template.cpp\"\n#include \"mint.cpp\"\n#include \"ntt.cpp\"\
    \n\n/*\n * @brief \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @ref https://ei1333.github.io/luzhiled/snippets/math/formal-power-series.html\n\
    \ * @author habara-k\n * @date 2020/10/23\n * @details\n * \u591A\u9805\u5F0F\u306E\
    \u7D2F\u4E57\u304CO(nlog n)\u3067\u3067\u304D\u308B\u6700\u4F4E\u9650\u306E\u5B9F\
    \u88C5\u306B\u3057\u3066\u3042\u308B\n * @usage\n *     vector<FPS<>::Int> a(n);\n\
    \ *     REP(i, n) cin >> a[i];\n *     auto ans = FPS(a).pow(m).a;\n */\ntemplate<int\
    \ mod=998244353, int root=3>\nstruct FPS {\n    using Int = mint<mod>;\n    int\
    \ n=0;\n    vector<Int> a;\n    FPS(const vector<Int>& a) : n(a.size()), a(a)\
    \ {}\n\n    FPS& operator+=(Int x) {\n        a[0] += x;\n        return *this;\n\
    \    }\n    FPS operator+(Int x) const {\n        return FPS(*this) += x;\n  \
    \  }\n    FPS& operator*=(Int x) {\n        REP(i, n) a[i] *= x;\n        return\
    \ *this;\n    }\n    FPS operator*(Int x) const {\n        return FPS(*this) *=\
    \ x;\n    }\n\n    FPS& operator+=(const FPS& r) {\n        if (chmax(n, r.n))\
    \ a.resize(n);\n        REP(i, r.n) a[i] += r.a[i];\n        return *this;\n \
    \   }\n    FPS operator-() const {\n        vector<Int> ret = a;\n        REP(i,\
    \ n) ret[i] = -ret[i];\n        return ret;\n    }\n    FPS& operator-=(const\
    \ FPS& r) {\n        if (chmax(n, r.n)) a.resize(n);\n        REP(i, r.n) a[i]\
    \ -= r.a[i];\n        return *this;\n    }\n    FPS operator+(const FPS& r) const\
    \ {\n        return FPS(a) += r;\n    }\n    FPS operator-(const FPS& r) const\
    \ {\n        return FPS(a) -= r;\n    }\n\n    FPS operator*(const FPS& r) const\
    \ {\n        return NTT<mod,root>().multiply(a, r.a);\n    }\n\n    FPS pre(int\
    \ sz) const {\n        return FPS({a.begin(), a.begin() + min(sz,n)});\n    }\n\
    \    FPS diff() const {\n        if (n == 0) return *this;\n        vector<Int>\
    \ ret(n-1);\n        FOR(i, 1, n) ret[i-1] = a[i] * i;\n        return ret;\n\
    \    }\n    FPS integral() const {\n        vector<Int> ret(n+1);\n        REP(i,\
    \ n) ret[i+1] = a[i] / (i+1);\n        return ret;\n    }\n    FPS inv(int deg\
    \ = -1) const {\n        assert(!a.empty() and a.at(0) != 0);\n        FPS ret({1\
    \ / a[0]});\n        if (deg == -1) deg = n;\n        for (int i = 1; i < deg;\
    \ i<<=1) {\n            ret = (ret * 2 - ret * ret * pre(i<<1)).pre(i<<1);\n \
    \       }\n        return ret.pre(deg);\n    }\n    FPS log(int deg = -1) const\
    \ {\n        assert(!a.empty() and a.at(0) == 1);\n        if (deg == -1) deg\
    \ = n;\n        return (diff() * inv(deg)).pre(deg-1).integral();\n    }\n   \
    \ FPS exp(int deg = -1) const {\n        assert(!a.empty() and a.at(0) == 0);\n\
    \        if (deg == -1) deg = n;\n        FPS ret({1});\n        for (int i =\
    \ 1; i < deg; i<<=1) {\n            ret = (ret * (pre(i<<1) + 1 - ret.log(i<<1))).pre(i<<1);\n\
    \        }\n        return ret.pre(deg);\n    }\n    FPS pow(ll k, int deg = -1)\
    \ {\n        if (deg == -1) deg = n;\n        REP(i, n) {\n            if (a[i]\
    \ == 0) continue;\n            vector<Int> ret(deg);\n            if (i * k >=\
    \ deg) return ret;\n            FPS C = ((FPS({a.begin() + i, a.end()}) * a[i].inv()).log()\
    \ * k).exp() * a[i].pow(k);\n            for (int j = 0; j + i * k < deg and j\
    \ < C.n; ++j) {\n                ret[j + i * k] = C.a[j];\n            }\n   \
    \         return ret;\n        }\n        return *this;\n    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  - lib/number/mint.cpp
  - lib/number/ntt.cpp
  isVerificationFile: false
  path: lib/number/fps.cpp
  requiredBy: []
  timestamp: '2020-10-23 18:09:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/fps/pow.test.cpp
  - test/number/fps/exp.test.cpp
  - test/number/fps/inv.test.cpp
  - test/number/fps/log.test.cpp
documentation_of: lib/number/fps.cpp
layout: document
redirect_from:
- /library/lib/number/fps.cpp
- /library/lib/number/fps.cpp.html
title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
---
