---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/primal_dual.cpp
    title: lib/graph/primal_dual.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
  bundledCode: "#line 1 \"test/graph/primal_dual.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \n\n#line 1 \"lib/graph/template.cpp\"\n\n\n\n#line 1 \"lib/template.cpp\"\n\n\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define REP(i, n) for\
    \ (int i=0; i<(n); ++i)\n#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)\n\
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
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/primal_dual.cpp\"\
    \n\ntemplate<typename flow_t, typename cost_t>\nstruct PrimalDual {\n    const\
    \ cost_t INF;\n\n    struct edge {\n        int to;\n        flow_t cap;\n   \
    \     cost_t cost;\n        int rev;\n    };\n    vector<vector<edge>> g;\n  \
    \  vector<cost_t> h, d;\n    vector<int> prevv, preve;\n\n    PrimalDual(int V)\
    \ : g(V), INF(numeric_limits< cost_t >::max()) {}\n\n    void add_edge(int from,\
    \ int to, flow_t cap, cost_t cost) {\n        g[from].push_back({to, cap, cost,\
    \ (int)g[to].size()});\n        g[to].push_back({from, 0, -cost, (int)g[from].size()-1});\n\
    \    }\n\n    cost_t min_cost_flow(int s, int t, flow_t f) {\n        int V =\
    \ (int)g.size();\n        cost_t ret = 0;\n        using Pi = pair<cost_t, int>;\n\
    \        priority_queue<Pi, vector<Pi>, greater<Pi>> que;\n        h.assign(V,\
    \ 0);\n        preve.assign(V, -1);\n        prevv.assign(V, -1);\n\n        while\
    \ (f > 0) {\n            d.assign(V, INF);\n            que.emplace(0, s);\n \
    \           d[s] = 0;\n            while (!que.empty()) {\n                Pi\
    \ p = que.top(); que.pop();\n                if (d[p.second] < p.first) continue;\n\
    \                for (int i = 0; i < g[p.second].size(); i++) {\n            \
    \        edge &e = g[p.second][i];\n                    cost_t nextCost = d[p.second]\
    \ + e.cost +\n                        h[p.second] - h[e.to];\n               \
    \     if (e.cap > 0 && d[e.to] > nextCost) {\n                        d[e.to]\
    \ = nextCost;\n                        prevv[e.to] = p.second, preve[e.to] = i;\n\
    \                        que.emplace(d[e.to], e.to);\n                    }\n\
    \                }\n            }\n            if (d[t] == INF) return -1;\n \
    \           for (int v = 0; v < V; v++) h[v] += d[v];\n            flow_t addflow\
    \ = f;\n            for (int v = t; v != s; v = prevv[v]) {\n                addflow\
    \ = min(addflow, g[prevv[v]][preve[v]].cap);\n            }\n            f -=\
    \ addflow;\n            ret += addflow * h[t];\n            for (int v = t; v\
    \ != s; v = prevv[v]) {\n                edge &e = g[prevv[v]][preve[v]];\n  \
    \              e.cap -= addflow;\n                g[v][e.rev].cap += addflow;\n\
    \            }\n        }\n        return ret;\n    }\n};\n#line 4 \"test/graph/primal_dual.test.cpp\"\
    \n\nint main() {\n    int V, E, F;\n    cin >> V >> E >> F;\n    PrimalDual<int,\
    \ int> g(V);\n    for(int i = 0; i < E; i++) {\n        int a, b, c, d;\n    \
    \    cin >> a >> b >> c >> d;\n        g.add_edge(a, b, c, d);\n    }\n    cout\
    \ << g.min_cost_flow(0, V - 1, F) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \n\n#include \"../../lib/graph/primal_dual.cpp\"\n\nint main() {\n    int V, E,\
    \ F;\n    cin >> V >> E >> F;\n    PrimalDual<int, int> g(V);\n    for(int i =\
    \ 0; i < E; i++) {\n        int a, b, c, d;\n        cin >> a >> b >> c >> d;\n\
    \        g.add_edge(a, b, c, d);\n    }\n    cout << g.min_cost_flow(0, V - 1,\
    \ F) << endl;\n}\n"
  dependsOn:
  - lib/graph/primal_dual.cpp
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/primal_dual.test.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/primal_dual.test.cpp
layout: document
redirect_from:
- /verify/test/graph/primal_dual.test.cpp
- /verify/test/graph/primal_dual.test.cpp.html
title: test/graph/primal_dual.test.cpp
---
