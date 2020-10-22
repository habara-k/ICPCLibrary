---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/max_flow_with_lower_limit.cpp
    title: lib/graph/max_flow_with_lower_limit.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dinic.test.cpp
    title: test/graph/dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/max_flow_with_lower_limit.test.cpp
    title: test/graph/max_flow_with_lower_limit.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF"
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
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/dinic.cpp\"\n\n\
    /**\n * @brief\n * Dinic\u6CD5(\u6700\u5927\u6D41)\n * \u59CB\u70B9\u304B\u3089\
    \u7D42\u70B9\u307E\u3067\u30D5\u30ED\u30FC\u3092\u6D41\u3057\u305F\u3068\u304D\
    \u306E\u6700\u5927\u6D41\u91CF\u3092\u6C42\u3081\u308B\n * O(EV^2) \uFF08\u3060\
    \u3044\u305F\u3044\u3082\u3063\u3068\u306F\u3084\u3044\uFF09\n * @author Md\n\
    \ * @date 2019/12\n * @detail\n * 2020/04/07 \u30B3\u30E1\u30F3\u30C8\u8FFD\u52A0\
    \ by Md\n * \u69CB\u7BC9\u3057\u305F\u3044\n */\n\ntemplate <typename T>\nstruct\
    \ Dinic {\n  int sz;\n  T inf = numeric_limits<T>::max();\n  vector<int> level,\
    \ iter;\n\n  struct Edge {\n    int to, rev;\n    T cap;\n    Edge(int to, int\
    \ rev, T cap): to(to), rev(rev), cap(cap) {}\n  };\n  vector<vector<Edge>> g;\n\
    \n  /**\n   * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n   * @param V\
    \ \u9802\u70B9\u6570\n   */\n  Dinic(int V): sz(V) {\n    g.resize(V);\n    level.resize(V);\n\
    \    iter.resize(V);\n  };\n\n  /**\n   * @brief \u8FBA\u3092\u8FFD\u52A0\n  \
    \ * @param[in] from \u59CB\u70B9\n   * @param[in] to \u7D42\u70B9\n   * @param[in]\
    \ cap \u5BB9\u91CF\n   */\n  void add_edge(int from, int to, T cap) {\n    g[from].emplace_back(to,\
    \ (int)(g[to].size()), cap);\n    g[to].emplace_back(from, (int)(g[from].size())-1,\
    \ 0);\n  }\n\n  /**\n   * @brief \u6700\u5927\u6D41\u3092\u6C42\u3081\u308B\n\
    \   * @param[in] s \u59CB\u70B9\n   * @param[in] t \u7D42\u70B9\n   */\n  T max_flow(int\
    \ s, int t) {\n    T flow = 0;\n    while(1) {\n      bfs(s);\n      if(level[t]\
    \ < 0) return flow;\n      iter.assign(sz, 0);\n      T f = dfs(s, t, inf);\n\
    \      while(f > 0) {\n        flow += f;\n        f = dfs(s, t, inf);\n     \
    \ }\n    }\n  }\n\nprivate:\n  void bfs(int s) {\n    level.assign(sz, -1);\n\
    \    level[s] = 0;\n    queue<int> que;\n    que.push(s);\n    while(!que.empty())\
    \ {\n      int now = que.front(); que.pop();\n      for(auto &e: g[now]) {\n \
    \       if(e.cap > 0 && level[e.to] < 0) {\n          level[e.to] = level[now]\
    \ + 1;\n          que.push(e.to);\n        }\n      }\n    }\n  }\n\n  T dfs(int\
    \ s, int t, T flow) {\n    if(s == t) return flow;\n    for(int i=iter[s];i<(int)(g[s].size());++i)\
    \ {\n      iter[s] = i;\n      auto e = g[s][i];\n      if(e.cap > 0 && level[s]\
    \ < level[e.to]) {\n        T d = dfs(e.to, t, min(flow, e.cap));\n        if(d\
    \ > 0) {\n          g[s][i].cap -= d;\n          g[e.to][e.rev].cap += d;\n  \
    \        return d;\n        }\n      }\n    }\n    return 0;\n  }\n};\n"
  code: "#include \"template.cpp\"\n\n/**\n * @brief\n * Dinic\u6CD5(\u6700\u5927\u6D41\
    )\n * \u59CB\u70B9\u304B\u3089\u7D42\u70B9\u307E\u3067\u30D5\u30ED\u30FC\u3092\
    \u6D41\u3057\u305F\u3068\u304D\u306E\u6700\u5927\u6D41\u91CF\u3092\u6C42\u3081\
    \u308B\n * O(EV^2) \uFF08\u3060\u3044\u305F\u3044\u3082\u3063\u3068\u306F\u3084\
    \u3044\uFF09\n * @author Md\n * @date 2019/12\n * @detail\n * 2020/04/07 \u30B3\
    \u30E1\u30F3\u30C8\u8FFD\u52A0 by Md\n * \u69CB\u7BC9\u3057\u305F\u3044\n */\n\
    \ntemplate <typename T>\nstruct Dinic {\n  int sz;\n  T inf = numeric_limits<T>::max();\n\
    \  vector<int> level, iter;\n\n  struct Edge {\n    int to, rev;\n    T cap;\n\
    \    Edge(int to, int rev, T cap): to(to), rev(rev), cap(cap) {}\n  };\n  vector<vector<Edge>>\
    \ g;\n\n  /**\n   * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n   * @param\
    \ V \u9802\u70B9\u6570\n   */\n  Dinic(int V): sz(V) {\n    g.resize(V);\n   \
    \ level.resize(V);\n    iter.resize(V);\n  };\n\n  /**\n   * @brief \u8FBA\u3092\
    \u8FFD\u52A0\n   * @param[in] from \u59CB\u70B9\n   * @param[in] to \u7D42\u70B9\
    \n   * @param[in] cap \u5BB9\u91CF\n   */\n  void add_edge(int from, int to, T\
    \ cap) {\n    g[from].emplace_back(to, (int)(g[to].size()), cap);\n    g[to].emplace_back(from,\
    \ (int)(g[from].size())-1, 0);\n  }\n\n  /**\n   * @brief \u6700\u5927\u6D41\u3092\
    \u6C42\u3081\u308B\n   * @param[in] s \u59CB\u70B9\n   * @param[in] t \u7D42\u70B9\
    \n   */\n  T max_flow(int s, int t) {\n    T flow = 0;\n    while(1) {\n     \
    \ bfs(s);\n      if(level[t] < 0) return flow;\n      iter.assign(sz, 0);\n  \
    \    T f = dfs(s, t, inf);\n      while(f > 0) {\n        flow += f;\n       \
    \ f = dfs(s, t, inf);\n      }\n    }\n  }\n\nprivate:\n  void bfs(int s) {\n\
    \    level.assign(sz, -1);\n    level[s] = 0;\n    queue<int> que;\n    que.push(s);\n\
    \    while(!que.empty()) {\n      int now = que.front(); que.pop();\n      for(auto\
    \ &e: g[now]) {\n        if(e.cap > 0 && level[e.to] < 0) {\n          level[e.to]\
    \ = level[now] + 1;\n          que.push(e.to);\n        }\n      }\n    }\n  }\n\
    \n  T dfs(int s, int t, T flow) {\n    if(s == t) return flow;\n    for(int i=iter[s];i<(int)(g[s].size());++i)\
    \ {\n      iter[s] = i;\n      auto e = g[s][i];\n      if(e.cap > 0 && level[s]\
    \ < level[e.to]) {\n        T d = dfs(e.to, t, min(flow, e.cap));\n        if(d\
    \ > 0) {\n          g[s][i].cap -= d;\n          g[e.to][e.rev].cap += d;\n  \
    \        return d;\n        }\n      }\n    }\n    return 0;\n  }\n};"
  dependsOn:
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/dinic.cpp
  requiredBy:
  - lib/graph/max_flow_with_lower_limit.cpp
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/max_flow_with_lower_limit.test.cpp
  - test/graph/dinic.test.cpp
documentation_of: lib/graph/dinic.cpp
layout: document
redirect_from:
- /library/lib/graph/dinic.cpp
- /library/lib/graph/dinic.cpp.html
title: "\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF"
---
