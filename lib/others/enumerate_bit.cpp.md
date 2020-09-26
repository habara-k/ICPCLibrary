---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"lib/others/enumerate_bit.cpp\"\n// \u96C6\u5408S\u306E\u90E8\
    \u5206\u96C6\u5408\u3092\u5217\u6319 (S\u3068T\u3092\u5217\u6319\u3059\u308B\u3068\
    \u304D\u306B\u3053\u308C\u3092\u3064\u304B\u3046\u30684^n\u304B\u30893^n\u306B\
    \u306A\u308B\uFF09\nfor(int T=S; ;T = (T - 1) & S) {\n  // hoge\n  if(T == 0)\
    \ break;\n}\n\n// n\u500B\u304B\u3089k\u500B\u3048\u3089\u3093\u3060\u96C6\u5408\
    \u3092\u5217\u6319\nfor (int x = (1 << k) - 1; x < (1 << n); ) {\n    ...\n  \
    \  int t = x | (x - 1);\n    x = (t + 1) | (((~ t & - ~ t) - 1) >> (__builtin_ctz(x)\
    \ + 1));\n}\n"
  code: "// \u96C6\u5408S\u306E\u90E8\u5206\u96C6\u5408\u3092\u5217\u6319 (S\u3068\
    T\u3092\u5217\u6319\u3059\u308B\u3068\u304D\u306B\u3053\u308C\u3092\u3064\u304B\
    \u3046\u30684^n\u304B\u30893^n\u306B\u306A\u308B\uFF09\nfor(int T=S; ;T = (T -\
    \ 1) & S) {\n  // hoge\n  if(T == 0) break;\n}\n\n// n\u500B\u304B\u3089k\u500B\
    \u3048\u3089\u3093\u3060\u96C6\u5408\u3092\u5217\u6319\nfor (int x = (1 << k)\
    \ - 1; x < (1 << n); ) {\n    ...\n    int t = x | (x - 1);\n    x = (t + 1) |\
    \ (((~ t & - ~ t) - 1) >> (__builtin_ctz(x) + 1));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/enumerate_bit.cpp
  requiredBy: []
  timestamp: '2020-09-03 08:26:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/enumerate_bit.cpp
layout: document
redirect_from:
- /library/lib/others/enumerate_bit.cpp
- /library/lib/others/enumerate_bit.cpp.html
title: lib/others/enumerate_bit.cpp
---
