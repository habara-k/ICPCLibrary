---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://codeforces.com/gym/102428/submission/90057804
    - https://w.atwiki.jp/uwicoder/pages/2842.html
  bundledCode: "#line 1 \"lib/string/suffix_automaton.cpp\"\n// https://codeforces.com/gym/102428/submission/90057804\
    \ (by kanra824)\n// \u2191\u30C6\u30B9\u30C8\u3000\u4F7F\u3063\u3066\u308B\u3060\
    \u3051 2019-2020 ACM-ICPC Latin American Regional Programming Contest\n\n// \u53C2\
    \u8003: https://w.atwiki.jp/uwicoder/pages/2842.html\n\nstruct state {\n  int\
    \ len, link;\n  map<char, int> next;\n};\n \nconst int MAXLEN = 200010;\nstate\
    \ st[MAXLEN * 2];\nint sz, last;\n \nvoid sa_init() {\n  sz = last = 0;\n  st[0].len\
    \ = 0;\n  st[0].link = -1;\n  sz++;\n}\n \n\nvoid sa_extend(char c) {\n  int cur\
    \ = sz++;\n  st[cur].len = st[last].len + 1;\n  int p;\n  for (p = last; p !=\
    \ -1 && !st[p].next.count(c); p = st[p].link) {\n    st[p].next[c] = cur;\n  }\n\
    \  if (p == -1) {\n    st[cur].link = 0;\n  } else {\n    int q = st[p].next[c];\n\
    \    if (st[p].len + 1 == st[q].len) {\n      st[cur].link = q;\n    } else {\n\
    \      int clone = sz++;\n      st[clone].len = st[p].len + 1;\n      st[clone].next\
    \ = st[q].next;\n      st[clone].link = st[q].link;\n      for (; p != -1 && st[p].next[c]\
    \ == q; p = st[p].link) {\n        st[p].next[c] = clone;\n      }\n      st[q].link\
    \ = st[cur].link = clone;\n    }\n  }\n  last = cur;\n}\n"
  code: "// https://codeforces.com/gym/102428/submission/90057804 (by kanra824)\n\
    // \u2191\u30C6\u30B9\u30C8\u3000\u4F7F\u3063\u3066\u308B\u3060\u3051 2019-2020\
    \ ACM-ICPC Latin American Regional Programming Contest\n\n// \u53C2\u8003: https://w.atwiki.jp/uwicoder/pages/2842.html\n\
    \nstruct state {\n  int len, link;\n  map<char, int> next;\n};\n \nconst int MAXLEN\
    \ = 200010;\nstate st[MAXLEN * 2];\nint sz, last;\n \nvoid sa_init() {\n  sz =\
    \ last = 0;\n  st[0].len = 0;\n  st[0].link = -1;\n  sz++;\n}\n \n\nvoid sa_extend(char\
    \ c) {\n  int cur = sz++;\n  st[cur].len = st[last].len + 1;\n  int p;\n  for\
    \ (p = last; p != -1 && !st[p].next.count(c); p = st[p].link) {\n    st[p].next[c]\
    \ = cur;\n  }\n  if (p == -1) {\n    st[cur].link = 0;\n  } else {\n    int q\
    \ = st[p].next[c];\n    if (st[p].len + 1 == st[q].len) {\n      st[cur].link\
    \ = q;\n    } else {\n      int clone = sz++;\n      st[clone].len = st[p].len\
    \ + 1;\n      st[clone].next = st[q].next;\n      st[clone].link = st[q].link;\n\
    \      for (; p != -1 && st[p].next[c] == q; p = st[p].link) {\n        st[p].next[c]\
    \ = clone;\n      }\n      st[q].link = st[cur].link = clone;\n    }\n  }\n  last\
    \ = cur;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/suffix_automaton.cpp
  requiredBy: []
  timestamp: '2020-09-06 11:22:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/string/suffix_automaton.cpp
layout: document
redirect_from:
- /library/lib/string/suffix_automaton.cpp
- /library/lib/string/suffix_automaton.cpp.html
title: lib/string/suffix_automaton.cpp
---
