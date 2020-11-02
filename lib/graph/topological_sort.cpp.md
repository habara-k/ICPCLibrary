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
  - icon: ':warning:'
    path: test/graph/topological_sort.cpp
    title: test/graph/topological_sort.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/topological_sort.cpp\"\
    \n\n/*\n * ord\u306B\u306F\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
    \u3055\u308C\u305F\u9806\u756A\u3067\u9802\u70B9\u756A\u53F7\u304C\u5165\u308B\
    \n * DAG\u3067\u306A\u3051\u308C\u3070\u7A7A\u306E\u914D\u5217\u3092\u8FD4\u3059\
    \n */\n\nvector<int> topological_sort(const vector<vector<int>>& G) {\n    vector<int>\
    \ ord;\n    int n = G.size();\n    vector<int> num(n, 0);\n    REP(i, n) {\n \
    \       for (auto u : G[i]) {\n            ++num[u];\n        }\n    }\n    queue<int>\
    \ que;\n    REP(i, n) {\n      if (num[i] == 0) {\n            que.push(i);\n\
    \        }\n    }\n    for (int k = 0; !que.empty(); ++k) {\n        int i = que.front();\
    \ que.pop();\n        ord.emplace_back(i);\n        for (auto u : G[i]) {\n  \
    \          if (--num[u] == 0) {\n                que.push(u);\n            }\n\
    \        }\n    }\n\n    if(SZ(ord) != n) return {};\n    else return ord;\n}\n"
  code: "#include \"template.cpp\"\n\n/*\n * ord\u306B\u306F\u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u30BD\u30FC\u30C8\u3055\u308C\u305F\u9806\u756A\u3067\u9802\u70B9\
    \u756A\u53F7\u304C\u5165\u308B\n * DAG\u3067\u306A\u3051\u308C\u3070\u7A7A\u306E\
    \u914D\u5217\u3092\u8FD4\u3059\n */\n\nvector<int> topological_sort(const vector<vector<int>>&\
    \ G) {\n    vector<int> ord;\n    int n = G.size();\n    vector<int> num(n, 0);\n\
    \    REP(i, n) {\n        for (auto u : G[i]) {\n            ++num[u];\n     \
    \   }\n    }\n    queue<int> que;\n    REP(i, n) {\n      if (num[i] == 0) {\n\
    \            que.push(i);\n        }\n    }\n    for (int k = 0; !que.empty();\
    \ ++k) {\n        int i = que.front(); que.pop();\n        ord.emplace_back(i);\n\
    \        for (auto u : G[i]) {\n            if (--num[u] == 0) {\n           \
    \     que.push(u);\n            }\n        }\n    }\n\n    if(SZ(ord) != n) return\
    \ {};\n    else return ord;\n}\n"
  dependsOn:
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/topological_sort.cpp
  requiredBy:
  - test/graph/topological_sort.cpp
  timestamp: '2020-10-31 04:16:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/topological_sort.cpp
layout: document
redirect_from:
- /library/lib/graph/topological_sort.cpp
- /library/lib/graph/topological_sort.cpp.html
title: lib/graph/topological_sort.cpp
---
