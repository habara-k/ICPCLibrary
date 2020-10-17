---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/tree/lowest_common_ancestor.cpp
    title: LCA
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"test/tree/lowest_common_ancestor.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\n\n#line\
    \ 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/tree/lowest_common_ancestor.cpp\"\n\n\
    /**\n * @brief LCA\n * @author habara-k\n * @date 2020/10/15\n */\nstruct LCA\
    \ {\n\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. O(VlogV)\n\
    \     * @param[in] g \u7121\u5411\u6728\n     * @param[in] root \u6839\n     */\n\
    \    LCA(const vector<vector<int>> &g, int root = 0) :\n            n(g.size()),\
    \ m(log2(n)), depth(n),\n            g(g), par(m + 1, vector<int>(n, -1)) {\n\n\
    \        dfs(root, -1, 0);\n\n        for (int k = 0; k < m; ++k) {\n        \
    \    for (int v = 0; v < n; ++v) {\n                if (par[k][v] != -1) {\n \
    \                   par[k + 1][v] = par[k][par[k][v]];\n                }\n  \
    \          }\n        }\n    }\n\n    /**\n     * @brief lca \u3092\u53D6\u5F97\
    \u3059\u308B. O(logV)\n     */\n    int query(int u, int v) {\n        if (depth[u]\
    \ > depth[v]) swap(u, v);\n        for (int k = 0; k <= m; ++k) {\n          \
    \  if ((depth[v] - depth[u]) >> k & 1) {\n                v = par[k][v];\n   \
    \         }\n        }\n        if (u == v) return u;\n        for (int k = m;\
    \ k >= 0; --k) {\n            if (par[k][u] != par[k][v]) {\n                u\
    \ = par[k][u];\n                v = par[k][v];\n            }\n        }\n   \
    \     return par[0][u];\n    }\n\n    /**\n     * @brief \u9802\u70B9u,v\u9593\
    \u306E\u8DDD\u96E2\u3092\u53D6\u5F97\u3059\u308B. O(logV)\n     */\n    int dist(int\
    \ u, int v) {\n        return depth[u] + depth[v] - 2 * depth[query(u,v)];\n \
    \   }\n\nprivate:\n    int n, m;\n    vector<int> depth;\n    vector<vector<int>>\
    \ g, par;\n\n    void dfs(int u, int p, int d) {\n        depth[u] = d;\n    \
    \    par[0][u] = p;\n        for (auto v : g[u]) {\n            if (v != p) dfs(v,\
    \ u, d + 1);\n        }\n    }\n};\n\n#line 4 \"test/tree/lowest_common_ancestor.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N;\n    vector<vector<int>> g(N);\n\
    \    for(int i = 0; i < N; i++) {\n        int k; cin >> k;\n        while (k--)\
    \ {\n            int c; cin >> c;\n            g[i].push_back(c);\n        }\n\
    \    }\n    LCA lca(g);\n    cin >> Q;\n    while (Q--) {\n        int x, y; cin\
    \ >> x >> y;\n        printf(\"%d\\n\", lca.query(x, y));\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#include \"../../lib/tree/lowest_common_ancestor.cpp\"\n\nint main() {\n \
    \   int N, Q;\n    cin >> N;\n    vector<vector<int>> g(N);\n    for(int i = 0;\
    \ i < N; i++) {\n        int k; cin >> k;\n        while (k--) {\n           \
    \ int c; cin >> c;\n            g[i].push_back(c);\n        }\n    }\n    LCA\
    \ lca(g);\n    cin >> Q;\n    while (Q--) {\n        int x, y; cin >> x >> y;\n\
    \        printf(\"%d\\n\", lca.query(x, y));\n    }\n}\n"
  dependsOn:
  - lib/tree/lowest_common_ancestor.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/tree/lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '2020-10-16 15:26:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/tree/lowest_common_ancestor.test.cpp
- /verify/test/tree/lowest_common_ancestor.test.cpp.html
title: test/tree/lowest_common_ancestor.test.cpp
---