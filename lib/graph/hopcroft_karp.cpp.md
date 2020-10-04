---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/hopcroft_karp.test.cpp
    title: test/graph/hopcroft_karp.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/graph/template.cpp\"\n\n\n\n#line 1 \"lib/template.cpp\"\
    \n\n\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define REP(i, n)\
    \ for (int i=0; i<(n); ++i)\n#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)\n\
    #define FOR(i, a, n) for (int i=(a); i<(n); ++i)\n#define RFOR(i, a, n) for (int\
    \ i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n#define ALL(x)\
    \ (x).begin(),(x).end()\n\n#define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n#define\
    \ DEBUG(x) cerr<<#x<<\" = \"<<(x)<<\" (L\"<<__LINE__<<\")\"<<endl;\n\ntemplate<class\
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
    \n    return 0;\n}\n*/\n\n\n#line 5 \"lib/graph/template.cpp\"\n\ntemplate<typename\
    \ T>\nstruct edge {\n    int src, to;\n    T cost;\n};\n\ntemplate<typename T>\n\
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/hopcroft_karp.cpp\"\
    \n\n/**\n * @brief\n * HopcroftKarp(\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\
    \u5927\u30DE\u30C3\u30C1\u30F3\u30B0)\n * O(|E| sqrt(|V|))\n * |\u6700\u5927\u30DE\
    \u30C3\u30C1\u30F3\u30B0| + |\u6700\u5C0F\u8FBA\u30AB\u30D0\u30FC| = |V|\n * \uFF08\
    \u4E8C\u90E8\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\uFF09|\u6700\u5927\u30DE\
    \u30C3\u30C1\u30F3\u30B0| = |\u6700\u5C0F\u70B9\u30AB\u30D0\u30FC|\n * |\u6700\
    \u5927\u5B89\u5B9A\u96C6\u5408| + |\u6700\u5C0F\u70B9\u30AB\u30D0\u30FC| = |V|\n\
    \ *\n * @author Md\n * @date 2019/12\n * @details\n * 2020/04/14 \u30B3\u30E1\u30F3\
    \u30C8\u8FFD\u52A0 by Md\n */\n\nstruct HopcroftKarp {\n    vector<vector<int>>\
    \ g;\n    vector<int> d, mch;\n    vector<bool> used, vv;\n\n    HopcroftKarp(int\
    \ n, int m) : g(n), mch(m, -1), used(n) {}\n\n    void add_edge(int u, int v)\
    \ {\n        g[u].push_back(v);\n    }\n\n    void bfs() {\n        d.assign(g.size(),\
    \ -1);\n        queue<int> que;\n        for (int i = 0; i < (int)(g.size());\
    \ i++) {\n            if (!used[i]) {\n                que.emplace(i);\n     \
    \           d[i] = 0;\n            }\n        }\n\n        while (!que.empty())\
    \ {\n            int a = que.front();\n            que.pop();\n            for\
    \ (auto &b : g[a]) {\n                int c = mch[b];\n                if (c >=\
    \ 0 && d[c] == -1) {\n                    d[c] = d[a] + 1;\n                 \
    \   que.emplace(c);\n                }\n            }\n        }\n    }\n\n  \
    \  bool dfs(int a) {\n        vv[a] = true;\n        for (auto &b : g[a]) {\n\
    \            int c = mch[b];\n            if (c < 0 || (!vv[c] && d[c] == d[a]\
    \ + 1 && dfs(c))) {\n                mch[b] = a;\n                used[a] = true;\n\
    \                return true;\n            }\n        }\n        return false;\n\
    \    }\n\n    int bipartite_matching() {\n        int ret = 0;\n        while\
    \ (true) {\n            bfs();\n            vv.assign(g.size(), false);\n    \
    \        int flow = 0;\n            for (int i = 0; i < (int)(g.size()); i++)\
    \ {\n                if (!used[i] && dfs(i)) ++flow;\n            }\n        \
    \    if (flow == 0) return ret;\n            ret += flow;\n        }\n    }\n\
    };\n"
  code: "#include \"template.cpp\"\n\n/**\n * @brief\n * HopcroftKarp(\u4E8C\u90E8\
    \u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0)\n * O(|E|\
    \ sqrt(|V|))\n * |\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0| + |\u6700\u5C0F\u8FBA\
    \u30AB\u30D0\u30FC| = |V|\n * \uFF08\u4E8C\u90E8\u30B0\u30E9\u30D5\u306B\u3064\
    \u3044\u3066\uFF09|\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0| = |\u6700\u5C0F\
    \u70B9\u30AB\u30D0\u30FC|\n * |\u6700\u5927\u5B89\u5B9A\u96C6\u5408| + |\u6700\
    \u5C0F\u70B9\u30AB\u30D0\u30FC| = |V|\n *\n * @author Md\n * @date 2019/12\n *\
    \ @details\n * 2020/04/14 \u30B3\u30E1\u30F3\u30C8\u8FFD\u52A0 by Md\n */\n\n\
    struct HopcroftKarp {\n    vector<vector<int>> g;\n    vector<int> d, mch;\n \
    \   vector<bool> used, vv;\n\n    HopcroftKarp(int n, int m) : g(n), mch(m, -1),\
    \ used(n) {}\n\n    void add_edge(int u, int v) {\n        g[u].push_back(v);\n\
    \    }\n\n    void bfs() {\n        d.assign(g.size(), -1);\n        queue<int>\
    \ que;\n        for (int i = 0; i < (int)(g.size()); i++) {\n            if (!used[i])\
    \ {\n                que.emplace(i);\n                d[i] = 0;\n            }\n\
    \        }\n\n        while (!que.empty()) {\n            int a = que.front();\n\
    \            que.pop();\n            for (auto &b : g[a]) {\n                int\
    \ c = mch[b];\n                if (c >= 0 && d[c] == -1) {\n                 \
    \   d[c] = d[a] + 1;\n                    que.emplace(c);\n                }\n\
    \            }\n        }\n    }\n\n    bool dfs(int a) {\n        vv[a] = true;\n\
    \        for (auto &b : g[a]) {\n            int c = mch[b];\n            if (c\
    \ < 0 || (!vv[c] && d[c] == d[a] + 1 && dfs(c))) {\n                mch[b] = a;\n\
    \                used[a] = true;\n                return true;\n            }\n\
    \        }\n        return false;\n    }\n\n    int bipartite_matching() {\n \
    \       int ret = 0;\n        while (true) {\n            bfs();\n           \
    \ vv.assign(g.size(), false);\n            int flow = 0;\n            for (int\
    \ i = 0; i < (int)(g.size()); i++) {\n                if (!used[i] && dfs(i))\
    \ ++flow;\n            }\n            if (flow == 0) return ret;\n           \
    \ ret += flow;\n        }\n    }\n};\n"
  dependsOn:
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/hopcroft_karp.cpp
  requiredBy: []
  timestamp: '2020-06-14 10:29:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/hopcroft_karp.test.cpp
documentation_of: lib/graph/hopcroft_karp.cpp
layout: document
redirect_from:
- /library/lib/graph/hopcroft_karp.cpp
- /library/lib/graph/hopcroft_karp.cpp.html
title: lib/graph/hopcroft_karp.cpp
---
