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
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"test/number/extended_gcd.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\n\n#line 1\
    \ \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i, n) for (int i=(int)(n)-1;\
    \ i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n); ++i)\n#define RFOR(i,\
    \ a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/extended_gcd.cpp\"\n\nll extended_gcd(ll\
    \ a, ll b, ll& x, ll& y) {\n    // solve ax + by = gcd(a, b)\n    if (b == 0)\
    \ { x = 1; y = 0; return a; }\n    ll X, Y;\n    ll g = extended_gcd(b, a % b,\
    \ X, Y);\n    x = Y; y = X - a/b * Y;\n    return g;\n}\n#line 4 \"test/number/extended_gcd.test.cpp\"\
    \n\nint main() {\n    ll a, b; cin >> a >> b;\n    ll x, y;\n    extended_gcd(a,\
    \ b, x, y);\n    cout << x << \" \" << y << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include \"../../lib/number/extended_gcd.cpp\"\n\nint main() {\n    ll a,\
    \ b; cin >> a >> b;\n    ll x, y;\n    extended_gcd(a, b, x, y);\n    cout <<\
    \ x << \" \" << y << endl;\n}\n"
  dependsOn:
  - lib/number/extended_gcd.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/number/extended_gcd.test.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/extended_gcd.test.cpp
layout: document
redirect_from:
- /verify/test/number/extended_gcd.test.cpp
- /verify/test/number/extended_gcd.test.cpp.html
title: test/number/extended_gcd.test.cpp
---
