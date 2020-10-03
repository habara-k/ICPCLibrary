---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/number/combination.cpp
    title: lib/number/combination.cpp
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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc042/submissions/13372745
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/mod.cpp\"\
    \n\nll powm(ll a, ll n, ll m) {\n    ll ret = 1;\n    while (n > 0) {\n      \
    \  if (n & 1) (ret *= a) %= m;\n        (a *= a) %= m;\n        n >>= 1;\n   \
    \ }\n    return ret;\n}\n\nll invm(ll a, ll m) {\n    return powm(a, m-2, m);\n\
    }\n\n\n/**\n * @brief\n * \u96E2\u6563\u5BFE\u6570 O(sqrt(m))\n * @author habara-k\n\
    \ * @date 2020/05/18\n * @verify https://atcoder.jp/contests/arc042/submissions/13372745\n\
    \ *\n * @param[in] a: 0 < a < m\n * @param[in] b: 0 <= b < m\n * @param[in] m:\
    \ prime\n * @return:\n *     minimum x >= 0 s.t. a^x == b mod m\n *     if no\
    \ x satisfies the condition, return -1\n */\n\nll logm(ll a, ll b, ll m) {\n\n\
    \    ll sm = sqrt(m);\n\n    map<ll,int> mp;\n    for (ll t = 1, r = 0; r < sm;\
    \ (t *= a) %= m, ++r) {\n        if (!mp.count(t)) mp[t] = r;\n    }\n\n    ll\
    \ A = invm(powm(a, sm, m), m);\n    for (ll t = b, p = 0; p <= sm; (t *= A) %=\
    \ m, ++p) {\n        if (mp.count(t)) {\n            return sm * p + mp[t];\n\
    \        }\n    }\n    return -1;\n}\n"
  code: "#include \"../template.cpp\"\n\nll powm(ll a, ll n, ll m) {\n    ll ret =\
    \ 1;\n    while (n > 0) {\n        if (n & 1) (ret *= a) %= m;\n        (a *=\
    \ a) %= m;\n        n >>= 1;\n    }\n    return ret;\n}\n\nll invm(ll a, ll m)\
    \ {\n    return powm(a, m-2, m);\n}\n\n\n/**\n * @brief\n * \u96E2\u6563\u5BFE\
    \u6570 O(sqrt(m))\n * @author habara-k\n * @date 2020/05/18\n * @verify https://atcoder.jp/contests/arc042/submissions/13372745\n\
    \ *\n * @param[in] a: 0 < a < m\n * @param[in] b: 0 <= b < m\n * @param[in] m:\
    \ prime\n * @return:\n *     minimum x >= 0 s.t. a^x == b mod m\n *     if no\
    \ x satisfies the condition, return -1\n */\n\nll logm(ll a, ll b, ll m) {\n\n\
    \    ll sm = sqrt(m);\n\n    map<ll,int> mp;\n    for (ll t = 1, r = 0; r < sm;\
    \ (t *= a) %= m, ++r) {\n        if (!mp.count(t)) mp[t] = r;\n    }\n\n    ll\
    \ A = invm(powm(a, sm, m), m);\n    for (ll t = b, p = 0; p <= sm; (t *= A) %=\
    \ m, ++p) {\n        if (mp.count(t)) {\n            return sm * p + mp[t];\n\
    \        }\n    }\n    return -1;\n}\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/mod.cpp
  requiredBy:
  - lib/number/combination.cpp
  timestamp: '2020-05-18 18:10:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/C.test.cpp
  - test/number/Stirling.test.cpp
  - test/number/Bell.test.cpp
  - test/number/Partition1.test.cpp
  - test/number/Partition2.test.cpp
documentation_of: lib/number/mod.cpp
layout: document
redirect_from:
- /library/lib/number/mod.cpp
- /library/lib/number/mod.cpp.html
title: lib/number/mod.cpp
---
