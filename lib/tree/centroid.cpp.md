---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/tree/tree_hash.cpp
    title: "\u6728\u306E\u30CF\u30C3\u30B7\u30E5\u5316"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/tree_hash.test.cpp
    title: test/tree/tree_hash.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6728\u306E\u91CD\u5FC3\u5217\u6319. O(n)"
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/tree/centroid.cpp\"\
    \n\n/**\n * @brief \u6728\u306E\u91CD\u5FC3\u5217\u6319. O(n)\n * @author habara-k\n\
    \ * @date 2020/10/14\n */\nvector<int> centroid(const vector<vector<int>>& g)\
    \ {\n    const int n = g.size();\n    vector<int> sz(n,1), ret;\n    function<int(int,int)>\
    \ dfs = [&](int u,int p) {\n        bool isCent = true;\n        for (int v :\
    \ g[u]) {\n            if (v == p) continue;\n            sz[u] += dfs(v, u);\n\
    \            if (sz[v] > n / 2) isCent = false;\n        }\n        if (n - sz[u]\
    \ > n / 2) isCent = false;\n        if (isCent) ret.emplace_back(u);\n       \
    \ return sz[u];\n    };\n    dfs(0, -1);\n    return ret;\n}\n\n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief \u6728\u306E\u91CD\u5FC3\u5217\
    \u6319. O(n)\n * @author habara-k\n * @date 2020/10/14\n */\nvector<int> centroid(const\
    \ vector<vector<int>>& g) {\n    const int n = g.size();\n    vector<int> sz(n,1),\
    \ ret;\n    function<int(int,int)> dfs = [&](int u,int p) {\n        bool isCent\
    \ = true;\n        for (int v : g[u]) {\n            if (v == p) continue;\n \
    \           sz[u] += dfs(v, u);\n            if (sz[v] > n / 2) isCent = false;\n\
    \        }\n        if (n - sz[u] > n / 2) isCent = false;\n        if (isCent)\
    \ ret.emplace_back(u);\n        return sz[u];\n    };\n    dfs(0, -1);\n    return\
    \ ret;\n}\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/tree/centroid.cpp
  requiredBy:
  - lib/tree/tree_hash.cpp
  timestamp: '2020-10-15 21:18:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/tree_hash.test.cpp
documentation_of: lib/tree/centroid.cpp
layout: document
redirect_from:
- /library/lib/tree/centroid.cpp
- /library/lib/tree/centroid.cpp.html
title: "\u6728\u306E\u91CD\u5FC3\u5217\u6319. O(n)"
---
