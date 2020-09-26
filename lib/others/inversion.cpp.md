---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/structure/binary_indexed_tree.cpp
    title: lib/structure/binary_indexed_tree.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/others/inversion.cpp
    title: test/others/inversion.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/others/inversion.cpp\"\
    \n\n#line 2 \"lib/structure/binary_indexed_tree.cpp\"\n\ntemplate<typename T>\n\
    struct BIT {\n    vector<T> bit;\n    int sz;\n    BIT(int n) : sz(n+1), bit(n+1)\
    \ {}\n    void add(int i, T x) {\n        i += 1;\n        while (i < sz) { bit[i]\
    \ += x; i += i & -i; }\n    }\n    T sum(int i) {\n        i += 1; T s = 0;\n\
    \        while (i > 0) { s += bit[i]; i -= i & -i; }\n        return s;\n    }\n\
    };\n#line 4 \"lib/others/inversion.cpp\"\n\ntemplate<typename T>\nll inversion(const\
    \ vector<T>& a)\n{\n    map<T,int> mp;\n    for (auto e : a) mp[e] = -1;\n   \
    \ int sz = 0;\n    for (auto &q : mp) {\n        q.second = sz++;\n    }\n\n \
    \   BIT<int> bit(sz+1);\n    ll res = 0;\n    for (int i = 0; i < a.size(); ++i)\
    \ {\n        res += i - bit.sum(mp[a[i]]);\n        bit.add(mp[a[i]], 1);\n  \
    \  }\n    return res;\n}\n"
  code: "#include \"../template.cpp\"\n\n#include \"../structure/binary_indexed_tree.cpp\"\
    \n\ntemplate<typename T>\nll inversion(const vector<T>& a)\n{\n    map<T,int>\
    \ mp;\n    for (auto e : a) mp[e] = -1;\n    int sz = 0;\n    for (auto &q : mp)\
    \ {\n        q.second = sz++;\n    }\n\n    BIT<int> bit(sz+1);\n    ll res =\
    \ 0;\n    for (int i = 0; i < a.size(); ++i) {\n        res += i - bit.sum(mp[a[i]]);\n\
    \        bit.add(mp[a[i]], 1);\n    }\n    return res;\n}\n"
  dependsOn:
  - lib/template.cpp
  - lib/structure/binary_indexed_tree.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/others/inversion.cpp
  requiredBy:
  - test/others/inversion.cpp
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/inversion.cpp
layout: document
redirect_from:
- /library/lib/others/inversion.cpp
- /library/lib/others/inversion.cpp.html
title: lib/others/inversion.cpp
---
