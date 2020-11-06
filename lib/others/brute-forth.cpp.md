---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/others/brute-forth.cpp\"\n// K^N\u306E\u5168\u63A2\u7D22\
    \n\nvector<int> a(N+1);\nwhile (a[N] == 0) {\n    // \u3053\u3053\u3067a[0] ~\
    \ a[N-1] \u3092\u4F7F\u3063\u3066\u51E6\u7406\n    for (int i = 0; ++a[i] == K;\
    \ ++i) { a[i] = 0; }\n}\n\n"
  code: "// K^N\u306E\u5168\u63A2\u7D22\n\nvector<int> a(N+1);\nwhile (a[N] == 0)\
    \ {\n    // \u3053\u3053\u3067a[0] ~ a[N-1] \u3092\u4F7F\u3063\u3066\u51E6\u7406\
    \n    for (int i = 0; ++a[i] == K; ++i) { a[i] = 0; }\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/brute-forth.cpp
  requiredBy: []
  timestamp: '2020-11-06 13:05:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/brute-forth.cpp
layout: document
redirect_from:
- /library/lib/others/brute-forth.cpp
- /library/lib/others/brute-forth.cpp.html
title: lib/others/brute-forth.cpp
---
