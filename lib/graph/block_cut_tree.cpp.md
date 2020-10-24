---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/lowlink.cpp
    title: lib/graph/lowlink.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
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
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/lowlink.cpp\"\n\
    \n/**\n * @brief\n * \u6A4B\u3068\u95A2\u7BC0\u70B9\u3092O(n+m)\u3067\u5217\u6319\
    \n * \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u30B0\u30E9\u30D5\u3092\u6295\
    \u3052\u8FBC\u3080\u3068bridge\u3068articulation\u304C\u66F4\u65B0\u3055\u308C\
    \u308B\n * @author Md\n * @date 2020/10/20\n */\n\nstruct Lowlink {\n  vvi g;\n\
    \  int n;\n  vi ord, low;\n  vector<P> bridge;\n  vector<int> articulation;\n\
    \  int t = 0;\n\n  Lowlink(const vvi &G): g(G) {\n    n = SZ(g);\n    ord.resize(n,\
    \ INF);\n    low.resize(n, INF);\n\n    REP(i, n) {\n      if(ord[i] == INF) {\n\
    \        dfs(i, -1);\n      }\n    }\n  }\n\n  void dfs(int now, int prev) {\n\
    \    ord[now] = t;\n    low[now] = ord[now];\n    t++;\n    int d = 0;\n    bool\
    \ ar = false;\n    for(auto &nxt: g[now]) {\n      if(nxt == prev) continue;\n\
    \      if(ord[nxt] == INF) {\n        d++;\n        dfs(nxt, now);\n        chmin(low[now],\
    \ low[nxt]);\n        ar |= prev != -1 && ord[now] <= low[nxt];\n        if(ord[now]\
    \ < low[nxt]) {\n          if(now < nxt) bridge.emplace_back(now, nxt);\n    \
    \      else bridge.emplace_back(nxt, now);\n        }\n      } else {\n      \
    \  chmin(low[now], ord[nxt]);\n      }\n    }\n    ar |= prev == -1 && d >= 2;\n\
    \    if(ar) articulation.push_back(now);\n  }\n};\n#line 2 \"lib/graph/block_cut_tree.cpp\"\
    \n\r\n/**\r\n * @brief\r\n * \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\
    \u89E3\u3059\u308B\r\n * edge\u306B\u3061\u3083\u3093\u3068idx\u3092\u8F09\u305B\
    \u305F\u3089\u7DDA\u5F62\u306B\u306A\u308B\u3051\u3069\u3001\u9762\u5012\u306A\
    \u306E\u3067log\u3092\u8F09\u305B\u3066\u3044\u307E\u3059...\r\n *\r\n * verify\u5148\
    \u304C\u306A\u304F\u3066\u3053\u307E\u3063\u305F\r\n * \u3042\u307E\u308A\u4FE1\
    \u7528\u3057\u306A\u3044\r\n *\r\n * @input\r\n * g: \u7121\u5411\u5358\u7D14\u30B0\
    \u30E9\u30D5\r\n * mp: \u9802\u70B9\u306E\u30DA\u30A2\u304B\u3089\u8FBA\u756A\u53F7\
    \u3078\u306E\u5199\u50CF\uFF08u < v\u306A\u308B\u30DA\u30A2u, v\u306B\u3064\u3044\
    \u3066mp[{u, v}]\u3092\u767B\u9332)\r\n *\r\n * @output\r\n * components: \u4E8C\
    \u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u3054\u3068\u306B\u8FBA\u306E\u914D\
    \u5217\u304C\u683C\u7D0D\u3055\u308C\u308B\r\n *\r\n * @author Md\r\n * @date\
    \ 2020/10/21\r\n */\r\n\r\nstruct BlockCutTree {\r\n  int n;\r\n  vvi g;\r\n \
    \ map<P, int> mp;\r\n  Lowlink lowlink;\r\n  vector<bool> sel;\r\n  vector<vector<int>>\
    \ components;\r\n  vector<int> tmp_edges;\r\n\r\n  BlockCutTree(const vvi &g,\
    \ const map<P, int> mp): g(g), lowlink(g), mp(mp) {\r\n    int n = SZ(g);\r\n\
    \    sel.resize(n, false);\r\n    REP(i, n) {\r\n      if(!sel[i]) dfs(i, -1);\r\
    \n    }\r\n  }\r\n\r\n  void build() {\r\n    REP(i, n) {\r\n\r\n    }\r\n  }\r\
    \n\r\nprivate:\r\n  void dfs(int now, int prev) {\r\n    sel[now] = true;\r\n\
    \    bool tmp = false;\r\n    for(auto &nxt: g[now]) {\r\n      int now_nxt_num\
    \ = -1;\r\n      if(now < nxt) now_nxt_num = tmp_edges.emplace_back(mp[{now, nxt}]);\r\
    \n      else now_nxt_num = tmp_edges.emplace_back(mp[{nxt, now}]);\r\n      if(nxt\
    \ == prev && !tmp) {\r\n        tmp = true;\r\n        continue;\r\n      }\r\n\
    \      if(!sel[nxt] || lowlink.ord[now] > lowlink.ord[nxt]) {\r\n        tmp_edges.emplace_back(now_nxt_num);\r\
    \n      }\r\n      if(!sel[nxt]) {\r\n        dfs(nxt, now);\r\n        if(lowlink.low[nxt]\
    \ >= lowlink.ord[now]) {\r\n          components.emplace_back();\r\n         \
    \ while(1) {\r\n            int edge_num = tmp_edges.back();\r\n            components.back().emplace_back(edge_num);\r\
    \n            tmp_edges.pop_back();\r\n            if(edge_num == now_nxt_num)\
    \ {\r\n              break;\r\n            }\r\n          }\r\n        }\r\n \
    \     }\r\n    }\r\n\r\n  }\r\n};\r\n\r\n"
  code: "#include \"./lowlink.cpp\"\r\n\r\n/**\r\n * @brief\r\n * \u4E8C\u91CD\u9802\
    \u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3\u3059\u308B\r\n * edge\u306B\u3061\u3083\
    \u3093\u3068idx\u3092\u8F09\u305B\u305F\u3089\u7DDA\u5F62\u306B\u306A\u308B\u3051\
    \u3069\u3001\u9762\u5012\u306A\u306E\u3067log\u3092\u8F09\u305B\u3066\u3044\u307E\
    \u3059...\r\n *\r\n * verify\u5148\u304C\u306A\u304F\u3066\u3053\u307E\u3063\u305F\
    \r\n * \u3042\u307E\u308A\u4FE1\u7528\u3057\u306A\u3044\r\n *\r\n * @input\r\n\
    \ * g: \u7121\u5411\u5358\u7D14\u30B0\u30E9\u30D5\r\n * mp: \u9802\u70B9\u306E\
    \u30DA\u30A2\u304B\u3089\u8FBA\u756A\u53F7\u3078\u306E\u5199\u50CF\uFF08u < v\u306A\
    \u308B\u30DA\u30A2u, v\u306B\u3064\u3044\u3066mp[{u, v}]\u3092\u767B\u9332)\r\n\
    \ *\r\n * @output\r\n * components: \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
    \u5206\u3054\u3068\u306B\u8FBA\u306E\u914D\u5217\u304C\u683C\u7D0D\u3055\u308C\
    \u308B\r\n *\r\n * @author Md\r\n * @date 2020/10/21\r\n */\r\n\r\nstruct BlockCutTree\
    \ {\r\n  int n;\r\n  vvi g;\r\n  map<P, int> mp;\r\n  Lowlink lowlink;\r\n  vector<bool>\
    \ sel;\r\n  vector<vector<int>> components;\r\n  vector<int> tmp_edges;\r\n\r\n\
    \  BlockCutTree(const vvi &g, const map<P, int> mp): g(g), lowlink(g), mp(mp)\
    \ {\r\n    int n = SZ(g);\r\n    sel.resize(n, false);\r\n    REP(i, n) {\r\n\
    \      if(!sel[i]) dfs(i, -1);\r\n    }\r\n  }\r\n\r\n  void build() {\r\n   \
    \ REP(i, n) {\r\n\r\n    }\r\n  }\r\n\r\nprivate:\r\n  void dfs(int now, int prev)\
    \ {\r\n    sel[now] = true;\r\n    bool tmp = false;\r\n    for(auto &nxt: g[now])\
    \ {\r\n      int now_nxt_num = -1;\r\n      if(now < nxt) now_nxt_num = tmp_edges.emplace_back(mp[{now,\
    \ nxt}]);\r\n      else now_nxt_num = tmp_edges.emplace_back(mp[{nxt, now}]);\r\
    \n      if(nxt == prev && !tmp) {\r\n        tmp = true;\r\n        continue;\r\
    \n      }\r\n      if(!sel[nxt] || lowlink.ord[now] > lowlink.ord[nxt]) {\r\n\
    \        tmp_edges.emplace_back(now_nxt_num);\r\n      }\r\n      if(!sel[nxt])\
    \ {\r\n        dfs(nxt, now);\r\n        if(lowlink.low[nxt] >= lowlink.ord[now])\
    \ {\r\n          components.emplace_back();\r\n          while(1) {\r\n      \
    \      int edge_num = tmp_edges.back();\r\n            components.back().emplace_back(edge_num);\r\
    \n            tmp_edges.pop_back();\r\n            if(edge_num == now_nxt_num)\
    \ {\r\n              break;\r\n            }\r\n          }\r\n        }\r\n \
    \     }\r\n    }\r\n\r\n  }\r\n};\r\n\r\n"
  dependsOn:
  - lib/graph/lowlink.cpp
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/block_cut_tree.cpp
  requiredBy: []
  timestamp: '2020-10-23 16:04:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/block_cut_tree.cpp
layout: document
redirect_from:
- /library/lib/graph/block_cut_tree.cpp
- /library/lib/graph/block_cut_tree.cpp.html
title: lib/graph/block_cut_tree.cpp
---
