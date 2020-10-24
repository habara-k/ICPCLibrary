---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/two_sat.cpp
    title: lib/graph/two_sat.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/scc.test.cpp
    title: test/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/two_sat.test.cpp
    title: test/graph/two_sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/two_sat.test.cpp
    title: test/yosupo-judge/two_sat.test.cpp
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
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/scc.cpp\"\n\n\
    /**\n * @brief\n * \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @author habara-k\n\
    \ * @date 2020/08\n *\n * @param[in] g \u30B0\u30E9\u30D5\n *\n * @details\n *\
    \ comp: vertex -> component_id\n * graph: graph of components\n */\n\nstruct StronglyConnectedComponents\
    \ {\n    int n;\n    vector<vector<int>> g, rg, graph;\n    vector<int> ord, used,\
    \ comp;\n\n    StronglyConnectedComponents(const vector<vector<int>>& g) :\n \
    \           n(g.size()), g(g), rg(n), used(n), comp(n, -1)\n    {\n        for\
    \ (int i = 0; i < n; ++i) {\n            for (int to : g[i]) {\n             \
    \   rg[to].push_back(i);\n            }\n        }\n    }\n\n    void build()\
    \ {\n        for (int i = 0; i < n; ++i) dfs(i);\n        reverse(ord.begin(),\
    \ ord.end());\n        int ptr = 0;\n        for (int i : ord) if (comp[i] ==\
    \ -1) rdfs(i, ptr), ptr++;\n\n        graph.resize(ptr);\n        for (int i =\
    \ 0; i < n; ++i) {\n            for (int to : g[i]) {\n                int x =\
    \ comp[i], y = comp[to];\n                if (x == y) continue;\n            \
    \    graph[x].push_back(y);\n            }\n        }\n        for (auto& v :\
    \ graph) {\n            sort(v.begin(), v.end());\n            v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n        }\n    }\n\nprivate:\n    void dfs(int idx) {\n\
    \        if (used[idx]) return;\n        used[idx] = true;\n        for (int to\
    \ : g[idx]) dfs(to);\n        ord.push_back(idx);\n    }\n\n    void rdfs(int\
    \ idx, int cnt) {\n        if (comp[idx] != -1) return;\n        comp[idx] = cnt;\n\
    \        for (int to : rg[idx]) rdfs(to, cnt);\n    }\n};\n\n"
  code: "#include \"template.cpp\"\n\n/**\n * @brief\n * \u5F37\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\n * @author habara-k\n * @date 2020/08\n *\n * @param[in] g \u30B0\
    \u30E9\u30D5\n *\n * @details\n * comp: vertex -> component_id\n * graph: graph\
    \ of components\n */\n\nstruct StronglyConnectedComponents {\n    int n;\n   \
    \ vector<vector<int>> g, rg, graph;\n    vector<int> ord, used, comp;\n\n    StronglyConnectedComponents(const\
    \ vector<vector<int>>& g) :\n            n(g.size()), g(g), rg(n), used(n), comp(n,\
    \ -1)\n    {\n        for (int i = 0; i < n; ++i) {\n            for (int to :\
    \ g[i]) {\n                rg[to].push_back(i);\n            }\n        }\n  \
    \  }\n\n    void build() {\n        for (int i = 0; i < n; ++i) dfs(i);\n    \
    \    reverse(ord.begin(), ord.end());\n        int ptr = 0;\n        for (int\
    \ i : ord) if (comp[i] == -1) rdfs(i, ptr), ptr++;\n\n        graph.resize(ptr);\n\
    \        for (int i = 0; i < n; ++i) {\n            for (int to : g[i]) {\n  \
    \              int x = comp[i], y = comp[to];\n                if (x == y) continue;\n\
    \                graph[x].push_back(y);\n            }\n        }\n        for\
    \ (auto& v : graph) {\n            sort(v.begin(), v.end());\n            v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n        }\n    }\n\nprivate:\n    void dfs(int idx) {\n\
    \        if (used[idx]) return;\n        used[idx] = true;\n        for (int to\
    \ : g[idx]) dfs(to);\n        ord.push_back(idx);\n    }\n\n    void rdfs(int\
    \ idx, int cnt) {\n        if (comp[idx] != -1) return;\n        comp[idx] = cnt;\n\
    \        for (int to : rg[idx]) rdfs(to, cnt);\n    }\n};\n\n"
  dependsOn:
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/scc.cpp
  requiredBy:
  - lib/graph/two_sat.cpp
  timestamp: '2020-08-24 14:33:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/two_sat.test.cpp
  - test/graph/two_sat.test.cpp
  - test/graph/scc.test.cpp
documentation_of: lib/graph/scc.cpp
layout: document
redirect_from:
- /library/lib/graph/scc.cpp
- /library/lib/graph/scc.cpp.html
title: lib/graph/scc.cpp
---