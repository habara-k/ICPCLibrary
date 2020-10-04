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
    path: test/graph/bfs01.test.cpp
    title: test/graph/bfs01.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/590/problem/C
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
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/bfs01.cpp\"\n\n\
    // verify: https://codeforces.com/contest/590/problem/C\n\n/**\n * @brief\n *\
    \ 01-BFS\n * \u8FBA\u306E\u91CD\u307F\u304C01\u306E\u6642\u306BO(E+V)\u3067\u5358\
    \u4E00\u59CB\u70B9\u6700\u77ED\u8DEF\u3092\u3084\u308B\n * @author Md\n * @date\
    \ 2019/12\n * @param[in] g \u30B0\u30E9\u30D5\n * @param[in] s \u59CB\u70B9\n\
    \ * @return vector<T> s\u304B\u3089\u305D\u308C\u305E\u308C\u306E\u9802\u70B9\u3078\
    \u306E\u6700\u77ED\u8DEF\n * \n * @details\n * 2020/04/07\n * \u30BD\u30FC\u30B9\
    \u30B3\u30FC\u30C9\u4FEE\u6B63\u3001\u30B3\u30E1\u30F3\u30C8\u8FFD\u52A0\u3001\
    \u30C6\u30B9\u30C8\u8FFD\u52A0 by Md\n * \u30C6\u30B9\u30C8\u306Fdijkstra\u306E\
    \u3082\u306E\u3092\u6D41\u7528(01-BFS\u3067\u3057\u304B\u901A\u3089\u306A\u3044\
    \u554F\u984C\u3001\u3042\u308B\uFF1F)\n */\n\ntemplate <typename T>\nstd::vector<T>\
    \ bfs01(const Graph<T> &g, int s) {\n    const T INF = numeric_limits<T>::max();\n\
    \    std::vector<T> res(SZ(g), INF);\n    deque<pair<T, int>> deq;\n    res[s]\
    \ = 0;\n    deq.push_back({0, s});\n    while(!deq.empty()) {\n        auto elm\
    \ = deq.front(); deq.pop_front();\n        T cost = elm.first;\n        int now\
    \ = elm.second;\n        if(cost > res[now]) continue;\n\n        for(auto &ne:\
    \ g[now]) {\n            int nxt = ne.to;\n            if(res[nxt] > cost + ne.cost)\
    \ {\n                res[nxt] = cost + ne.cost;\n                if(ne.cost ==\
    \ 0) {\n                    deq.push_front({res[nxt], nxt});\n               \
    \ } else {\n                    deq.push_back({res[nxt], nxt});\n            \
    \    }\n            }\n        }\n    }\n    \n    return res;\n}\n"
  code: "#include \"template.cpp\"\n\n// verify: https://codeforces.com/contest/590/problem/C\n\
    \n/**\n * @brief\n * 01-BFS\n * \u8FBA\u306E\u91CD\u307F\u304C01\u306E\u6642\u306B\
    O(E+V)\u3067\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF\u3092\u3084\u308B\n * @author\
    \ Md\n * @date 2019/12\n * @param[in] g \u30B0\u30E9\u30D5\n * @param[in] s \u59CB\
    \u70B9\n * @return vector<T> s\u304B\u3089\u305D\u308C\u305E\u308C\u306E\u9802\
    \u70B9\u3078\u306E\u6700\u77ED\u8DEF\n * \n * @details\n * 2020/04/07\n * \u30BD\
    \u30FC\u30B9\u30B3\u30FC\u30C9\u4FEE\u6B63\u3001\u30B3\u30E1\u30F3\u30C8\u8FFD\
    \u52A0\u3001\u30C6\u30B9\u30C8\u8FFD\u52A0 by Md\n * \u30C6\u30B9\u30C8\u306F\
    dijkstra\u306E\u3082\u306E\u3092\u6D41\u7528(01-BFS\u3067\u3057\u304B\u901A\u3089\
    \u306A\u3044\u554F\u984C\u3001\u3042\u308B\uFF1F)\n */\n\ntemplate <typename T>\n\
    std::vector<T> bfs01(const Graph<T> &g, int s) {\n    const T INF = numeric_limits<T>::max();\n\
    \    std::vector<T> res(SZ(g), INF);\n    deque<pair<T, int>> deq;\n    res[s]\
    \ = 0;\n    deq.push_back({0, s});\n    while(!deq.empty()) {\n        auto elm\
    \ = deq.front(); deq.pop_front();\n        T cost = elm.first;\n        int now\
    \ = elm.second;\n        if(cost > res[now]) continue;\n\n        for(auto &ne:\
    \ g[now]) {\n            int nxt = ne.to;\n            if(res[nxt] > cost + ne.cost)\
    \ {\n                res[nxt] = cost + ne.cost;\n                if(ne.cost ==\
    \ 0) {\n                    deq.push_front({res[nxt], nxt});\n               \
    \ } else {\n                    deq.push_back({res[nxt], nxt});\n            \
    \    }\n            }\n        }\n    }\n    \n    return res;\n}"
  dependsOn:
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/bfs01.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/bfs01.test.cpp
documentation_of: lib/graph/bfs01.cpp
layout: document
redirect_from:
- /library/lib/graph/bfs01.cpp
- /library/lib/graph/bfs01.cpp.html
title: lib/graph/bfs01.cpp
---
