---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/primal_dual.test.cpp
    title: test/graph/primal_dual.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5C0F\u8CBB\u7528\u6D41(Primal Dual)"
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
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/primal_dual.cpp\"\
    \n\n/**\n * @brief \u6700\u5C0F\u8CBB\u7528\u6D41(Primal Dual)\n * @author habara-k\n\
    \ * @date 2020/10/26\n * @usage\n * PrimalDual<int,int> g(n);     // \u9802\u70B9\
    \u6570\u3067\u521D\u671F\u5316\n * g.add_edge(u, v, cap, cost);  // \u8FBA\u306E\
    \u8FFD\u52A0\n * g.min_cost_flow(s, t, flow);  // O(FElogV). \u3060\u3044\u305F\
    \u3044\u3082\u3063\u3068\u901F\u3044\n */\ntemplate<typename flow_t, typename\
    \ cost_t>\nstruct PrimalDual {\n    const cost_t INF;\n\n    struct edge {\n \
    \       int to;\n        flow_t cap;\n        cost_t cost;\n        int rev;\n\
    \        bool is_rev; // \u9006\u65B9\u5411:1, \u9806\u65B9\u5411:0. \u5FA9\u5143\
    \u306B\u4F7F\u7528\n    };\n    vector<vector<edge>> g;\n    vector<cost_t> h,\
    \ d;\n    vector<int> prevv, preve;\n\n    PrimalDual(int V) : g(V), INF(numeric_limits<\
    \ cost_t >::max()) {}\n\n    void add_edge(int from, int to, flow_t cap, cost_t\
    \ cost) {\n        g[from].push_back({to, cap, cost, SZ(g[to]), false});\n   \
    \     g[to].push_back({from, 0, -cost, SZ(g[from])-1, true});\n    }\n\n    cost_t\
    \ min_cost_flow(int s, int t, flow_t f) {\n        int V = (int)g.size();\n  \
    \      cost_t ret = 0;\n        using Pi = pair<cost_t, int>;\n        priority_queue<Pi,\
    \ vector<Pi>, greater<Pi>> que;\n        h.assign(V, 0);\n        preve.assign(V,\
    \ -1);\n        prevv.assign(V, -1);\n\n        while (f > 0) {\n            d.assign(V,\
    \ INF);\n            que.emplace(0, s);\n            d[s] = 0;\n            while\
    \ (!que.empty()) {\n                Pi p = que.top(); que.pop();\n           \
    \     if (d[p.second] < p.first) continue;\n                for (int i = 0; i\
    \ < g[p.second].size(); i++) {\n                    edge &e = g[p.second][i];\n\
    \                    cost_t nextCost = d[p.second] + e.cost +\n              \
    \                        h[p.second] - h[e.to];\n                    if (e.cap\
    \ > 0 && d[e.to] > nextCost) {\n                        d[e.to] = nextCost;\n\
    \                        prevv[e.to] = p.second, preve[e.to] = i;\n          \
    \              que.emplace(d[e.to], e.to);\n                    }\n          \
    \      }\n            }\n            if (d[t] == INF) return -1;\n           \
    \ for (int v = 0; v < V; v++) h[v] += d[v];\n            flow_t addflow = f;\n\
    \            for (int v = t; v != s; v = prevv[v]) {\n                addflow\
    \ = min(addflow, g[prevv[v]][preve[v]].cap);\n            }\n            f -=\
    \ addflow;\n            ret += addflow * h[t];\n            for (int v = t; v\
    \ != s; v = prevv[v]) {\n                edge &e = g[prevv[v]][preve[v]];\n  \
    \              e.cap -= addflow;\n                g[v][e.rev].cap += addflow;\n\
    \            }\n        }\n        return ret;\n    }\n};\n\n"
  code: "#include \"template.cpp\"\n\n/**\n * @brief \u6700\u5C0F\u8CBB\u7528\u6D41\
    (Primal Dual)\n * @author habara-k\n * @date 2020/10/26\n * @usage\n * PrimalDual<int,int>\
    \ g(n);     // \u9802\u70B9\u6570\u3067\u521D\u671F\u5316\n * g.add_edge(u, v,\
    \ cap, cost);  // \u8FBA\u306E\u8FFD\u52A0\n * g.min_cost_flow(s, t, flow);  //\
    \ O(FElogV). \u3060\u3044\u305F\u3044\u3082\u3063\u3068\u901F\u3044\n */\ntemplate<typename\
    \ flow_t, typename cost_t>\nstruct PrimalDual {\n    const cost_t INF;\n\n   \
    \ struct edge {\n        int to;\n        flow_t cap;\n        cost_t cost;\n\
    \        int rev;\n        bool is_rev; // \u9006\u65B9\u5411:1, \u9806\u65B9\u5411\
    :0. \u5FA9\u5143\u306B\u4F7F\u7528\n    };\n    vector<vector<edge>> g;\n    vector<cost_t>\
    \ h, d;\n    vector<int> prevv, preve;\n\n    PrimalDual(int V) : g(V), INF(numeric_limits<\
    \ cost_t >::max()) {}\n\n    void add_edge(int from, int to, flow_t cap, cost_t\
    \ cost) {\n        g[from].push_back({to, cap, cost, SZ(g[to]), false});\n   \
    \     g[to].push_back({from, 0, -cost, SZ(g[from])-1, true});\n    }\n\n    cost_t\
    \ min_cost_flow(int s, int t, flow_t f) {\n        int V = (int)g.size();\n  \
    \      cost_t ret = 0;\n        using Pi = pair<cost_t, int>;\n        priority_queue<Pi,\
    \ vector<Pi>, greater<Pi>> que;\n        h.assign(V, 0);\n        preve.assign(V,\
    \ -1);\n        prevv.assign(V, -1);\n\n        while (f > 0) {\n            d.assign(V,\
    \ INF);\n            que.emplace(0, s);\n            d[s] = 0;\n            while\
    \ (!que.empty()) {\n                Pi p = que.top(); que.pop();\n           \
    \     if (d[p.second] < p.first) continue;\n                for (int i = 0; i\
    \ < g[p.second].size(); i++) {\n                    edge &e = g[p.second][i];\n\
    \                    cost_t nextCost = d[p.second] + e.cost +\n              \
    \                        h[p.second] - h[e.to];\n                    if (e.cap\
    \ > 0 && d[e.to] > nextCost) {\n                        d[e.to] = nextCost;\n\
    \                        prevv[e.to] = p.second, preve[e.to] = i;\n          \
    \              que.emplace(d[e.to], e.to);\n                    }\n          \
    \      }\n            }\n            if (d[t] == INF) return -1;\n           \
    \ for (int v = 0; v < V; v++) h[v] += d[v];\n            flow_t addflow = f;\n\
    \            for (int v = t; v != s; v = prevv[v]) {\n                addflow\
    \ = min(addflow, g[prevv[v]][preve[v]].cap);\n            }\n            f -=\
    \ addflow;\n            ret += addflow * h[t];\n            for (int v = t; v\
    \ != s; v = prevv[v]) {\n                edge &e = g[prevv[v]][preve[v]];\n  \
    \              e.cap -= addflow;\n                g[v][e.rev].cap += addflow;\n\
    \            }\n        }\n        return ret;\n    }\n};\n\n"
  dependsOn:
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/primal_dual.cpp
  requiredBy: []
  timestamp: '2020-10-26 23:10:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/primal_dual.test.cpp
documentation_of: lib/graph/primal_dual.cpp
layout: document
redirect_from:
- /library/lib/graph/primal_dual.cpp
- /library/lib/graph/primal_dual.cpp.html
title: "\u6700\u5C0F\u8CBB\u7528\u6D41(Primal Dual)"
---
