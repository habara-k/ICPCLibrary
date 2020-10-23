---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/extended_gcd.cpp
    title: lib/number/extended_gcd.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/number/crt.test.cpp
    title: test/number/crt.test.cpp
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/extended_gcd.cpp\"\
    \n\nll extended_gcd(ll a, ll b, ll& x, ll& y) {\n    // solve ax + by = gcd(a,\
    \ b)\n    if (b == 0) { x = 1; y = 0; return a; }\n    ll X, Y;\n    ll g = extended_gcd(b,\
    \ a % b, X, Y);\n    x = Y; y = X - a/b * Y;\n    return g;\n}\n#line 2 \"lib/number/crt.cpp\"\
    \n\n/**\n * @brief\n * \u4E2D\u56FD\u5F0F\u5834\u4E88\u5B9A\u7406(CRT)\n * m1\u3067\
    \u5272\u3063\u305F\u3042\u307E\u308A\u304Ca1, m2\u3067\u5272\u3063\u305F\u3042\
    \u307E\u308A\u304Ca2\u306E\u3068\u304D\u3001m1*m2\u3067\u308F\u3063\u305F\u3042\
    \u307E\u308A\u3092\u69CB\u7BC9\n * @author Md\n * @date 2020/04/25\n */\n\n/**\n\
    \ * @return first: \u7B54\u3048, second: mod\u306E\u5024\n */\npair<ll, ll> crt(ll\
    \ a1, ll m1, ll a2, ll m2) {\n  ll p, q;\n  ll g = extended_gcd(m1, m2, p, q);\n\
    \  if ((a1 - a2) % g) return make_pair(0, -1);\n  return make_pair(a1 + m1 * (a2\
    \ - a1) / g * p % (m2 / g), m1 * (m2 / g));\n}\n\n/**\n * @brief\n * \u5F0F\u304C\
    \u8907\u6570\u500B\u3042\u308B\u5834\u5408\n * @return first: \u7B54\u3048, second:\
    \ mod\u306E\u5024\n */\npair<ll, ll> crt(const vector<ll> &a, const vector<ll>\
    \ &m) {\n  ll r = 0, mod = 1;\n  REP(i, SZ(a)) {\n    ll p, q;\n    ll g = extended_gcd(mod,\
    \ m[i], p, q);\n    if ((a[i] - r) % g) return make_pair(0, -1);\n    ll tmp =\
    \ (a[i] - r) / g * p % (m[i] / g);\n    r += mod * tmp;\n    mod *= m[i] / g;\n\
    \  }\n  return make_pair(r % mod, mod);\n}\n"
  code: "#include \"./extended_gcd.cpp\"\n\n/**\n * @brief\n * \u4E2D\u56FD\u5F0F\u5834\
    \u4E88\u5B9A\u7406(CRT)\n * m1\u3067\u5272\u3063\u305F\u3042\u307E\u308A\u304C\
    a1, m2\u3067\u5272\u3063\u305F\u3042\u307E\u308A\u304Ca2\u306E\u3068\u304D\u3001\
    m1*m2\u3067\u308F\u3063\u305F\u3042\u307E\u308A\u3092\u69CB\u7BC9\n * @author\
    \ Md\n * @date 2020/04/25\n */\n\n/**\n * @return first: \u7B54\u3048, second:\
    \ mod\u306E\u5024\n */\npair<ll, ll> crt(ll a1, ll m1, ll a2, ll m2) {\n  ll p,\
    \ q;\n  ll g = extended_gcd(m1, m2, p, q);\n  if ((a1 - a2) % g) return make_pair(0,\
    \ -1);\n  return make_pair(a1 + m1 * (a2 - a1) / g * p % (m2 / g), m1 * (m2 /\
    \ g));\n}\n\n/**\n * @brief\n * \u5F0F\u304C\u8907\u6570\u500B\u3042\u308B\u5834\
    \u5408\n * @return first: \u7B54\u3048, second: mod\u306E\u5024\n */\npair<ll,\
    \ ll> crt(const vector<ll> &a, const vector<ll> &m) {\n  ll r = 0, mod = 1;\n\
    \  REP(i, SZ(a)) {\n    ll p, q;\n    ll g = extended_gcd(mod, m[i], p, q);\n\
    \    if ((a[i] - r) % g) return make_pair(0, -1);\n    ll tmp = (a[i] - r) / g\
    \ * p % (m[i] / g);\n    r += mod * tmp;\n    mod *= m[i] / g;\n  }\n  return\
    \ make_pair(r % mod, mod);\n}\n"
  dependsOn:
  - lib/number/extended_gcd.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/crt.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/crt.test.cpp
documentation_of: lib/number/crt.cpp
layout: document
redirect_from:
- /library/lib/number/crt.cpp
- /library/lib/number/crt.cpp.html
title: lib/number/crt.cpp
---
