---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/luzhiled/snippets/graph/chromatic-number.html
  bundledCode: "#line 1 \"lib/graph/graph_coloring.cpp\"\n// https://ei1333.github.io/luzhiled/snippets/graph/chromatic-number.html\n\
    // \u2191\u306E\u3082\u306E\u3067\u3059\n// \u8FFD\u52A0: Md\n\ntemplate<typename\
    \ T>\nusing Matrix<T> = vector<vector<T>>;\n\nint chromatic_number(const Matrix<\
    \ bool > &g) {\n  int N = (int) g.size();\n  vector< int > es(N);\n  for(int i\
    \ = 0; i < g.size(); i++) {\n    for(int j = 0; j < g.size(); j++) {\n      es[i]\
    \ |= g[i][j] << j;\n    }\n  }\n  int ret = N;\n  for(int d : {7, 11, 21}) {\n\
    \    int mod = 1e9 + d;\n    vector< int > ind(1 << N), aux(1 << N, 1);\n    ind[0]\
    \ = 1;\n    for(int S = 1; S < 1 << N; S++) {\n      int u = __builtin_ctz(S);\n\
    \      ind[S] = ind[S ^ (1 << u)] + ind[(S ^ (1 << u)) & ~es[u]];\n    }\n   \
    \ for(int i = 1; i < ret; i++) {\n      int64_t all = 0;\n      for(int j = 0;\
    \ j < 1 << N; j++) {\n        int S = j ^(j >> 1);\n        aux[S] = (1LL * aux[S]\
    \ * ind[S]) % mod;\n        all += j & 1 ? aux[S] : mod - aux[S];\n      }\n \
    \     if(all % mod) ret = i;\n    }\n  }\n  return ret;\n}\n"
  code: "// https://ei1333.github.io/luzhiled/snippets/graph/chromatic-number.html\n\
    // \u2191\u306E\u3082\u306E\u3067\u3059\n// \u8FFD\u52A0: Md\n\ntemplate<typename\
    \ T>\nusing Matrix<T> = vector<vector<T>>;\n\nint chromatic_number(const Matrix<\
    \ bool > &g) {\n  int N = (int) g.size();\n  vector< int > es(N);\n  for(int i\
    \ = 0; i < g.size(); i++) {\n    for(int j = 0; j < g.size(); j++) {\n      es[i]\
    \ |= g[i][j] << j;\n    }\n  }\n  int ret = N;\n  for(int d : {7, 11, 21}) {\n\
    \    int mod = 1e9 + d;\n    vector< int > ind(1 << N), aux(1 << N, 1);\n    ind[0]\
    \ = 1;\n    for(int S = 1; S < 1 << N; S++) {\n      int u = __builtin_ctz(S);\n\
    \      ind[S] = ind[S ^ (1 << u)] + ind[(S ^ (1 << u)) & ~es[u]];\n    }\n   \
    \ for(int i = 1; i < ret; i++) {\n      int64_t all = 0;\n      for(int j = 0;\
    \ j < 1 << N; j++) {\n        int S = j ^(j >> 1);\n        aux[S] = (1LL * aux[S]\
    \ * ind[S]) % mod;\n        all += j & 1 ? aux[S] : mod - aux[S];\n      }\n \
    \     if(all % mod) ret = i;\n    }\n  }\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/graph_coloring.cpp
  requiredBy: []
  timestamp: '2020-09-02 10:27:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/graph_coloring.cpp
layout: document
redirect_from:
- /library/lib/graph/graph_coloring.cpp
- /library/lib/graph/graph_coloring.cpp.html
title: lib/graph/graph_coloring.cpp
---
