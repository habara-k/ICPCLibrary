---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6728\u306E\u91CD\u5FC3\u5206\u89E3. O(VlogV)"
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/tree/centroid_decomposition.cpp\"\
    \n\n/**\n * @brief \u6728\u306E\u91CD\u5FC3\u5206\u89E3. O(VlogV)\n * @author\
    \ habara-k\n * @date 2020/10/14\n * @details\n * g: \u5165\u529B\u306E\u7121\u5411\
    \u6728\n * t: \u91CD\u5FC3\u5206\u89E3\u306E\u69D8\u5B50\u3092\u8868\u3057\u305F\
    \u6839\u4ED8\u304D\u6728\n * root: t\u306E\u6839\n */\nstruct CentroidDecomposition\
    \ {\n    int n, root;\n    vector<vector<int>> g, t;\n\n    CentroidDecomposition(const\
    \ vector<vector<int>>& g) :\n    n(g.size()), g(g), t(n), sz(n), split(n) {\n\
    \        root = build(0);\n    }\n\nprivate:\n    vector<int> sz;\n    vector<bool>\
    \ split;\n\n    int build_size(int u, int p) {\n        sz[u] = 1;\n        for\
    \ (int v : g[u]) {\n            if (v == p or split[v]) continue;\n          \
    \  sz[u] += build_size(v, u);\n        }\n        return sz[u];\n    }\n    int\
    \ get_centroid(int u, int p, int mid) {\n        for (int v : g[u]) {\n      \
    \      if (v == p or split[v]) continue;\n            if (sz[v] > mid) return\
    \ get_centroid(v, u, mid);\n        }\n        return u;\n    }\n\n    int build(int\
    \ u) {\n        int cent = get_centroid(u, -1, build_size(u, -1) / 2);\n     \
    \   split[cent] = true;\n        for (int v : g[cent]) {\n            if (!split[v])\
    \ t[cent].emplace_back(build(v));\n        }\n        split[cent] = false;\n \
    \       return cent;\n    }\n};\n\n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief \u6728\u306E\u91CD\u5FC3\u5206\
    \u89E3. O(VlogV)\n * @author habara-k\n * @date 2020/10/14\n * @details\n * g:\
    \ \u5165\u529B\u306E\u7121\u5411\u6728\n * t: \u91CD\u5FC3\u5206\u89E3\u306E\u69D8\
    \u5B50\u3092\u8868\u3057\u305F\u6839\u4ED8\u304D\u6728\n * root: t\u306E\u6839\
    \n */\nstruct CentroidDecomposition {\n    int n, root;\n    vector<vector<int>>\
    \ g, t;\n\n    CentroidDecomposition(const vector<vector<int>>& g) :\n    n(g.size()),\
    \ g(g), t(n), sz(n), split(n) {\n        root = build(0);\n    }\n\nprivate:\n\
    \    vector<int> sz;\n    vector<bool> split;\n\n    int build_size(int u, int\
    \ p) {\n        sz[u] = 1;\n        for (int v : g[u]) {\n            if (v ==\
    \ p or split[v]) continue;\n            sz[u] += build_size(v, u);\n        }\n\
    \        return sz[u];\n    }\n    int get_centroid(int u, int p, int mid) {\n\
    \        for (int v : g[u]) {\n            if (v == p or split[v]) continue;\n\
    \            if (sz[v] > mid) return get_centroid(v, u, mid);\n        }\n   \
    \     return u;\n    }\n\n    int build(int u) {\n        int cent = get_centroid(u,\
    \ -1, build_size(u, -1) / 2);\n        split[cent] = true;\n        for (int v\
    \ : g[cent]) {\n            if (!split[v]) t[cent].emplace_back(build(v));\n \
    \       }\n        split[cent] = false;\n        return cent;\n    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/tree/centroid_decomposition.cpp
  requiredBy: []
  timestamp: '2020-10-16 15:26:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/tree/centroid_decomposition.cpp
layout: document
redirect_from:
- /library/lib/tree/centroid_decomposition.cpp
- /library/lib/tree/centroid_decomposition.cpp.html
title: "\u6728\u306E\u91CD\u5FC3\u5206\u89E3. O(VlogV)"
---
