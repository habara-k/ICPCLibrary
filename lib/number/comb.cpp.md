---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/number/Bell.test.cpp
    title: test/number/Bell.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/C.test.cpp
    title: test/number/C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/Partition1.test.cpp
    title: test/number/Partition1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/Partition2.test.cpp
    title: test/number/Partition2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/Stirling.test.cpp
    title: test/number/Stirling.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/montmort_number.test.cpp
    title: test/yosupo-judge/montmort_number.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/comb.cpp\"\
    \n\n#define SNIPPET_ONLY\n\ntemplate<typename T>\nstruct Combination {\n    int\
    \ _n = 1;\n    vector<T> _fact{1}, _rfact{1};\n\n    void extend(int n) {\n  \
    \      if (n <= _n) return;\n        _fact.resize(n);\n        _rfact.resize(n);\n\
    \        for (int i = _n; i < n; ++i) _fact[i] = _fact[i - 1] * i;\n        _rfact[n\
    \ - 1] = 1 / _fact[n - 1];\n        for (int i = n - 1; i > _n; --i) _rfact[i\
    \ - 1] = _rfact[i] * i;\n        _n = n;\n    }\n\n    T fact(int k) {\n     \
    \   extend(k + 1);\n        return _fact.at(k);\n    }\n\n    T rfact(int k) {\n\
    \        extend(k + 1);\n        return _rfact.at(k);\n    }\n\n    T P(int n,\
    \ int r) {\n        if (r < 0 or n < r) return 0;\n        return fact(n) * rfact(n\
    \ - r);\n    }\n\n    T C(int n, int r) {\n        if (r < 0 or n < r) return\
    \ 0;\n        return fact(n) * rfact(r) * rfact(n - r);\n    }\n\n    T H(int\
    \ n, int r) {\n        return (n == 0 and r == 0) ? 1 : C(n + r - 1, r);\n   \
    \ }\n\n    // O(k logn)\n    // \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\n \
    \   // Stirling(n, k) := n \u500B\u306E\u533A\u5225\u3067\u304D\u308B\u30DC\u30FC\
    \u30EB\u3092 k \u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\u7BB1\u306B\u3044\
    \u308C\u308B\u5834\u5408\u306E\u6570\n    //                   \u305D\u308C\u305E\
    \u308C\u306E\u7BB1\u306B\u306F1\u500B\u4EE5\u4E0A\u30DC\u30FC\u30EB\u3092\u3044\
    \u308C\u308B\n    // ---\n    // S(n, k) = S(n-1, k-1) + k * S(n-1, k)\n    //\
    \ * \u7279\u5B9A\u306E1\u500B\u3060\u3051\u30671\u500B\u306E\u7BB1\u306B\u3044\
    \u308C\u308B\u5834\u5408\u306F S(n-1, k-1)\n    // * \u305D\u3046\u3067\u306A\u3044\
    \u5834\u5408\u306F S(n-1, k) \u901A\u308A\u306B\u5BFE\u3057\u3066\u7279\u5B9A\u306E\
    1\u500B\u3092\u3044\u308C\u308B\u306E\u304C k \u901A\u308A\n    // ---\n    //\
    \ \u5404\u30B0\u30EB\u30FC\u30D7\u306B\u3064\u304Dr\u500B\u4EE5\u4E0A, \u306E\u5236\
    \u9650\u304C\u3042\u308B\u5834\u5408\n    // S(n, k) = C(n-1, r-1) * S(n-r, k-1)\
    \ + k * S(n-1, k)\n    // ---\n    // \u7389\u304Cn\u500B\u3042\u308B\u3046\u3061\
    \u306E\u3044\u304F\u3064\u304B\u3092\u9078\u3093\u3067k\u30B0\u30EB\u30FC\u30D7\
    \u306B\u5206\u3051\u308B\u5834\u5408\n    // S(n, k) = S(n-1, k-1) + (k+1) * S(n-1,\
    \ k)\n    T Stirling(ll n, int k) {\n        T ret = 0;\n        for (int l =\
    \ 0; l <= k; ++l) {\n            ret += C(k, l) * T{k-l}.pow(n) * (l & 1 ? -1\
    \ : 1);\n        }\n        return ret / fact(k);\n    }\n\n    // O(k^2 logn)\n\
    \    // \u30D9\u30EB\u6570\n    // Bell(n, k) := n \u500B\u306E\u533A\u5225\u3067\
    \u304D\u308B\u30DC\u30FC\u30EB\u3092 k \u500B\u306E\u533A\u5225\u3067\u304D\u306A\
    \u3044\u7BB1\u306B\u3044\u308C\u308B\u5834\u5408\u306E\u6570\n    // ---\n   \
    \ // B(n+1) := Bell(n+1, n+1) = n \u500B\u306E\u533A\u5225\u3067\u304D\u308B\u30DC\
    \u30FC\u30EB\u306E\u5206\u5272\u306E\u7DCF\u6570\n    // B(n+1) = \\sum_{i=0}^n\
    \ C(n,i) * B(i)\n    // * \u7279\u5B9A\u306E1\u500B\u304C\u5C5E\u3059\u308B\u30B0\
    \u30EB\u30FC\u30D7\u306B, \u4ED6\u306E\u30DC\u30FC\u30EB\u304Cn-i \u500B\u5165\
    \u3063\u3066\u3044\u308B\u3068\u304D,\n    // * \u6B8B\u308Ai \u500B\u306E\u4E26\
    \u3079\u65B9\u306FB(i)\n    T Bell(ll n, int k) {\n        T ret = 0;\n      \
    \  for (int l = 0; l <= k; ++l) {\n            ret += Stirling(n, l);\n      \
    \  }\n        return ret;\n    }\n\n};\n\n// O(nk)\n// Partition[n][k] := n \u500B\
    \u306E\u533A\u5225\u3067\u304D\u306A\u3044\u30DC\u30FC\u30EB\u3092 k \u500B\u306E\
    \u533A\u5225\u3067\u304D\u306A\u3044\u7BB1\u306B\u3044\u308C\u308B\u5834\u5408\
    \u306E\u6570\n// ---\n// \u5404\u30B0\u30EB\u30FC\u30D7\u306B\u3064\u304D1\u500B\
    \u4EE5\u4E0A, \u306E\u5236\u9650\u304C\u3042\u308B\u5834\u5408, Part[n][k] - Part[n][k-1]\n\
    template<typename T>\nvector<vector<T>> Partition(int n, int k) {\n    vector<vector<T>>\
    \ ret(n+1, vector<T>(k+1));\n    ret[0][0] = 1;\n    for (int i = 0; i <= n; ++i)\
    \ {\n        for (int j = 1; j <= k; ++j) {\n            ret[i][j] = ret[i][j-1]\
    \ + (i-j >= 0 ? ret[i-j][j] : 0);\n        }\n    }\n    return ret;\n}\n\n//\
    \ O(n)\n// Montmort[n] := 1, ..., n \u306E\u64B9\u4E71\u9806\u5217\u306E\u7DCF\
    \u6570(n > 0)\ntemplate<typename T>\nvector<T> Montmort(int n) {\n    vector<T>\
    \ ret(n+1);\n    ret[2] = 1;\n    for (int k = 3; k <= n; ++k) {\n        ret[k]\
    \ = (k-1) * (ret[k-1] + ret[k-2]);\n    }\n    return ret;\n}\n"
  code: "#include \"../template.cpp\"\n\n#define SNIPPET_ONLY\n\ntemplate<typename\
    \ T>\nstruct Combination {\n    int _n = 1;\n    vector<T> _fact{1}, _rfact{1};\n\
    \n    void extend(int n) {\n        if (n <= _n) return;\n        _fact.resize(n);\n\
    \        _rfact.resize(n);\n        for (int i = _n; i < n; ++i) _fact[i] = _fact[i\
    \ - 1] * i;\n        _rfact[n - 1] = 1 / _fact[n - 1];\n        for (int i = n\
    \ - 1; i > _n; --i) _rfact[i - 1] = _rfact[i] * i;\n        _n = n;\n    }\n\n\
    \    T fact(int k) {\n        extend(k + 1);\n        return _fact.at(k);\n  \
    \  }\n\n    T rfact(int k) {\n        extend(k + 1);\n        return _rfact.at(k);\n\
    \    }\n\n    T P(int n, int r) {\n        if (r < 0 or n < r) return 0;\n   \
    \     return fact(n) * rfact(n - r);\n    }\n\n    T C(int n, int r) {\n     \
    \   if (r < 0 or n < r) return 0;\n        return fact(n) * rfact(r) * rfact(n\
    \ - r);\n    }\n\n    T H(int n, int r) {\n        return (n == 0 and r == 0)\
    \ ? 1 : C(n + r - 1, r);\n    }\n\n    // O(k logn)\n    // \u30B9\u30BF\u30FC\
    \u30EA\u30F3\u30B0\u6570\n    // Stirling(n, k) := n \u500B\u306E\u533A\u5225\u3067\
    \u304D\u308B\u30DC\u30FC\u30EB\u3092 k \u500B\u306E\u533A\u5225\u3067\u304D\u306A\
    \u3044\u7BB1\u306B\u3044\u308C\u308B\u5834\u5408\u306E\u6570\n    //         \
    \          \u305D\u308C\u305E\u308C\u306E\u7BB1\u306B\u306F1\u500B\u4EE5\u4E0A\
    \u30DC\u30FC\u30EB\u3092\u3044\u308C\u308B\n    // ---\n    // S(n, k) = S(n-1,\
    \ k-1) + k * S(n-1, k)\n    // * \u7279\u5B9A\u306E1\u500B\u3060\u3051\u30671\u500B\
    \u306E\u7BB1\u306B\u3044\u308C\u308B\u5834\u5408\u306F S(n-1, k-1)\n    // * \u305D\
    \u3046\u3067\u306A\u3044\u5834\u5408\u306F S(n-1, k) \u901A\u308A\u306B\u5BFE\u3057\
    \u3066\u7279\u5B9A\u306E1\u500B\u3092\u3044\u308C\u308B\u306E\u304C k \u901A\u308A\
    \n    // ---\n    // \u5404\u30B0\u30EB\u30FC\u30D7\u306B\u3064\u304Dr\u500B\u4EE5\
    \u4E0A, \u306E\u5236\u9650\u304C\u3042\u308B\u5834\u5408\n    // S(n, k) = C(n-1,\
    \ r-1) * S(n-r, k-1) + k * S(n-1, k)\n    // ---\n    // \u7389\u304Cn\u500B\u3042\
    \u308B\u3046\u3061\u306E\u3044\u304F\u3064\u304B\u3092\u9078\u3093\u3067k\u30B0\
    \u30EB\u30FC\u30D7\u306B\u5206\u3051\u308B\u5834\u5408\n    // S(n, k) = S(n-1,\
    \ k-1) + (k+1) * S(n-1, k)\n    T Stirling(ll n, int k) {\n        T ret = 0;\n\
    \        for (int l = 0; l <= k; ++l) {\n            ret += C(k, l) * T{k-l}.pow(n)\
    \ * (l & 1 ? -1 : 1);\n        }\n        return ret / fact(k);\n    }\n\n   \
    \ // O(k^2 logn)\n    // \u30D9\u30EB\u6570\n    // Bell(n, k) := n \u500B\u306E\
    \u533A\u5225\u3067\u304D\u308B\u30DC\u30FC\u30EB\u3092 k \u500B\u306E\u533A\u5225\
    \u3067\u304D\u306A\u3044\u7BB1\u306B\u3044\u308C\u308B\u5834\u5408\u306E\u6570\
    \n    // ---\n    // B(n+1) := Bell(n+1, n+1) = n \u500B\u306E\u533A\u5225\u3067\
    \u304D\u308B\u30DC\u30FC\u30EB\u306E\u5206\u5272\u306E\u7DCF\u6570\n    // B(n+1)\
    \ = \\sum_{i=0}^n C(n,i) * B(i)\n    // * \u7279\u5B9A\u306E1\u500B\u304C\u5C5E\
    \u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306B, \u4ED6\u306E\u30DC\u30FC\u30EB\u304C\
    n-i \u500B\u5165\u3063\u3066\u3044\u308B\u3068\u304D,\n    // * \u6B8B\u308Ai\
    \ \u500B\u306E\u4E26\u3079\u65B9\u306FB(i)\n    T Bell(ll n, int k) {\n      \
    \  T ret = 0;\n        for (int l = 0; l <= k; ++l) {\n            ret += Stirling(n,\
    \ l);\n        }\n        return ret;\n    }\n\n};\n\n// O(nk)\n// Partition[n][k]\
    \ := n \u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\u30DC\u30FC\u30EB\u3092\
    \ k \u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\u7BB1\u306B\u3044\u308C\u308B\
    \u5834\u5408\u306E\u6570\n// ---\n// \u5404\u30B0\u30EB\u30FC\u30D7\u306B\u3064\
    \u304D1\u500B\u4EE5\u4E0A, \u306E\u5236\u9650\u304C\u3042\u308B\u5834\u5408, Part[n][k]\
    \ - Part[n][k-1]\ntemplate<typename T>\nvector<vector<T>> Partition(int n, int\
    \ k) {\n    vector<vector<T>> ret(n+1, vector<T>(k+1));\n    ret[0][0] = 1;\n\
    \    for (int i = 0; i <= n; ++i) {\n        for (int j = 1; j <= k; ++j) {\n\
    \            ret[i][j] = ret[i][j-1] + (i-j >= 0 ? ret[i-j][j] : 0);\n       \
    \ }\n    }\n    return ret;\n}\n\n// O(n)\n// Montmort[n] := 1, ..., n \u306E\u64B9\
    \u4E71\u9806\u5217\u306E\u7DCF\u6570(n > 0)\ntemplate<typename T>\nvector<T> Montmort(int\
    \ n) {\n    vector<T> ret(n+1);\n    ret[2] = 1;\n    for (int k = 3; k <= n;\
    \ ++k) {\n        ret[k] = (k-1) * (ret[k-1] + ret[k-2]);\n    }\n    return ret;\n\
    }\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/comb.cpp
  requiredBy: []
  timestamp: '2020-10-12 01:33:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/Partition1.test.cpp
  - test/number/Partition2.test.cpp
  - test/number/Bell.test.cpp
  - test/number/C.test.cpp
  - test/number/Stirling.test.cpp
  - test/yosupo-judge/montmort_number.test.cpp
documentation_of: lib/number/comb.cpp
layout: document
redirect_from:
- /library/lib/number/comb.cpp
- /library/lib/number/comb.cpp.html
title: lib/number/comb.cpp
---
