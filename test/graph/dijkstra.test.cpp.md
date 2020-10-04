---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/dijkstra.cpp
    title: lib/graph/dijkstra.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"test/graph/dijkstra.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#line 1 \"lib/graph/template.cpp\"\n\n\n\n#line 1 \"lib/template.cpp\"\n\n\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define REP(i, n) for\
    \ (int i=0; i<(n); ++i)\n#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)\n\
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
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/dijkstra.cpp\"\
    \n\n/**\n * @brief\n * \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF(\u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9)\n * \u4E8C\u5206\u30D2\u30FC\u30D7(priority_queue)\u3092\
    \u4F7F\u3063\u3066O((E+V)logV)\n * @author ?\n * @date 2019/12\n *\n * @param[in]\
    \ g \u30B0\u30E9\u30D5\n * @param[in] s \u59CB\u70B9\n * @param[in] inf \u5230\
    \u9054\u4E0D\u53EF\u80FD\u3092\u8868\u3059\u7121\u9650\u5024\n * @return vector<T>\
    \ s\u304B\u3089\u305D\u308C\u305E\u308C\u306E\u9802\u70B9\u3078\u306E\u6700\u77ED\
    \u8DEF\n *\n * @details\n * 2020/04/07 \u30B3\u30E1\u30F3\u30C8\u8FFD\u52A0\u3001\
    \u30C6\u30B9\u30C8\u6709\u7121\u306E\u30C1\u30A7\u30C3\u30AF by Md\n * 2020/05/04\
    \ inf \u306B\u4F7F\u3046\u5024\u3092\u660E\u793A\u7684\u306B\u6E21\u3059. by haraba-k\n\
    \ */\n\ntemplate<typename T>\nvector<T> dijkstra(const Graph<T> &g, int s, T inf)\
    \ {\n    vector<T> d(g.size(), inf);\n\n    using Pi = pair<T, int>;\n    priority_queue<Pi,\
    \ vector<Pi>, greater<Pi>> que;\n    d[s] = 0;\n    que.emplace(d[s], s);\n  \
    \  while (!que.empty()) {\n        T cost;\n        int v;\n        tie(cost,\
    \ v) = que.top();\n        que.pop();\n        if (d[v] < cost) continue;\n  \
    \      for (auto &e : g[v]) {\n            auto nxt = cost + e.cost;\n       \
    \     if (d[e.to] > nxt) {\n                d[e.to] = nxt;\n                que.emplace(nxt,\
    \ e.to);\n            }\n        }\n    }\n    return d;\n}\n#line 4 \"test/graph/dijkstra.test.cpp\"\
    \n\nint main() {\n    int V, E, R;\n    cin >> V >> E >> R;\n    Graph<int> g(V);\n\
    \    for (int i = 0; i < E; ++i) {\n        int a, b, c;\n        cin >> a >>\
    \ b >> c;\n        g[a].push_back({a,b,c});\n    }\n    for (auto &dist : dijkstra(g,\
    \ R, INF)) {\n        if (dist == INF) puts(\"INF\");\n        else cout << dist\
    \ << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include \"../../lib/graph/dijkstra.cpp\"\n\nint main() {\n    int V, E, R;\n\
    \    cin >> V >> E >> R;\n    Graph<int> g(V);\n    for (int i = 0; i < E; ++i)\
    \ {\n        int a, b, c;\n        cin >> a >> b >> c;\n        g[a].push_back({a,b,c});\n\
    \    }\n    for (auto &dist : dijkstra(g, R, INF)) {\n        if (dist == INF)\
    \ puts(\"INF\");\n        else cout << dist << endl;\n    }\n}\n"
  dependsOn:
  - lib/graph/dijkstra.cpp
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dijkstra.test.cpp
- /verify/test/graph/dijkstra.test.cpp.html
title: test/graph/dijkstra.test.cpp
---
