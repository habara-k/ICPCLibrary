---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7573\u307F\u8FBC\u307F\u306E\u5B9F\u884C. O(nlog n)"
    links:
    - https://atcoder.jp/contests/atc001/submissions/15125563
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/ntt.cpp\"\
    \n\n/**\n * @brief\n * Number Theoretic Transform\n * @author habara-k\n * @date\
    \ 2020/07/11\n * @verify https://atcoder.jp/contests/atc001/submissions/15125563\n\
    \ */\n\ntemplate<ll mod=998244353, ll primitive=3>\nstruct NTT {\n\n    /**\n\
    \    * @brief \u7573\u307F\u8FBC\u307F\u306E\u5B9F\u884C. O(nlog n)\n    * @require\
    \ n <= 2^23\n    * @param[in] a, b: \u7573\u307F\u8FBC\u307F\u305F\u3044\u914D\
    \u5217\n    * @return \u7573\u307F\u8FBC\u307F\u3057\u305F\u7D50\u679C\n    *\
    \ @usage\n    *   vector<ll> a(2*n+1), b(2*n+1);\n    *   vector<ll> c = NTT<>::multiply(a,\
    \ b);\n    */\n    static vector<ll> multiply(const vector<ll>& a, const vector<ll>&\
    \ b) {\n        auto A = NTT(a).solve();\n        auto B = NTT(b).solve();\n\n\
    \        vector<ll> C(A.size());\n        REP(i, C.size()) C[i] = (A[i] * B[i])\
    \ % 998244353;\n\n        return NTT(C).solve(true);\n    }\n\nprivate:\n    int\
    \ n;\n    vector<ll> a;\n    ll inv_n, root, inv_root;\n\n    NTT(const vector<ll>&\
    \ a) : n(1), a(a) {\n        while (n < a.size()) n <<= 1;\n        this->a.resize(n);\n\
    \        inv_n = modpow(n, mod-2);\n        root = modpow(primitive, (mod-1) /\
    \ n);\n        inv_root = modpow(root, mod-2);\n    }\n\n    vector<ll> solve(bool\
    \ inverse = false) {\n        return ntt(0, 0, inverse, inverse ? inv_root : root);\n\
    \    }\n\n    vector<ll> ntt(int d, int bit, bool inverse, ll base) {\n      \
    \  int sz = n >> d;\n        if (sz == 1) return {(a[bit] * (inverse ? inv_n :\
    \ 1)) % mod};\n\n        auto f0 = ntt(d+1, bit, inverse, (base * base) % mod);\n\
    \        auto f1 = ntt(d+1, bit | 1<<d, inverse, (base * base) % mod);\n     \
    \   vector<ll> f(sz);\n        ll tmp = 1;\n        for (int i = 0; i < sz; ++i)\
    \ {\n            f[i] = (f0[i % (sz / 2)] + tmp * f1[i % (sz / 2)]) % mod;\n \
    \           (tmp *= base) %= mod;\n        }\n        return f;\n    }\n\n   \
    \ ll modpow(ll a, ll p) {\n        ll ret = 1;\n        while (p) {\n        \
    \    if (p & 1) (ret *= a) %= mod;\n            (a *= a) %= mod;\n           \
    \ p >>= 1;\n        }\n        return ret;\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief\n * Number Theoretic Transform\n\
    \ * @author habara-k\n * @date 2020/07/11\n * @verify https://atcoder.jp/contests/atc001/submissions/15125563\n\
    \ */\n\ntemplate<ll mod=998244353, ll primitive=3>\nstruct NTT {\n\n    /**\n\
    \    * @brief \u7573\u307F\u8FBC\u307F\u306E\u5B9F\u884C. O(nlog n)\n    * @require\
    \ n <= 2^23\n    * @param[in] a, b: \u7573\u307F\u8FBC\u307F\u305F\u3044\u914D\
    \u5217\n    * @return \u7573\u307F\u8FBC\u307F\u3057\u305F\u7D50\u679C\n    *\
    \ @usage\n    *   vector<ll> a(2*n+1), b(2*n+1);\n    *   vector<ll> c = NTT<>::multiply(a,\
    \ b);\n    */\n    static vector<ll> multiply(const vector<ll>& a, const vector<ll>&\
    \ b) {\n        auto A = NTT(a).solve();\n        auto B = NTT(b).solve();\n\n\
    \        vector<ll> C(A.size());\n        REP(i, C.size()) C[i] = (A[i] * B[i])\
    \ % 998244353;\n\n        return NTT(C).solve(true);\n    }\n\nprivate:\n    int\
    \ n;\n    vector<ll> a;\n    ll inv_n, root, inv_root;\n\n    NTT(const vector<ll>&\
    \ a) : n(1), a(a) {\n        while (n < a.size()) n <<= 1;\n        this->a.resize(n);\n\
    \        inv_n = modpow(n, mod-2);\n        root = modpow(primitive, (mod-1) /\
    \ n);\n        inv_root = modpow(root, mod-2);\n    }\n\n    vector<ll> solve(bool\
    \ inverse = false) {\n        return ntt(0, 0, inverse, inverse ? inv_root : root);\n\
    \    }\n\n    vector<ll> ntt(int d, int bit, bool inverse, ll base) {\n      \
    \  int sz = n >> d;\n        if (sz == 1) return {(a[bit] * (inverse ? inv_n :\
    \ 1)) % mod};\n\n        auto f0 = ntt(d+1, bit, inverse, (base * base) % mod);\n\
    \        auto f1 = ntt(d+1, bit | 1<<d, inverse, (base * base) % mod);\n     \
    \   vector<ll> f(sz);\n        ll tmp = 1;\n        for (int i = 0; i < sz; ++i)\
    \ {\n            f[i] = (f0[i % (sz / 2)] + tmp * f1[i % (sz / 2)]) % mod;\n \
    \           (tmp *= base) %= mod;\n        }\n        return f;\n    }\n\n   \
    \ ll modpow(ll a, ll p) {\n        ll ret = 1;\n        while (p) {\n        \
    \    if (p & 1) (ret *= a) %= mod;\n            (a *= a) %= mod;\n           \
    \ p >>= 1;\n        }\n        return ret;\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/ntt.cpp
  requiredBy: []
  timestamp: '2020-07-11 00:18:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/number/ntt.cpp
layout: document
redirect_from:
- /library/lib/number/ntt.cpp
- /library/lib/number/ntt.cpp.html
title: "\u7573\u307F\u8FBC\u307F\u306E\u5B9F\u884C. O(nlog n)"
---
