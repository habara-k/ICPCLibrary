---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/number/crt.cpp
    title: lib/number/crt.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/number/crt.test.cpp
    title: test/number/crt.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/extended_gcd.test.cpp
    title: test/number/extended_gcd.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
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
    \ a % b, X, Y);\n    x = Y; y = X - a/b * Y;\n    return g;\n}\n"
  code: "#include \"../template.cpp\"\n\nll extended_gcd(ll a, ll b, ll& x, ll& y)\
    \ {\n    // solve ax + by = gcd(a, b)\n    if (b == 0) { x = 1; y = 0; return\
    \ a; }\n    ll X, Y;\n    ll g = extended_gcd(b, a % b, X, Y);\n    x = Y; y =\
    \ X - a/b * Y;\n    return g;\n}\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/extended_gcd.cpp
  requiredBy:
  - lib/number/crt.cpp
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/crt.test.cpp
  - test/number/extended_gcd.test.cpp
documentation_of: lib/number/extended_gcd.cpp
layout: document
redirect_from:
- /library/lib/number/extended_gcd.cpp
- /library/lib/number/extended_gcd.cpp.html
title: lib/number/extended_gcd.cpp
---
