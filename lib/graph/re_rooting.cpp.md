---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/re_rooting.test.cpp
    title: test/graph/re_rooting.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. O(1)."
    links:
    - https://codeforces.com/gym/102433/submission/80588275
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/graph/re_rooting.cpp\"\
    \n\n/**\n * @brief\n * \u5168\u65B9\u4F4D\u6728dp\n * @author habara-k\n * @date\
    \ 2020/05/18\n * @verify https://codeforces.com/gym/102433/submission/80588275\n\
    \ * @details \u4F7F\u3044\u65B9\n *   e.g. \u76F4\u5F84\n *   using T = pair<int,int>;\
    \ // \u9802\u70B9\u304C\u6301\u3064\u3079\u304D\u30C7\u30FC\u30BF\n *   using\
    \ Data = int;        // \u89AA\u304C\u5B50\u3092\u5F15\u3063\u5F35\u308A\u4E0A\
    \u3052\u308B\u3068\u304D\u306B\u5FC5\u8981\u306A\u30C7\u30FC\u30BF\n\n *   ReRooting<Data,T>\
    \ tr(\n *           n,\n *           [](T a, T b){\n *               vector<int>\
    \ v{a.first,a.second,b.first,b.second};\n *               sort(v.rbegin(),v.rend());\n\
    \ *               return T{v[0],v[1]};\n *               },                  \
    \     // \u5B50\u3092\u30DE\u30FC\u30B8\u3059\u308B\u6F14\u7B97\n *          \
    \ [](T a, Data w){\n *               return T{a.first+w, 0};\n *             \
    \  },                       // \u5B50\u3092\u5F15\u3063\u5F35\u308A\u4E0A\u3052\
    \u308B\u6F14\u7B97\n *           vector<T>(n, T{0, 0}),       // \u9802\u70B9\u304C\
    \u6301\u3064\u30C7\u30FC\u30BF\u306E\u521D\u671F\u5024\n *           T{0,0}  \
    \                     // \u5B50\u3092\u30DE\u30FC\u30B8\u3059\u308B\u6F14\u7B97\
    \u306E\u5358\u4F4D\u5143\n *           );\n *\n *   for (int i = 0; i < n-1; ++i)\
    \ {\n *       int s, t, w; cin >> s >> t >> w;\n *       tr.add_edge(s, t, Data{w},\
    \ Data{w});\n *   }\n *\n *   auto ans = tr.solve();\n */\n\ntemplate<typename\
    \ Data, typename T>\nstruct ReRooting {\n\n    using F1 = function<T(T, T)>;\n\
    \    using F2 = function<T(T, Data)>;\n\n    /**\n    * @brief \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF. O(1).\n    * @param[in] n: \u9802\u70B9\u6570\n    *\
    \ @param[in] f1: \u5B50\u304C\u6301\u3064\u30C7\u30FC\u30BF\u3092\u30DE\u30FC\u30B8\
    \u3059\u308B\u6F14\u7B97\n    * @param[in] f2: \u89AA\u304C\u5B50\u3092\u5F15\u3063\
    \u5F35\u308A\u4E0A\u3052\u308B\u6F14\u7B97\n    * @param[in] init: \u9802\u70B9\
    \u304C\u6301\u3064\u30C7\u30FC\u30BF\u306E\u521D\u671F\u5024\n    * @param[in]\
    \ ident: f1\u306E\u5358\u4F4D\u5143\n    */\n    ReRooting(\n            int n,\
    \ const F1 &f1, const F2 &f2,\n            const vector<T> &init, const T &ident)\
    \ :\n        g(n), ldp(n), rdp(n), lptr(n), rptr(n),\n        f1(f1), f2(f2),\
    \ init(init), ident(ident) {}\n\n    /**\n    * @brief \u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B. O(1)\n    * @param[in] u, v: \u8FBAu, v \u3092\u8FFD\u52A0\u3059\
    \u308B.\n    * @param[in] d: u \u304Cv \u3092\u5F15\u3063\u5F35\u308A\u4E0A\u3052\
    \u308B\u3068\u304D\u306B\u5FC5\u8981\u306A\u30C7\u30FC\u30BF.\n    * @param[in]\
    \ e: v \u304Cu \u3092\u5F15\u3063\u5F35\u308A\u4E0A\u3052\u308B\u3068\u304D\u306B\
    \u5FC5\u8981\u306A\u30C7\u30FC\u30BF.\n    */\n    void add_edge(int u, int v,\
    \ const Data &d, const Data &e) {\n        g[u].emplace_back((edge){v, (int)g[v].size(),\
    \ d});\n        g[v].emplace_back((edge){u, (int)g[u].size()-1, e});\n    }\n\n\
    \n    /**\n    * @brief \u5168\u65B9\u4F4D\u6728dp \u3092\u5B9F\u884C\u3059\u308B\
    .\n    * @return vector<T> \u5404\u9802\u70B9\u3092\u6839\u3068\u3057\u305F\u3068\
    \u304D\u306E\u6F14\u7B97\u306E\u7D50\u679C.\n    */\n    vector<T> solve() {\n\
    \        for (int i = 0; i < g.size(); ++i) {\n            ldp[i].assign(g[i].size()+1,\
    \ ident);\n            rdp[i].assign(g[i].size()+1, ident);\n            lptr[i]\
    \ = 0;\n            rptr[i] = (int)g[i].size()-1;\n            ldp[i][0] = init[i];\n\
    \        }\n        vector<T> ret(g.size());\n        for (int i = 0; i < g.size();\
    \ ++i) {\n            ret[i] = dfs(i, -1);\n        }\n        return ret;\n \
    \   }\n\nprivate:\n    struct edge {\n        int to, rev;\n        Data data;\n\
    \    };\n\n    vector<vector<edge>> g;\n    vector<vector<T>> ldp, rdp;\n    vector<int>\
    \ lptr, rptr;\n    const F1 f1;\n    const F2 f2;\n    const vector<T> init;\n\
    \    const T ident;\n\n    T dfs(int idx, int par) {\n        while (lptr[idx]\
    \ != par and lptr[idx] < g[idx].size()) {\n            auto &e = g[idx][lptr[idx]];\n\
    \            ldp[idx][lptr[idx]+1] = f1(\n                    ldp[idx][lptr[idx]],\n\
    \                    f2(dfs(e.to, e.rev), e.data));\n            ++lptr[idx];\n\
    \        }\n        while (rptr[idx] != par and rptr[idx] >= 0) {\n          \
    \  auto &e = g[idx][rptr[idx]];\n            rdp[idx][rptr[idx]] = f1(\n     \
    \               rdp[idx][rptr[idx]+1],\n                    f2(dfs(e.to, e.rev),\
    \ e.data));\n            --rptr[idx];\n        }\n        if (par < 0) return\
    \ rdp[idx][0];\n        return f1(ldp[idx][par], rdp[idx][par+1]);\n    }\n};\n\
    \n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief\n * \u5168\u65B9\u4F4D\u6728\
    dp\n * @author habara-k\n * @date 2020/05/18\n * @verify https://codeforces.com/gym/102433/submission/80588275\n\
    \ * @details \u4F7F\u3044\u65B9\n *   e.g. \u76F4\u5F84\n *   using T = pair<int,int>;\
    \ // \u9802\u70B9\u304C\u6301\u3064\u3079\u304D\u30C7\u30FC\u30BF\n *   using\
    \ Data = int;        // \u89AA\u304C\u5B50\u3092\u5F15\u3063\u5F35\u308A\u4E0A\
    \u3052\u308B\u3068\u304D\u306B\u5FC5\u8981\u306A\u30C7\u30FC\u30BF\n\n *   ReRooting<Data,T>\
    \ tr(\n *           n,\n *           [](T a, T b){\n *               vector<int>\
    \ v{a.first,a.second,b.first,b.second};\n *               sort(v.rbegin(),v.rend());\n\
    \ *               return T{v[0],v[1]};\n *               },                  \
    \     // \u5B50\u3092\u30DE\u30FC\u30B8\u3059\u308B\u6F14\u7B97\n *          \
    \ [](T a, Data w){\n *               return T{a.first+w, 0};\n *             \
    \  },                       // \u5B50\u3092\u5F15\u3063\u5F35\u308A\u4E0A\u3052\
    \u308B\u6F14\u7B97\n *           vector<T>(n, T{0, 0}),       // \u9802\u70B9\u304C\
    \u6301\u3064\u30C7\u30FC\u30BF\u306E\u521D\u671F\u5024\n *           T{0,0}  \
    \                     // \u5B50\u3092\u30DE\u30FC\u30B8\u3059\u308B\u6F14\u7B97\
    \u306E\u5358\u4F4D\u5143\n *           );\n *\n *   for (int i = 0; i < n-1; ++i)\
    \ {\n *       int s, t, w; cin >> s >> t >> w;\n *       tr.add_edge(s, t, Data{w},\
    \ Data{w});\n *   }\n *\n *   auto ans = tr.solve();\n */\n\ntemplate<typename\
    \ Data, typename T>\nstruct ReRooting {\n\n    using F1 = function<T(T, T)>;\n\
    \    using F2 = function<T(T, Data)>;\n\n    /**\n    * @brief \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF. O(1).\n    * @param[in] n: \u9802\u70B9\u6570\n    *\
    \ @param[in] f1: \u5B50\u304C\u6301\u3064\u30C7\u30FC\u30BF\u3092\u30DE\u30FC\u30B8\
    \u3059\u308B\u6F14\u7B97\n    * @param[in] f2: \u89AA\u304C\u5B50\u3092\u5F15\u3063\
    \u5F35\u308A\u4E0A\u3052\u308B\u6F14\u7B97\n    * @param[in] init: \u9802\u70B9\
    \u304C\u6301\u3064\u30C7\u30FC\u30BF\u306E\u521D\u671F\u5024\n    * @param[in]\
    \ ident: f1\u306E\u5358\u4F4D\u5143\n    */\n    ReRooting(\n            int n,\
    \ const F1 &f1, const F2 &f2,\n            const vector<T> &init, const T &ident)\
    \ :\n        g(n), ldp(n), rdp(n), lptr(n), rptr(n),\n        f1(f1), f2(f2),\
    \ init(init), ident(ident) {}\n\n    /**\n    * @brief \u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B. O(1)\n    * @param[in] u, v: \u8FBAu, v \u3092\u8FFD\u52A0\u3059\
    \u308B.\n    * @param[in] d: u \u304Cv \u3092\u5F15\u3063\u5F35\u308A\u4E0A\u3052\
    \u308B\u3068\u304D\u306B\u5FC5\u8981\u306A\u30C7\u30FC\u30BF.\n    * @param[in]\
    \ e: v \u304Cu \u3092\u5F15\u3063\u5F35\u308A\u4E0A\u3052\u308B\u3068\u304D\u306B\
    \u5FC5\u8981\u306A\u30C7\u30FC\u30BF.\n    */\n    void add_edge(int u, int v,\
    \ const Data &d, const Data &e) {\n        g[u].emplace_back((edge){v, (int)g[v].size(),\
    \ d});\n        g[v].emplace_back((edge){u, (int)g[u].size()-1, e});\n    }\n\n\
    \n    /**\n    * @brief \u5168\u65B9\u4F4D\u6728dp \u3092\u5B9F\u884C\u3059\u308B\
    .\n    * @return vector<T> \u5404\u9802\u70B9\u3092\u6839\u3068\u3057\u305F\u3068\
    \u304D\u306E\u6F14\u7B97\u306E\u7D50\u679C.\n    */\n    vector<T> solve() {\n\
    \        for (int i = 0; i < g.size(); ++i) {\n            ldp[i].assign(g[i].size()+1,\
    \ ident);\n            rdp[i].assign(g[i].size()+1, ident);\n            lptr[i]\
    \ = 0;\n            rptr[i] = (int)g[i].size()-1;\n            ldp[i][0] = init[i];\n\
    \        }\n        vector<T> ret(g.size());\n        for (int i = 0; i < g.size();\
    \ ++i) {\n            ret[i] = dfs(i, -1);\n        }\n        return ret;\n \
    \   }\n\nprivate:\n    struct edge {\n        int to, rev;\n        Data data;\n\
    \    };\n\n    vector<vector<edge>> g;\n    vector<vector<T>> ldp, rdp;\n    vector<int>\
    \ lptr, rptr;\n    const F1 f1;\n    const F2 f2;\n    const vector<T> init;\n\
    \    const T ident;\n\n    T dfs(int idx, int par) {\n        while (lptr[idx]\
    \ != par and lptr[idx] < g[idx].size()) {\n            auto &e = g[idx][lptr[idx]];\n\
    \            ldp[idx][lptr[idx]+1] = f1(\n                    ldp[idx][lptr[idx]],\n\
    \                    f2(dfs(e.to, e.rev), e.data));\n            ++lptr[idx];\n\
    \        }\n        while (rptr[idx] != par and rptr[idx] >= 0) {\n          \
    \  auto &e = g[idx][rptr[idx]];\n            rdp[idx][rptr[idx]] = f1(\n     \
    \               rdp[idx][rptr[idx]+1],\n                    f2(dfs(e.to, e.rev),\
    \ e.data));\n            --rptr[idx];\n        }\n        if (par < 0) return\
    \ rdp[idx][0];\n        return f1(ldp[idx][par], rdp[idx][par+1]);\n    }\n};\n\
    \n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/re_rooting.cpp
  requiredBy: []
  timestamp: '2020-05-18 18:41:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/re_rooting.test.cpp
documentation_of: lib/graph/re_rooting.cpp
layout: document
redirect_from:
- /library/lib/graph/re_rooting.cpp
- /library/lib/graph/re_rooting.cpp.html
title: "\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. O(1)."
---
