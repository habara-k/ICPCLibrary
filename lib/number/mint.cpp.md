---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/convolution.test.cpp
    title: test/yosupo-judge/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/point_set_range_composite.test.cpp
    title: test/yosupo-judge/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/range_affine_range_sum.test.cpp
    title: test/yosupo-judge/range_affine_range_sum.test.cpp
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/mint.cpp\"\
    \n\ntemplate<ll m>\nstruct mint {\n    ll x;\n    mint(ll x = 0) : x(((x % m)\
    \ + m) % m) {}\n    mint operator-() { return x ? m-x : 0; }\n    mint &operator+=(mint\
    \ r) {\n        if ((x += r.x) >= m) x -= m;\n        return *this;\n    }\n \
    \   mint &operator-=(mint r) { return *this += -r; }\n    mint &operator*=(mint\
    \ r) {\n        (x *= r.x) %= m;\n        return *this;\n    }\n    mint &operator/=(mint\
    \ r) { return *this *= r.pow(m-2); }\n\n    friend mint operator+(mint l, mint\
    \ r) { return l += r; }\n    friend mint operator-(mint l, mint r) { return l\
    \ -= r; }\n    friend mint operator*(mint l, mint r) { return l *= r; }\n    friend\
    \ mint operator/(mint l, mint r) { return l /= r; }\n    mint pow(ll n) {\n  \
    \      mint ret = 1, tmp = *this;\n        while (n) {\n            if (n & 1)\
    \ ret *= tmp;\n            tmp *= tmp, n >>= 1;\n        }\n        return ret;\n\
    \    }\n    friend ostream &operator<<(ostream &os, mint a) {\n        return\
    \ os << a.x;\n    }\n    friend istream &operator>>(istream &is, mint& a) {\n\
    \        ll x; is >> x; a = x; return is;\n    }\n};\n\n"
  code: "#include \"../template.cpp\"\n\ntemplate<ll m>\nstruct mint {\n    ll x;\n\
    \    mint(ll x = 0) : x(((x % m) + m) % m) {}\n    mint operator-() { return x\
    \ ? m-x : 0; }\n    mint &operator+=(mint r) {\n        if ((x += r.x) >= m) x\
    \ -= m;\n        return *this;\n    }\n    mint &operator-=(mint r) { return *this\
    \ += -r; }\n    mint &operator*=(mint r) {\n        (x *= r.x) %= m;\n       \
    \ return *this;\n    }\n    mint &operator/=(mint r) { return *this *= r.pow(m-2);\
    \ }\n\n    friend mint operator+(mint l, mint r) { return l += r; }\n    friend\
    \ mint operator-(mint l, mint r) { return l -= r; }\n    friend mint operator*(mint\
    \ l, mint r) { return l *= r; }\n    friend mint operator/(mint l, mint r) { return\
    \ l /= r; }\n    mint pow(ll n) {\n        mint ret = 1, tmp = *this;\n      \
    \  while (n) {\n            if (n & 1) ret *= tmp;\n            tmp *= tmp, n\
    \ >>= 1;\n        }\n        return ret;\n    }\n    friend ostream &operator<<(ostream\
    \ &os, mint a) {\n        return os << a.x;\n    }\n    friend istream &operator>>(istream\
    \ &is, mint& a) {\n        ll x; is >> x; a = x; return is;\n    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/mint.cpp
  requiredBy: []
  timestamp: '2020-10-13 20:06:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/convolution.test.cpp
  - test/yosupo-judge/range_affine_range_sum.test.cpp
  - test/yosupo-judge/point_set_range_composite.test.cpp
documentation_of: lib/number/mint.cpp
layout: document
redirect_from:
- /library/lib/number/mint.cpp
- /library/lib/number/mint.cpp.html
title: lib/number/mint.cpp
---