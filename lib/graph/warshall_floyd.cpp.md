---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/warshall_floyd.cpp\"\
    \n\n/**\n * @brief\n * \u5168\u70B9\u5BFE\u9593\u6700\u77ED\u7D4C\u8DEF(\u30EF\
    \u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9)\n * O(V^3)\n * @author ?\n *\
    \ @date ?\n *\n * @param[in] g \u30B0\u30E9\u30D5(\u96A3\u63A5\u884C\u5217)\n\
    \ * @param[in] inf \u5230\u9054\u4E0D\u53EF\u80FD\u3092\u8868\u3059\u7121\u9650\
    \u5024\n * @param[out] g \u6700\u77ED\u8DDD\u96E2(\u96A3\u63A5\u884C\u5217)\n\
    \ *\n * @details\n * 2020/05/04 \u30B3\u30E1\u30F3\u30C8\u8FFD\u52A0, inf \u306B\
    \u4F7F\u3046\u5024\u3092\u660E\u793A\u7684\u306B\u6E21\u3059. by habara-k\n */\n\
    \ntemplate<typename T>\nvoid warshall_floyd(vector<vector<T>> &g, T inf) {\n \
    \   int n = g.size();\n    for (int k = 0; k < n; k++) {\n        for (int i =\
    \ 0; i < n; i++) {\n            for (int j = 0; j < n; j++) {\n              \
    \  if (g[i][k] == inf or g[k][j] == inf) continue;\n                g[i][j] =\
    \ min(g[i][j], g[i][k] + g[k][j]);\n            }\n        }\n    }\n}\n"
  code: "#include \"template.cpp\"\n\n/**\n * @brief\n * \u5168\u70B9\u5BFE\u9593\u6700\
    \u77ED\u7D4C\u8DEF(\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9)\n *\
    \ O(V^3)\n * @author ?\n * @date ?\n *\n * @param[in] g \u30B0\u30E9\u30D5(\u96A3\
    \u63A5\u884C\u5217)\n * @param[in] inf \u5230\u9054\u4E0D\u53EF\u80FD\u3092\u8868\
    \u3059\u7121\u9650\u5024\n * @param[out] g \u6700\u77ED\u8DDD\u96E2(\u96A3\u63A5\
    \u884C\u5217)\n *\n * @details\n * 2020/05/04 \u30B3\u30E1\u30F3\u30C8\u8FFD\u52A0\
    , inf \u306B\u4F7F\u3046\u5024\u3092\u660E\u793A\u7684\u306B\u6E21\u3059. by habara-k\n\
    \ */\n\ntemplate<typename T>\nvoid warshall_floyd(vector<vector<T>> &g, T inf)\
    \ {\n    int n = g.size();\n    for (int k = 0; k < n; k++) {\n        for (int\
    \ i = 0; i < n; i++) {\n            for (int j = 0; j < n; j++) {\n          \
    \      if (g[i][k] == inf or g[k][j] == inf) continue;\n                g[i][j]\
    \ = min(g[i][j], g[i][k] + g[k][j]);\n            }\n        }\n    }\n}\n"
  dependsOn:
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/warshall_floyd.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/warshall_floyd.test.cpp
documentation_of: lib/graph/warshall_floyd.cpp
layout: document
redirect_from:
- /library/lib/graph/warshall_floyd.cpp
- /library/lib/graph/warshall_floyd.cpp.html
title: lib/graph/warshall_floyd.cpp
---