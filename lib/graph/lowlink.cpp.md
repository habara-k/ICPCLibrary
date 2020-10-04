---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/graph/twoconnectedcomponents.cpp
    title: lib/graph/twoconnectedcomponents.cpp
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
    \ntemplate<typename T>\nstruct LowLink {\n    const int inf = 1000000000;\n  \
    \  int sz;\n    std::vector<int> pre, low;\n    std::vector<bool> sel;\n    std::vector<std::pair<int,\
    \ int>> bridge;\n    std::vector<int> articulation;\n\n    LowLink(const Graph<T>\
    \ &g) {\n        sz = g.size();\n        pre.resize(sz, inf);\n        low.resize(sz,\
    \ inf);\n        sel.resize(sz, false);\n        int cnt = 0;\n        dfs(g,\
    \ 0, -1, cnt);\n    }\n\n    void dfs(const Graph<T> &g, int now, int prev, int\
    \ &cnt) {\n        if(pre[now] != inf) {\n            low[prev] = min(low[prev],\
    \ pre[now]);\n            return;\n        }\n        pre[now] = cnt;\n      \
    \  low[now] = cnt;\n        cnt++;\n        for(int i=0;i<(int)(g[now].size());++i)\
    \ {\n            int nxt = g[now][i].to;\n            //if g is an undirected\
    \ graph\n            if(nxt == prev) continue;\n            dfs(g, nxt, now, cnt);\n\
    \        }\n        if(prev != -1) low[prev] = min(low[prev], low[now]);\n   \
    \     if(prev != -1 && pre[prev] < low[now]) {\n            bridge.emplace_back(make_pair(prev,\
    \ now));\n        }\n    }\n\n    void get_articulation(const Graph<T> &g, int\
    \ now, int prev) {\n        sel[now] = true;\n        int art = 0;\n        for(int\
    \ i=0;i<(int)(g[now].size());++i) {\n            int nxt = g[now][i].to;\n   \
    \         //cout << now << \":\" << nxt << endl;\n            if(sel[nxt]) continue;\n\
    \            // if g is an undirected graph\n            if(nxt == prev) continue;\n\
    \            if(now == 0 || pre[now] <= low[nxt]) art++;\n            get_articulation(g,\
    \ nxt, now);\n        }\n        if((now == 0 && art >= 2) || (now != 0 && art\
    \ >= 1)) {\n            articulation.push_back(now);\n        }\n    }\n};\n"
  code: "#include \"./template.cpp\"\n\ntemplate<typename T>\nstruct LowLink {\n \
    \   const int inf = 1000000000;\n    int sz;\n    std::vector<int> pre, low;\n\
    \    std::vector<bool> sel;\n    std::vector<std::pair<int, int>> bridge;\n  \
    \  std::vector<int> articulation;\n\n    LowLink(const Graph<T> &g) {\n      \
    \  sz = g.size();\n        pre.resize(sz, inf);\n        low.resize(sz, inf);\n\
    \        sel.resize(sz, false);\n        int cnt = 0;\n        dfs(g, 0, -1, cnt);\n\
    \    }\n\n    void dfs(const Graph<T> &g, int now, int prev, int &cnt) {\n   \
    \     if(pre[now] != inf) {\n            low[prev] = min(low[prev], pre[now]);\n\
    \            return;\n        }\n        pre[now] = cnt;\n        low[now] = cnt;\n\
    \        cnt++;\n        for(int i=0;i<(int)(g[now].size());++i) {\n         \
    \   int nxt = g[now][i].to;\n            //if g is an undirected graph\n     \
    \       if(nxt == prev) continue;\n            dfs(g, nxt, now, cnt);\n      \
    \  }\n        if(prev != -1) low[prev] = min(low[prev], low[now]);\n        if(prev\
    \ != -1 && pre[prev] < low[now]) {\n            bridge.emplace_back(make_pair(prev,\
    \ now));\n        }\n    }\n\n    void get_articulation(const Graph<T> &g, int\
    \ now, int prev) {\n        sel[now] = true;\n        int art = 0;\n        for(int\
    \ i=0;i<(int)(g[now].size());++i) {\n            int nxt = g[now][i].to;\n   \
    \         //cout << now << \":\" << nxt << endl;\n            if(sel[nxt]) continue;\n\
    \            // if g is an undirected graph\n            if(nxt == prev) continue;\n\
    \            if(now == 0 || pre[now] <= low[nxt]) art++;\n            get_articulation(g,\
    \ nxt, now);\n        }\n        if((now == 0 && art >= 2) || (now != 0 && art\
    \ >= 1)) {\n            articulation.push_back(now);\n        }\n    }\n};\n"
  dependsOn:
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/lowlink.cpp
  requiredBy:
  - lib/graph/twoconnectedcomponents.cpp
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/lowlink.cpp
layout: document
redirect_from:
- /library/lib/graph/lowlink.cpp
- /library/lib/graph/lowlink.cpp.html
title: lib/graph/lowlink.cpp
---
