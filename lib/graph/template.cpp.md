---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/bfs01.cpp
    title: lib/graph/bfs01.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/dijkstra.cpp
    title: lib/graph/dijkstra.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/dinic.cpp
    title: "\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF"
  - icon: ':heavy_check_mark:'
    path: lib/graph/hopcroft_karp.cpp
    title: lib/graph/hopcroft_karp.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/kruskal.cpp
    title: lib/graph/kruskal.cpp
  - icon: ':warning:'
    path: lib/graph/lowlink.cpp
    title: lib/graph/lowlink.cpp
  - icon: ':warning:'
    path: lib/graph/maximum_clique.cpp
    title: lib/graph/maximum_clique.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/primal_dual.cpp
    title: lib/graph/primal_dual.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/scc.cpp
    title: lib/graph/scc.cpp
  - icon: ':warning:'
    path: lib/graph/topological_sort.cpp
    title: lib/graph/topological_sort.cpp
  - icon: ':warning:'
    path: lib/graph/twoconnectedcomponents.cpp
    title: lib/graph/twoconnectedcomponents.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/warshall_floyd.cpp
    title: lib/graph/warshall_floyd.cpp
  - icon: ':warning:'
    path: test/graph/maximum_clique.cpp
    title: test/graph/maximum_clique.cpp
  - icon: ':warning:'
    path: test/graph/topological_sort.cpp
    title: test/graph/topological_sort.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs01.test.cpp
    title: test/graph/bfs01.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/dinic.test.cpp
    title: test/graph/dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/hopcroft_karp.test.cpp
    title: test/graph/hopcroft_karp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal.test.cpp
    title: test/graph/kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/primal_dual.test.cpp
    title: test/graph/primal_dual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/scc.test.cpp
    title: test/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/warshall_floyd.test.cpp
    title: test/graph/warshall_floyd.test.cpp
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
    using Graph = vector<vector<edge<T>>>;\n\n\n"
  code: "#ifndef GRAPH_TEMPLATE\n#define GRAPH_TEMPLATE\n\n#include \"../template.cpp\"\
    \n\ntemplate<typename T>\nstruct edge {\n    int src, to;\n    T cost;\n};\n\n\
    template<typename T>\nusing Graph = vector<vector<edge<T>>>;\n\n#endif\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/template.cpp
  requiredBy:
  - lib/graph/bfs01.cpp
  - lib/graph/dijkstra.cpp
  - lib/graph/scc.cpp
  - lib/graph/lowlink.cpp
  - lib/graph/hopcroft_karp.cpp
  - lib/graph/maximum_clique.cpp
  - lib/graph/kruskal.cpp
  - lib/graph/dinic.cpp
  - lib/graph/topological_sort.cpp
  - lib/graph/primal_dual.cpp
  - lib/graph/twoconnectedcomponents.cpp
  - lib/graph/warshall_floyd.cpp
  - test/graph/maximum_clique.cpp
  - test/graph/topological_sort.cpp
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dijkstra.test.cpp
  - test/graph/bfs01.test.cpp
  - test/graph/warshall_floyd.test.cpp
  - test/graph/dinic.test.cpp
  - test/graph/scc.test.cpp
  - test/graph/hopcroft_karp.test.cpp
  - test/graph/kruskal.test.cpp
  - test/graph/primal_dual.test.cpp
documentation_of: lib/graph/template.cpp
layout: document
redirect_from:
- /library/lib/graph/template.cpp
- /library/lib/graph/template.cpp.html
title: lib/graph/template.cpp
---
