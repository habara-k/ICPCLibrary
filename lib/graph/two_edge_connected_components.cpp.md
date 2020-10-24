---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/lowlink.cpp
    title: lib/graph/lowlink.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/two_edge_connected_components.test.cpp
    title: test/graph/two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/two_edge_connected_components.test.cpp
    title: test/yosupo-judge/two_edge_connected_components.test.cpp
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
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/lowlink.cpp\"\n\
    \n/**\n * @brief\n * \u6A4B\u3068\u95A2\u7BC0\u70B9\u3092O(n+m)\u3067\u5217\u6319\
    \n * \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u30B0\u30E9\u30D5\u3092\u6295\
    \u3052\u8FBC\u3080\u3068bridge\u3068articulation\u304C\u66F4\u65B0\u3055\u308C\
    \u308B\n * @author Md\n * @date 2020/10/20\n */\n\nstruct Lowlink {\n  vvi g;\n\
    \  int n;\n  vi ord, low;\n  vector<P> bridge;\n  vector<int> articulation;\n\
    \  int t = 0;\n\n  Lowlink(const vvi &G): g(G) {\n    n = SZ(g);\n    ord.resize(n,\
    \ INF);\n    low.resize(n, INF);\n\n    REP(i, n) {\n      if(ord[i] == INF) {\n\
    \        dfs(i, -1);\n      }\n    }\n  }\n\n  void dfs(int now, int prev) {\n\
    \    ord[now] = t;\n    low[now] = ord[now];\n    t++;\n    int d = 0;\n    bool\
    \ ar = false;\n    for(auto &nxt: g[now]) {\n      if(nxt == prev) continue;\n\
    \      if(ord[nxt] == INF) {\n        d++;\n        dfs(nxt, now);\n        chmin(low[now],\
    \ low[nxt]);\n        ar |= prev != -1 && ord[now] <= low[nxt];\n        if(ord[now]\
    \ < low[nxt]) {\n          if(now < nxt) bridge.emplace_back(now, nxt);\n    \
    \      else bridge.emplace_back(nxt, now);\n        }\n      } else {\n      \
    \  chmin(low[now], ord[nxt]);\n      }\n    }\n    ar |= prev == -1 && d >= 2;\n\
    \    if(ar) articulation.push_back(now);\n  }\n};\n#line 2 \"lib/graph/two_edge_connected_components.cpp\"\
    \n\n/**\n * @brief\n * \u5358\u7D14\u306A\u7121\u5411\u30B0\u30E9\u30D5g\u3092\
    \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\u3059\u308B\n *\n * \u5358\
    \u7D14\u3067\u306A\u3044\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3082\n * \
    \  \u81EA\u5DF1\u30EB\u30FC\u30D7: \u7121\u8996\n *   \u591A\u91CD\u8FBA: \u30E1\
    \u30E2\u3063\u3066\u304A\u3044\u3066\u3001\u6700\u5F8C\u306Bunionfind\n * \u3068\
    \u3059\u308B\u3068\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u304C\u307B\u307C\
    \u7DDA\u5F62\u3067\u6C42\u307E\u308B\n *\n * @author Md\n * @date 2020/10/21\n\
    \ *\n */\n\n\nstruct TwoEdgeCC {\n  vvi g;\n  int n;\n  Lowlink lowlink;\n  vi\
    \ comp;\n  int id = 0;\n\n  TwoEdgeCC(const vvi &g): g(g), lowlink(g) {\n    n\
    \ = SZ(g);\n    comp.resize(n, -1);\n    REP(i, n) {\n      if(comp[i] == -1)\
    \ {\n        dfs(i, -1);\n      }\n    }\n  }\n\n  vvi build_graph() {\n    vvi\
    \ t(id);\n    for(auto &e: lowlink.bridge) {\n      int u = comp[e.first];\n \
    \     int v = comp[e.second];\n      t[u].push_back(v);\n      t[v].push_back(u);\n\
    \    }\n    return t;\n  }\n\nprivate:\n  void dfs(int now, int prev) {\n    if(prev\
    \ != -1 && lowlink.ord[prev] >= lowlink.low[now]) {\n      comp[now] = comp[prev];\n\
    \    } else {\n      comp[now] = id;\n      id++;\n    }\n    for(auto &nxt: g[now])\
    \ {\n      if(comp[nxt] == -1) dfs(nxt, now);\n    }\n  }\n};\n\n"
  code: "#include \"./lowlink.cpp\"\n\n/**\n * @brief\n * \u5358\u7D14\u306A\u7121\
    \u5411\u30B0\u30E9\u30D5g\u3092\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\
    \u89E3\u3059\u308B\n *\n * \u5358\u7D14\u3067\u306A\u3044\u30B0\u30E9\u30D5\u306B\
    \u3064\u3044\u3066\u3082\n *   \u81EA\u5DF1\u30EB\u30FC\u30D7: \u7121\u8996\n\
    \ *   \u591A\u91CD\u8FBA: \u30E1\u30E2\u3063\u3066\u304A\u3044\u3066\u3001\u6700\
    \u5F8C\u306Bunionfind\n * \u3068\u3059\u308B\u3068\u4E8C\u91CD\u8FBA\u9023\u7D50\
    \u6210\u5206\u304C\u307B\u307C\u7DDA\u5F62\u3067\u6C42\u307E\u308B\n *\n * @author\
    \ Md\n * @date 2020/10/21\n *\n */\n\n\nstruct TwoEdgeCC {\n  vvi g;\n  int n;\n\
    \  Lowlink lowlink;\n  vi comp;\n  int id = 0;\n\n  TwoEdgeCC(const vvi &g): g(g),\
    \ lowlink(g) {\n    n = SZ(g);\n    comp.resize(n, -1);\n    REP(i, n) {\n   \
    \   if(comp[i] == -1) {\n        dfs(i, -1);\n      }\n    }\n  }\n\n  vvi build_graph()\
    \ {\n    vvi t(id);\n    for(auto &e: lowlink.bridge) {\n      int u = comp[e.first];\n\
    \      int v = comp[e.second];\n      t[u].push_back(v);\n      t[v].push_back(u);\n\
    \    }\n    return t;\n  }\n\nprivate:\n  void dfs(int now, int prev) {\n    if(prev\
    \ != -1 && lowlink.ord[prev] >= lowlink.low[now]) {\n      comp[now] = comp[prev];\n\
    \    } else {\n      comp[now] = id;\n      id++;\n    }\n    for(auto &nxt: g[now])\
    \ {\n      if(comp[nxt] == -1) dfs(nxt, now);\n    }\n  }\n};\n\n"
  dependsOn:
  - lib/graph/lowlink.cpp
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/two_edge_connected_components.cpp
  requiredBy: []
  timestamp: '2020-10-21 02:33:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/two_edge_connected_components.test.cpp
  - test/graph/two_edge_connected_components.test.cpp
documentation_of: lib/graph/two_edge_connected_components.cpp
layout: document
redirect_from:
- /library/lib/graph/two_edge_connected_components.cpp
- /library/lib/graph/two_edge_connected_components.cpp.html
title: lib/graph/two_edge_connected_components.cpp
---
