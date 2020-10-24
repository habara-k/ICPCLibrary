---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/persistent_segment_tree.cpp
    title: "\u5B8C\u5168\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/tree/lowest_common_ancestor.cpp
    title: LCA
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270
  bundledCode: "#line 1 \"test/structure/persistent_segment_tree.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270\"\n\n\
    #line 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i, n) for\
    \ (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n); ++i)\n\
    #define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n\
    #define ALL(x) (x).begin(),(x).end()\n\n#define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\
    #define DEBUG(x) cerr<<#x<<\" = \"<<(x)<<\" (L\"<<__LINE__<<\")\"<<endl;\n\ntemplate<class\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/structure/persistent_segment_tree.cpp\"\
    \n\n/**\n* @brief \u5B8C\u5168\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n* @author habara-k\n* @date 2020/05/04\n* @details \u4F7F\u3044\u65B9\n*   build,\
    \ update\u3059\u308B\u305F\u3073\u306BNode* \u304C\u8FD4\u308B.\n*   \u3053\u308C\
    \u3092\u4FDD\u5B58\u3057\u3066\u7F6E\u3044\u3066, \u53D6\u5F97\u6642\u306B\u5229\
    \u7528\u3059\u308B.\n*\n*   e.g.\n*   vector<vector<int>> g(n) // tree;\n*   PersistentSegmentTree<int>\
    \ segt(\n*           sz, [](int a,int b){ return a+b; }, 0);\n*\n*   // \u9802\
    \u70B9 -> Node* \u3092\u4FDD\u5B58\u3059\u308B.\n*   map<int,PersistentSegmentTree<int>::Node*>\
    \ root;\n*\n*   function<void(int,int)> dfs = [&](int v, int p) {\n*       root[v]\
    \ = segt.update(root[p],\n*               x[v], [](int a){ return a+1; });\n*\
    \       for (int u : G[v]) {\n*           if (u != p) dfs(u, v);\n*       }\n\
    *   };\n*\n*   root[-1] = segt.build();\n*   dfs(0, -1);\n*/\ntemplate<typename\
    \ M>\nstruct PersistentSegmentTree {\n    struct Node {\n        Node *l, *r;\n\
    \        M data;\n        Node() : l(nullptr), r(nullptr) {}\n    };\n\n    /**\n\
    \    * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. O(1)\n    * @param[in]\
    \ n \u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30B5\u30A4\u30BA.\n    * @param[in]\
    \ f \u30E2\u30CE\u30A4\u30C9\u306E\u6F14\u7B97.\n    * @param[in] e \u30E2\u30CE\
    \u30A4\u30C9\u306E\u5358\u4F4D\u5143.\n    * @details \u4F7F\u3044\u65B9\n   \
    \ *   e.g. Range Sum\n    *   PersistentSegmentTree<int> segt(\n    *        \
    \    n, [](int a,int b){ return a+b; }, 0);\n    */\n    PersistentSegmentTree(int\
    \ n, const function<M(M,M)>& f, const M& e) :\n            n(n), f(f), e(e) {}\n\
    \n    /**\n    * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\
    \u3059\u308B. O(nlog n)\n    * @details \u4F7F\u3044\u65B9\n    *   root[-1] =\
    \ segt.build();\n    */\n    Node* build() const {\n        return build(0, n);\n\
    \    }\n\n    /**\n    * @brief \u6307\u5B9A\u3057\u305F\u4F4D\u7F6E\u306B\u66F4\
    \u65B0\u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B. O(log n)\n    * @param[in]\
    \ root: \u4F5C\u7528\u3055\u305B\u308B\u30BB\u30B0\u6728\u306E\u6839.\n    * @param[in]\
    \ k: \u4F4D\u7F6Ek \u306E\u8981\u7D20\u306B\u4F5C\u7528\u3055\u305B\u308B.\n \
    \   * @param[in] q: \u5024x \u3092q(x) \u3067\u66F4\u65B0\u3059\u308B.\n    *\
    \ @details \u4F7F\u3044\u65B9\n    *   e.g. Add Query\n    *   int i, x; // \u4F4D\
    \u7F6Ei \u3092x \u3092\u8DB3\u3057\u305F\u3044.\n    *   root[v] = segt.update(root[p],\
    \ i, [&](int a){ return a + x; });\n    *\n    *   e.g. Update Query\n    *  \
    \ int i, x; // \u4F4D\u7F6Ei \u3092x \u306B\u66F4\u65B0\u3057\u305F\u3044.\n \
    \   *   root[v] = segt.update(root[p], i, [&](int a){ return x; });\n    */\n\
    \    template<typename UpdateQuery>\n    Node* update(Node* root, int k, const\
    \ UpdateQuery& q) const {\n        return update(root, k, q, 0, n);\n    }\n\n\
    \    /**\n    * @brief \u6307\u5B9A\u3057\u305F\u533A\u9593\u306B\u53D6\u5F97\u30AF\
    \u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B. O(log n)\n    * @param[in] l, r \u533A\
    \u9593[l, r) \u3092\u53D6\u5F97\u3059\u308B.\n    * @return \u53D6\u5F97\u3057\
    \u305F\u5024.\n    * @details \u4F7F\u3044\u65B9\n    *   e.g. Range Minimum\n\
    \    *   int l, r; // \u533A\u9593[l, r) \u306Emin\u3092\u53D6\u5F97\u3057\u305F\
    \u3044.\n    *   cout << segt.query(root[v], l, r) << endl;\n    */\n    M query(Node*\
    \ root, int a, int b) const {\n        return query(root, a, b, 0, n);\n    }\n\
    \nprivate:\n    const int n;\n    const function<M(M,M)> f;\n    const M e;\n\n\
    \    Node* _new(const M& data) const {\n        auto t = new Node();\n       \
    \ t->data = data;\n        return t;\n    }\n\n    Node* _new(Node* l, Node* r)\
    \ const {\n        auto t = new Node();\n        t->l = l, t->r = r, t->data =\
    \ f(l->data, r->data);\n        return t;\n    }\n\n    Node* build(int l, int\
    \ r) const {\n        assert(l < r);\n        if (l + 1 == r) return _new(e);\n\
    \        return _new(build(l, (l + r) >> 1), build((l + r) >> 1, r));\n    }\n\
    \n    template<typename UpdateQuery>\n    Node* update(Node* t, int k, const UpdateQuery&\
    \ q, int l, int r) const {\n        if (k == l and k + 1 == r) return _new(q(t->data));\n\
    \        if (r <= k or k < l) return t;\n        return _new(update(t->l, k, q,\
    \ l, (l + r) >> 1),\n                    update(t->r, k, q, (l + r) >> 1, r));\n\
    \    }\n\n    M query(Node* t, int a, int b, int l, int r) const {\n        if\
    \ (r <= a or b <= l) return e;\n        if (a <= l and r <= b) return t->data;\n\
    \        return f(query(t->l, a, b, l, (l + r) >> 1),\n                 query(t->r,\
    \ a, b, (l + r) >> 1, r));\n    }\n};\n#line 2 \"lib/tree/lowest_common_ancestor.cpp\"\
    \n\n/**\n * @brief LCA\n * @author habara-k\n * @date 2020/10/15\n */\nstruct\
    \ LCA {\n\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF.\
    \ O(VlogV)\n     * @param[in] g \u7121\u5411\u6728\n     * @param[in] root \u6839\
    \n     */\n    LCA(const vector<vector<int>> &g, int root = 0) :\n           \
    \ n(g.size()), m(log2(n)), depth(n),\n            g(g), par(m + 1, vector<int>(n,\
    \ -1)) {\n\n        dfs(root, -1, 0);\n\n        for (int k = 0; k < m; ++k) {\n\
    \            for (int v = 0; v < n; ++v) {\n                if (par[k][v] != -1)\
    \ {\n                    par[k + 1][v] = par[k][par[k][v]];\n                }\n\
    \            }\n        }\n    }\n\n    /**\n     * @brief lca \u3092\u53D6\u5F97\
    \u3059\u308B. O(logV)\n     */\n    int query(int u, int v) {\n        if (depth[u]\
    \ > depth[v]) swap(u, v);\n        for (int k = 0; k <= m; ++k) {\n          \
    \  if ((depth[v] - depth[u]) >> k & 1) {\n                v = par[k][v];\n   \
    \         }\n        }\n        if (u == v) return u;\n        for (int k = m;\
    \ k >= 0; --k) {\n            if (par[k][u] != par[k][v]) {\n                u\
    \ = par[k][u];\n                v = par[k][v];\n            }\n        }\n   \
    \     return par[0][u];\n    }\n\n    /**\n     * @brief \u9802\u70B9u,v\u9593\
    \u306E\u8DDD\u96E2\u3092\u53D6\u5F97\u3059\u308B. O(logV)\n     */\n    int dist(int\
    \ u, int v) {\n        return depth[u] + depth[v] - 2 * depth[query(u,v)];\n \
    \   }\n\nprivate:\n    int n, m;\n    vector<int> depth;\n    vector<vector<int>>\
    \ g, par;\n\n    void dfs(int u, int p, int d) {\n        depth[u] = d;\n    \
    \    par[0][u] = p;\n        for (auto v : g[u]) {\n            if (v != p) dfs(v,\
    \ u, d + 1);\n        }\n    }\n};\n\n#line 5 \"test/structure/persistent_segment_tree.test.cpp\"\
    \n\nint main()\n{\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> x(N);\n\
    \    for (int i = 0; i < N; ++i) {\n        cin >> x[i];\n    }\n\n    vector<vector<int>>\
    \ G(N);\n    for (int i = 0; i < N-1; ++i) {\n        int a, b; cin >> a >> b;\n\
    \        --a, --b;\n        G[a].push_back(b);\n        G[b].push_back(a);\n \
    \   }\n\n    // compress\n    map<int,int> comp, comp_inv;\n    for (auto X :\
    \ x) comp[X] = -1;\n    int comp_size = 0;\n    for (auto &p : comp) {\n     \
    \   p.second = comp_size++;\n    }\n    for (auto p : comp) {\n        comp_inv[p.second]\
    \ = p.first;\n    }\n\n    // lca\n    auto lca = LCA(G);\n\n    // persistent\
    \ segtree\n    PersistentSegmentTree<int> segt(\n            comp.size(), [](int\
    \ a,int b){ return a+b; }, 0);\n\n    map<int,PersistentSegmentTree<int>::Node*>\
    \ root;\n    vector<int> par(N);\n\n    function<void(int,int)> dfs = [&](int\
    \ v, int p) {\n        par[v] = p;\n        root[v] = segt.update(root[p],\n \
    \               comp[x[v]], [](int a){ return a+1; });\n        for (int u : G[v])\
    \ {\n            if (u != p) dfs(u, v);\n        }\n    };\n\n    root[-1] = segt.build();\n\
    \    dfs(0, -1);\n\n    for (int i = 0; i < Q; ++i)\n    {\n        int v, w,\
    \ l; cin >> v >> w >> l; --v, --w;\n\n        // search x s.t. there are more\
    \ than l numbers less than or equal to x\n\n        int u = lca.query(v, w);\n\
    \n        auto check = [&](int m) {\n            int nv = segt.query(root[v],\
    \ 0, m+1),\n                nw = segt.query(root[w], 0, m+1),\n              \
    \  nu = segt.query(root[u], 0, m+1),\n                np = segt.query(root[par[u]],\
    \ 0, m+1);\n\n            return nv + nw - nu - np >= l;\n        };\n\n     \
    \   int ng = -1, ok = comp.size()-1;\n        while (abs(ok - ng) > 1) {\n   \
    \         int mid = (ng + ok) / 2;\n            (check(mid) ? ok : ng) = mid;\n\
    \        }\n\n        cout << comp_inv[ok] << endl;\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270\"\
    \n\n#include \"../../lib/structure/persistent_segment_tree.cpp\"\n#include \"\
    ../../lib/tree/lowest_common_ancestor.cpp\"\n\nint main()\n{\n    int N, Q;\n\
    \    cin >> N >> Q;\n    vector<int> x(N);\n    for (int i = 0; i < N; ++i) {\n\
    \        cin >> x[i];\n    }\n\n    vector<vector<int>> G(N);\n    for (int i\
    \ = 0; i < N-1; ++i) {\n        int a, b; cin >> a >> b;\n        --a, --b;\n\
    \        G[a].push_back(b);\n        G[b].push_back(a);\n    }\n\n    // compress\n\
    \    map<int,int> comp, comp_inv;\n    for (auto X : x) comp[X] = -1;\n    int\
    \ comp_size = 0;\n    for (auto &p : comp) {\n        p.second = comp_size++;\n\
    \    }\n    for (auto p : comp) {\n        comp_inv[p.second] = p.first;\n   \
    \ }\n\n    // lca\n    auto lca = LCA(G);\n\n    // persistent segtree\n    PersistentSegmentTree<int>\
    \ segt(\n            comp.size(), [](int a,int b){ return a+b; }, 0);\n\n    map<int,PersistentSegmentTree<int>::Node*>\
    \ root;\n    vector<int> par(N);\n\n    function<void(int,int)> dfs = [&](int\
    \ v, int p) {\n        par[v] = p;\n        root[v] = segt.update(root[p],\n \
    \               comp[x[v]], [](int a){ return a+1; });\n        for (int u : G[v])\
    \ {\n            if (u != p) dfs(u, v);\n        }\n    };\n\n    root[-1] = segt.build();\n\
    \    dfs(0, -1);\n\n    for (int i = 0; i < Q; ++i)\n    {\n        int v, w,\
    \ l; cin >> v >> w >> l; --v, --w;\n\n        // search x s.t. there are more\
    \ than l numbers less than or equal to x\n\n        int u = lca.query(v, w);\n\
    \n        auto check = [&](int m) {\n            int nv = segt.query(root[v],\
    \ 0, m+1),\n                nw = segt.query(root[w], 0, m+1),\n              \
    \  nu = segt.query(root[u], 0, m+1),\n                np = segt.query(root[par[u]],\
    \ 0, m+1);\n\n            return nv + nw - nu - np >= l;\n        };\n\n     \
    \   int ng = -1, ok = comp.size()-1;\n        while (abs(ok - ng) > 1) {\n   \
    \         int mid = (ng + ok) / 2;\n            (check(mid) ? ok : ng) = mid;\n\
    \        }\n\n        cout << comp_inv[ok] << endl;\n    }\n\n    return 0;\n\
    }\n"
  dependsOn:
  - lib/structure/persistent_segment_tree.cpp
  - lib/template.cpp
  - lib/tree/lowest_common_ancestor.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/structure/persistent_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2020-10-16 15:26:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/persistent_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/structure/persistent_segment_tree.test.cpp
- /verify/test/structure/persistent_segment_tree.test.cpp.html
title: test/structure/persistent_segment_tree.test.cpp
---
