---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/number/fps.cpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
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
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/convolution.test.cpp
    title: test/yosupo-judge/convolution.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: NTT
    links:
    - https://ei1333.github.io/library/math/fft/number-theoretic-transform-friendly-mod-int.cpp
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
    \n\n/*\n * @brief NTT\n * @ref https://ei1333.github.io/library/math/fft/number-theoretic-transform-friendly-mod-int.cpp\n\
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
    \        return a;\n    }\n};\n\n"
  code: "#include \"../template.cpp\"\n\n/*\n * @brief NTT\n * @ref https://ei1333.github.io/library/math/fft/number-theoretic-transform-friendly-mod-int.cpp\n\
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
    \        return a;\n    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/ntt.cpp
  requiredBy:
  - lib/number/fps.cpp
  timestamp: '2020-10-24 19:29:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/convolution.test.cpp
  - test/number/fps/pow.test.cpp
  - test/number/fps/exp.test.cpp
  - test/number/fps/inv.test.cpp
  - test/number/fps/log.test.cpp
documentation_of: lib/number/ntt.cpp
layout: document
redirect_from:
- /library/lib/number/ntt.cpp
- /library/lib/number/ntt.cpp.html
title: NTT
---
