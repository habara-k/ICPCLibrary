---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/suffix_array.test.cpp
    title: test/string/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/suffix_array_2.test.cpp
    title: test/string/suffix_array_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/number_of_substrings.test.cpp
    title: test/yosupo-judge/number_of_substrings.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u63A5\u5C3E\u8F9E\u914D\u5217 O(n(logn)^2) \u3042\u308A\u307B\
      \u3093\u306E\u3084\u3064\u305D\u306E\u307E\u307E"
    links: []
  bundledCode: "#line 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\n#define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i,\
    \ n) for (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n);\
    \ ++i)\n#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x)\
    \ ((int)(x).size())\n#define ALL(x) (x).begin(),(x).end()\n\n#define DUMP(x) cerr<<#x<<\"\
    \ = \"<<(x)<<endl\n#define DEBUG(x) cerr<<#x<<\" = \"<<(x)<<\" (L\"<<__LINE__<<\"\
    )\"<<endl;\n\ntemplate<class T>\nostream &operator<<(ostream &os, const vector\
    \ <T> &v) {\n    os << \"[\";\n    REP(i, SZ(v)) {\n        if (i) os << \", \"\
    ;\n        os << v[i];\n    }\n    return os << \"]\";\n}\n\ntemplate<class T,\
    \ class U>\nostream &operator<<(ostream &os, const pair <T, U> &p) {\n    return\
    \ os << \"(\" << p.first << \" \" << p.second << \")\";\n}\n\ntemplate<class T>\n\
    bool chmax(T &a, const T &b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ntemplate<class T>\nbool chmin(T &a, const\
    \ T &b) {\n    if (b < a) {\n        a = b;\n        return true;\n    }\n   \
    \ return false;\n}\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\nusing P = pair<int, int>;\nusing vi = vector<int>;\n\
    using vll = vector<ll>;\nusing vvi = vector<vi>;\nusing vvll = vector<vll>;\n\n\
    const ll MOD = 1e9 + 7;\nconst int INF = INT_MAX / 2;\nconst ll LINF = LLONG_MAX\
    \ / 2;\nconst ld eps = 1e-9;\n\n/*\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(10);\n\n    // ifstream in(\"in.txt\");\n \
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/string/suffix_array.cpp\"\
    \n\n/**\n * @brief \u63A5\u5C3E\u8F9E\u914D\u5217 O(n(logn)^2) \u3042\u308A\u307B\
    \u3093\u306E\u3084\u3064\u305D\u306E\u307E\u307E\n * @detail\n *  construct_sa\u306B\
    string\u3092\u6295\u3052\u308B\u3068\u63A5\u5C3E\u8F9E\u914D\u5217\u304C\u5E30\
    \u3063\u3066\u304F\u308B(1-indexed)\n *  construct_lcp\u306Bstring\u3068suffix_array\u3092\
    \u6295\u3052\u308B\u3068LCP\u306E\u914D\u5217\u304C\u5E30\u3063\u3066\u304F\u308B\
    (1-indexed)\n *\n *  \u914D\u5217\u30B5\u30A4\u30BA(ma)\u306B\u6CE8\u610F\uFF08\
    \u6587\u5B57\u5217\u306E\u9577\u3055+1\u4EE5\u4E0A\uFF09\n * @author Md\n * @date\
    \ 2020/10/12\n */\n\nnamespace SA {\n  static const int ma = 1000000;\n  int n,\
    \ k;\n  int rank[ma];\n  int rank_lcp[ma];\n  int tmp[ma];\n\n  bool compare_sa(int\
    \ i, int j) {\n    if (rank[i] != rank[j]) return rank[i] < rank[j];\n    else\
    \ {\n      int ri = i + k <= n ? rank[i + k] : -1;\n      int rj = j + k <= n\
    \ ? rank[j + k] : -1;\n      return ri < rj;\n    }\n  }\n\n  std::vector<int>\
    \ construct_sa(const std::string &s) {\n    n = s.length();\n    std::vector<int>\
    \ sa(n + 1);\n    for (int i = 0; i <= n; ++i) {\n      sa[i] = i;\n      rank[i]\
    \ = i < n ? s[i] : -1;\n    }\n\n    for (k = 1; k <= n; k *= 2) {\n      sort(sa.begin(),\
    \ sa.end(), compare_sa);\n\n      tmp[sa[0]] = 0;\n      for(int i=1;i<=n;++i)\
    \ {\n        tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);\n\
    \      }\n      for(int i=0;i<=n;++i) {\n        rank[i] = tmp[i];\n      }\n\
    \    }\n\n    return sa;\n  }\n\n  std::vector<int> construct_lcp(const std::string\
    \ &s, const std::vector<int> &sa) {\n    int n = s.length();\n    std::vector<int>\
    \ lcp(n+1);\n\n    for(int i=0;i<=n;++i) rank_lcp[sa[i]] = i;\n\n    int h = 0;\n\
    \    lcp[0] = 0;\n    for(int i=0;i<n;++i) {\n      int j = sa[rank_lcp[i] - 1];\n\
    \n      if(h > 0) h--;\n      for(; j + h < n && i + h < n; h++) {\n        if(s[j+h]\
    \ != s[i+h]) break;\n      }\n\n      lcp[rank_lcp[i] - 1] = h;\n    }\n\n   \
    \ return lcp;\n  }\n\n};\n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief \u63A5\u5C3E\u8F9E\u914D\u5217\
    \ O(n(logn)^2) \u3042\u308A\u307B\u3093\u306E\u3084\u3064\u305D\u306E\u307E\u307E\
    \n * @detail\n *  construct_sa\u306Bstring\u3092\u6295\u3052\u308B\u3068\u63A5\
    \u5C3E\u8F9E\u914D\u5217\u304C\u5E30\u3063\u3066\u304F\u308B(1-indexed)\n *  construct_lcp\u306B\
    string\u3068suffix_array\u3092\u6295\u3052\u308B\u3068LCP\u306E\u914D\u5217\u304C\
    \u5E30\u3063\u3066\u304F\u308B(1-indexed)\n *\n *  \u914D\u5217\u30B5\u30A4\u30BA\
    (ma)\u306B\u6CE8\u610F\uFF08\u6587\u5B57\u5217\u306E\u9577\u3055+1\u4EE5\u4E0A\
    \uFF09\n * @author Md\n * @date 2020/10/12\n */\n\nnamespace SA {\n  static const\
    \ int ma = 1000000;\n  int n, k;\n  int rank[ma];\n  int rank_lcp[ma];\n  int\
    \ tmp[ma];\n\n  bool compare_sa(int i, int j) {\n    if (rank[i] != rank[j]) return\
    \ rank[i] < rank[j];\n    else {\n      int ri = i + k <= n ? rank[i + k] : -1;\n\
    \      int rj = j + k <= n ? rank[j + k] : -1;\n      return ri < rj;\n    }\n\
    \  }\n\n  std::vector<int> construct_sa(const std::string &s) {\n    n = s.length();\n\
    \    std::vector<int> sa(n + 1);\n    for (int i = 0; i <= n; ++i) {\n      sa[i]\
    \ = i;\n      rank[i] = i < n ? s[i] : -1;\n    }\n\n    for (k = 1; k <= n; k\
    \ *= 2) {\n      sort(sa.begin(), sa.end(), compare_sa);\n\n      tmp[sa[0]] =\
    \ 0;\n      for(int i=1;i<=n;++i) {\n        tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1],\
    \ sa[i]) ? 1 : 0);\n      }\n      for(int i=0;i<=n;++i) {\n        rank[i] =\
    \ tmp[i];\n      }\n    }\n\n    return sa;\n  }\n\n  std::vector<int> construct_lcp(const\
    \ std::string &s, const std::vector<int> &sa) {\n    int n = s.length();\n   \
    \ std::vector<int> lcp(n+1);\n\n    for(int i=0;i<=n;++i) rank_lcp[sa[i]] = i;\n\
    \n    int h = 0;\n    lcp[0] = 0;\n    for(int i=0;i<n;++i) {\n      int j = sa[rank_lcp[i]\
    \ - 1];\n\n      if(h > 0) h--;\n      for(; j + h < n && i + h < n; h++) {\n\
    \        if(s[j+h] != s[i+h]) break;\n      }\n\n      lcp[rank_lcp[i] - 1] =\
    \ h;\n    }\n\n    return lcp;\n  }\n\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/string/suffix_array.cpp
  requiredBy: []
  timestamp: '2020-10-13 17:48:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/number_of_substrings.test.cpp
  - test/string/suffix_array.test.cpp
  - test/string/suffix_array_2.test.cpp
documentation_of: lib/string/suffix_array.cpp
layout: document
redirect_from:
- /library/lib/string/suffix_array.cpp
- /library/lib/string/suffix_array.cpp.html
title: "\u63A5\u5C3E\u8F9E\u914D\u5217 O(n(logn)^2) \u3042\u308A\u307B\u3093\u306E\
  \u3084\u3064\u305D\u306E\u307E\u307E"
---
