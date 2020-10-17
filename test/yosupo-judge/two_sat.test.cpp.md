---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/scc.cpp
    title: lib/graph/scc.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/two_sat.cpp
    title: lib/graph/two_sat.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/yosupo-judge/two_sat.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/two_sat\"\r\n\r\n#line 1 \"lib/graph/template.cpp\"\
    \n\n\n\n#line 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing\
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 5 \"lib/graph/template.cpp\"\
    \n\ntemplate<typename T>\nstruct edge {\n    int src, to;\n    T cost;\n};\n\n\
    template<typename T>\nusing Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/scc.cpp\"\
    \n\n/**\n * @brief\n * \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @author\
    \ habara-k\n * @date 2020/08\n *\n * @param[in] g \u30B0\u30E9\u30D5\n *\n * @details\n\
    \ * comp: vertex -> component_id\n * graph: graph of components\n */\n\nstruct\
    \ StronglyConnectedComponents {\n    int n;\n    vector<vector<int>> g, rg, graph;\n\
    \    vector<int> ord, used, comp;\n\n    StronglyConnectedComponents(const vector<vector<int>>&\
    \ g) :\n            n(g.size()), g(g), rg(n), used(n), comp(n, -1)\n    {\n  \
    \      for (int i = 0; i < n; ++i) {\n            for (int to : g[i]) {\n    \
    \            rg[to].push_back(i);\n            }\n        }\n    }\n\n    void\
    \ build() {\n        for (int i = 0; i < n; ++i) dfs(i);\n        reverse(ord.begin(),\
    \ ord.end());\n        int ptr = 0;\n        for (int i : ord) if (comp[i] ==\
    \ -1) rdfs(i, ptr), ptr++;\n\n        graph.resize(ptr);\n        for (int i =\
    \ 0; i < n; ++i) {\n            for (int to : g[i]) {\n                int x =\
    \ comp[i], y = comp[to];\n                if (x == y) continue;\n            \
    \    graph[x].push_back(y);\n            }\n        }\n        for (auto& v :\
    \ graph) {\n            sort(v.begin(), v.end());\n            v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n        }\n    }\n\nprivate:\n    void dfs(int idx) {\n\
    \        if (used[idx]) return;\n        used[idx] = true;\n        for (int to\
    \ : g[idx]) dfs(to);\n        ord.push_back(idx);\n    }\n\n    void rdfs(int\
    \ idx, int cnt) {\n        if (comp[idx] != -1) return;\n        comp[idx] = cnt;\n\
    \        for (int to : rg[idx]) rdfs(to, cnt);\n    }\n};\n\n#line 2 \"lib/graph/two_sat.cpp\"\
    \n\r\n/**\r\n * @brief\r\n * 2-sat O(n)\r\n * add_hoge\u3067\u30EA\u30C6\u30E9\
    \u30EB\u3092\u8FFD\u52A0\u3057\u3066\u3044\u3063\u3066\u3001solve\u3067\u7D50\u679C\
    \u3092\u5F97\u308B\r\n */\r\n\r\nstruct TwoSat {\r\n  int n;\r\n  vector<vector<int>>\
    \ g;\r\n\r\n  TwoSat(int n): n(n) {\r\n    g.resize(2*n);\r\n  }\r\n\r\n  int\
    \ neg(int x) {\r\n    if(x < n) return x + n;\r\n    else return x - n;\r\n  }\r\
    \n\r\n  void add_ifthen(int u, int v) {\r\n    g[u].push_back(v);\r\n    g[neg(v)].push_back(neg(u));\r\
    \n  }\r\n\r\n  void add_or(int u, int v) {\r\n    add_ifthen(neg(u), v);\r\n \
    \ }\r\n\r\n  void add_nand(int u, int v) {\r\n    add_ifthen(u, neg(v));\r\n \
    \ }\r\n\r\n  void add_true(int u) {\r\n    g[neg(u)].push_back(u);\r\n  }\r\n\r\
    \n  void add_false(int u) {\r\n    g[u].push_back(neg(u));\r\n  }\r\n\r\n  vector<int>\
    \ solve() {\r\n    StronglyConnectedComponents scc(g);\r\n    scc.build();\r\n\
    \    vector<int> result(n);\r\n    REP(i, n) {\r\n      if(scc.comp[i] == scc.comp[neg(i)])\
    \ return {};\r\n      result[i] = scc.comp[i] > scc.comp[neg(i)];\r\n    }\r\n\
    \    return result;\r\n  }\r\n};\r\n\r\n#line 4 \"test/yosupo-judge/two_sat.test.cpp\"\
    \n\r\nint main() {\r\n  string tmp;\r\n  cin >> tmp >> tmp;\r\n  int n, m; cin\
    \ >> n >> m;\r\n  TwoSat twosat(n);\r\n  REP(i, m) {\r\n    int a, b, c; cin >>\
    \ a >> b >> c;\r\n    if(a < 0) {\r\n      a = n - a;\r\n    }\r\n    if(b < 0)\
    \ {\r\n      b = n - b;\r\n    }\r\n    a--;\r\n    b--;\r\n    twosat.add_or(a,\
    \ b);\r\n  }\r\n\r\n  auto res = twosat.solve();\r\n  if(res.empty()) {\r\n  \
    \  cout << \"s UNSATISFIABLE\" << endl;\r\n  } else {\r\n    cout << \"s SATISFIABLE\"\
    \ << endl;\r\n    cout << \"v\";\r\n    REP(i, n) {\r\n      cout << \" \" <<\
    \ ((2 * res[i] - 1) * (i+1));\r\n    }\r\n    cout << \" \" << 0 << endl;\r\n\
    \  }\r\n}\r\n\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\r\n\r\n#include\
    \ \"../../lib/graph/two_sat.cpp\"\r\n\r\nint main() {\r\n  string tmp;\r\n  cin\
    \ >> tmp >> tmp;\r\n  int n, m; cin >> n >> m;\r\n  TwoSat twosat(n);\r\n  REP(i,\
    \ m) {\r\n    int a, b, c; cin >> a >> b >> c;\r\n    if(a < 0) {\r\n      a =\
    \ n - a;\r\n    }\r\n    if(b < 0) {\r\n      b = n - b;\r\n    }\r\n    a--;\r\
    \n    b--;\r\n    twosat.add_or(a, b);\r\n  }\r\n\r\n  auto res = twosat.solve();\r\
    \n  if(res.empty()) {\r\n    cout << \"s UNSATISFIABLE\" << endl;\r\n  } else\
    \ {\r\n    cout << \"s SATISFIABLE\" << endl;\r\n    cout << \"v\";\r\n    REP(i,\
    \ n) {\r\n      cout << \" \" << ((2 * res[i] - 1) * (i+1));\r\n    }\r\n    cout\
    \ << \" \" << 0 << endl;\r\n  }\r\n}\r\n\r\n"
  dependsOn:
  - lib/graph/two_sat.cpp
  - lib/graph/scc.cpp
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/yosupo-judge/two_sat.test.cpp
  requiredBy: []
  timestamp: '2020-10-17 06:17:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/two_sat.test.cpp
- /verify/test/yosupo-judge/two_sat.test.cpp.html
title: test/yosupo-judge/two_sat.test.cpp
---
