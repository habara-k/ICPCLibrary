---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/others/LIS.cpp
    title: test/others/LIS.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/others/LIS.cpp\"\
    \n\ntemplate<typename T>\nint LIS(const vector<T>& a) {\n    int n = a.size();\n\
    \    T INF = numeric_limits<T>::max();\n    vector<T> dp(n, INF);\n    for(int\
    \ i = 0; i < n; ++i) {\n        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];\n\
    \    }\n    return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), INF));\n\
    }\n"
  code: "#include \"../template.cpp\"\n\ntemplate<typename T>\nint LIS(const vector<T>&\
    \ a) {\n    int n = a.size();\n    T INF = numeric_limits<T>::max();\n    vector<T>\
    \ dp(n, INF);\n    for(int i = 0; i < n; ++i) {\n        *lower_bound(dp.begin(),\
    \ dp.end(), a[i]) = a[i];\n    }\n    return distance(dp.begin(), lower_bound(dp.begin(),\
    \ dp.end(), INF));\n}\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/others/LIS.cpp
  requiredBy:
  - test/others/LIS.cpp
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/LIS.cpp
layout: document
redirect_from:
- /library/lib/others/LIS.cpp
- /library/lib/others/LIS.cpp.html
title: lib/others/LIS.cpp
---