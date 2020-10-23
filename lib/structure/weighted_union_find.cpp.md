---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/structure/weighted_union_find.test.cpp
    title: test/structure/weighted_union_find.test.cpp
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/structure/weighted_union_find.cpp\"\
    \n\ntemplate<typename A>\nstruct WeightedUnionFind\n{\n    vector<int> par, sz;\n\
    \    vector<A> data;     // data[x]: diff from root to x\n    WeightedUnionFind(int\
    \ n, A e=0) :\n        par(n), sz(n, 1), data(n, e) {\n        for (int i = 0;\
    \ i < n; ++i) par[i] = i;\n    }\n\n    int root(int x) {\n        if (par[x]\
    \ == x) return x;\n        int r = root(par[x]);\n        data[x] += data[par[x]];\n\
    \        return par[x] = r;\n    }\n\n    A weight(int x) {\n        root(x);\n\
    \        return data[x];\n    }\n\n    A diff(int x, int y) {\n        // diff\
    \ from x to y\n        return data[y] - data[x];\n    }\n\n    void merge(int\
    \ x, int y, A w) {\n        // merge so that \"diff from x to y\" will be w.\n\
    \        w += weight(x); w -= weight(y);\n        x = root(x); y = root(y);\n\
    \        if (x == y) return;\n        if (sz[x] < sz[y]) swap(x, y), w = -w;\n\
    \        par[y] = x;\n        sz[x] += sz[y];\n        sz[y] = 0;\n        data[y]\
    \ = w;\n    }\n\n    bool issame(int x, int y) {\n        return root(x) == root(y);\n\
    \    }\n};\n"
  code: "#include \"../template.cpp\"\n\ntemplate<typename A>\nstruct WeightedUnionFind\n\
    {\n    vector<int> par, sz;\n    vector<A> data;     // data[x]: diff from root\
    \ to x\n    WeightedUnionFind(int n, A e=0) :\n        par(n), sz(n, 1), data(n,\
    \ e) {\n        for (int i = 0; i < n; ++i) par[i] = i;\n    }\n\n    int root(int\
    \ x) {\n        if (par[x] == x) return x;\n        int r = root(par[x]);\n  \
    \      data[x] += data[par[x]];\n        return par[x] = r;\n    }\n\n    A weight(int\
    \ x) {\n        root(x);\n        return data[x];\n    }\n\n    A diff(int x,\
    \ int y) {\n        // diff from x to y\n        return data[y] - data[x];\n \
    \   }\n\n    void merge(int x, int y, A w) {\n        // merge so that \"diff\
    \ from x to y\" will be w.\n        w += weight(x); w -= weight(y);\n        x\
    \ = root(x); y = root(y);\n        if (x == y) return;\n        if (sz[x] < sz[y])\
    \ swap(x, y), w = -w;\n        par[y] = x;\n        sz[x] += sz[y];\n        sz[y]\
    \ = 0;\n        data[y] = w;\n    }\n\n    bool issame(int x, int y) {\n     \
    \   return root(x) == root(y);\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/structure/weighted_union_find.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/structure/weighted_union_find.test.cpp
documentation_of: lib/structure/weighted_union_find.cpp
layout: document
redirect_from:
- /library/lib/structure/weighted_union_find.cpp
- /library/lib/structure/weighted_union_find.cpp.html
title: lib/structure/weighted_union_find.cpp
---
