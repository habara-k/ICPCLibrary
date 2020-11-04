---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/ford_fulkerson.test.cpp
    title: test/graph/ford_fulkerson.test.cpp
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/graph/ford_fulkerson.cpp\"\
    \n\r\n/**\r\n * @brief\r\n * \u6700\u5927\u6D41 O(FE)\r\n *\r\n * @author Md\r\
    \n * @date 2020/11/03\r\n *\r\n */\r\ntemplate <typename T>\r\nstruct FordFulkerson\
    \ {\r\n  struct Edge {\r\n    int to, rev;\r\n    T cap;\r\n  };\r\n\r\n  int\
    \ n;\r\n  vector<vector<Edge>> g;\r\n  vector<bool> used;\r\n\r\n  FordFulkerson(int\
    \ n): n(n) {\r\n    g.resize(n);\r\n    used.resize(n);\r\n  }\r\n\r\n  void add_edge(int\
    \ from, int to, T cap) {\r\n    g[from].push_back({to, SZ(g[to]), cap});\r\n \
    \   g[to].push_back({from, SZ(g[from])-1, 0});\r\n  }\r\n\r\n  T max_flow(int\
    \ s, int t) {\r\n    int flow = 0, f = 0;\r\n    while(1){\r\n      fill(ALL(used),\
    \ false);\r\n      f = dfs(s, t, INF);\r\n      if(f == 0) return flow;\r\n  \
    \    flow += f;\r\n    }\r\n  }\r\n\r\nprivate:\r\n  int dfs(int now, int t, int\
    \ f) {\r\n    if(now == t) return f;\r\n    used[now] = true;\r\n    for(auto\
    \ &e: g[now]) {\r\n      if(used[e.to] || e.cap <= 0) continue;\r\n      int d\
    \ = dfs(e.to, t, min(f, e.cap));\r\n      if(d > 0) {\r\n        e.cap -= d;\r\
    \n        g[e.to][e.rev].cap += d;\r\n        return d;\r\n      }\r\n    }\r\n\
    \    return 0;\r\n  }\r\n\r\n};\r\n"
  code: "#include \"../template.cpp\"\r\n\r\n/**\r\n * @brief\r\n * \u6700\u5927\u6D41\
    \ O(FE)\r\n *\r\n * @author Md\r\n * @date 2020/11/03\r\n *\r\n */\r\ntemplate\
    \ <typename T>\r\nstruct FordFulkerson {\r\n  struct Edge {\r\n    int to, rev;\r\
    \n    T cap;\r\n  };\r\n\r\n  int n;\r\n  vector<vector<Edge>> g;\r\n  vector<bool>\
    \ used;\r\n\r\n  FordFulkerson(int n): n(n) {\r\n    g.resize(n);\r\n    used.resize(n);\r\
    \n  }\r\n\r\n  void add_edge(int from, int to, T cap) {\r\n    g[from].push_back({to,\
    \ SZ(g[to]), cap});\r\n    g[to].push_back({from, SZ(g[from])-1, 0});\r\n  }\r\
    \n\r\n  T max_flow(int s, int t) {\r\n    int flow = 0, f = 0;\r\n    while(1){\r\
    \n      fill(ALL(used), false);\r\n      f = dfs(s, t, INF);\r\n      if(f ==\
    \ 0) return flow;\r\n      flow += f;\r\n    }\r\n  }\r\n\r\nprivate:\r\n  int\
    \ dfs(int now, int t, int f) {\r\n    if(now == t) return f;\r\n    used[now]\
    \ = true;\r\n    for(auto &e: g[now]) {\r\n      if(used[e.to] || e.cap <= 0)\
    \ continue;\r\n      int d = dfs(e.to, t, min(f, e.cap));\r\n      if(d > 0) {\r\
    \n        e.cap -= d;\r\n        g[e.to][e.rev].cap += d;\r\n        return d;\r\
    \n      }\r\n    }\r\n    return 0;\r\n  }\r\n\r\n};\r\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/ford_fulkerson.cpp
  requiredBy: []
  timestamp: '2020-11-04 00:46:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/ford_fulkerson.test.cpp
documentation_of: lib/graph/ford_fulkerson.cpp
layout: document
redirect_from:
- /library/lib/graph/ford_fulkerson.cpp
- /library/lib/graph/ford_fulkerson.cpp.html
title: lib/graph/ford_fulkerson.cpp
---
