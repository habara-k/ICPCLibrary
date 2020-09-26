---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/structure/union_find.cpp
    title: lib/structure/union_find.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal.test.cpp
    title: test/graph/kruskal.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
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
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/kruskal.cpp\"\n\
    \n#line 2 \"lib/structure/union_find.cpp\"\n\nstruct UnionFind\n{\n    vector<int>\
    \ par, sz;\n    UnionFind(int n) : par(n), sz(n, 1) {\n        for (int i = 0;\
    \ i < n; ++i) par[i] = i;\n    }\n    int root(int x) {\n        if (par[x] ==\
    \ x) return x;\n        return par[x] = root(par[x]);\n    }\n    void merge(int\
    \ x, int y) {\n        x = root(x);\n        y = root(y);\n        if (x == y)\
    \ return;\n        if (sz[x] < sz[y]) swap(x, y);\n        par[y] = x;\n     \
    \   sz[x] += sz[y];\n        sz[y] = 0;\n    }\n    bool issame(int x, int y)\
    \ {\n        return root(x) == root(y);\n    }\n    int size(int x) {\n      \
    \  return sz[root(x)];\n    }\n};\n#line 4 \"lib/graph/kruskal.cpp\"\n\n/**\n\
    \ * @brief\n * \u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5\uFF08\u6700\u5C0F\u5168\u57DF\
    \u6728\uFF09\n * O(|E|log|E|)\n * \u5927\u304D\u3055\u3060\u3051\u6C42\u3081\u3066\
    \u308B\u3051\u3069\u69CB\u7BC9\u3082\u3059\u3050\u66F8\u3051\u308B\u306F\u305A\
    \uFF08merge\u306E\u30BF\u30A4\u30DF\u30F3\u30B0\u3067\u767B\u9332\uFF09\n *\n\
    \ * @author ?\n * @date 2019/12\n */\n\ntemplate<typename T>\nT kruskal(vector<edge<T>>\
    \ &es, int V) {\n\n    UnionFind uf(V);\n    T ret = 0;\n\n    // sort destructively\n\
    \    sort(es.begin(), es.end(), [](edge<T> &a,edge<T> &b){\n            return\
    \ a.cost < b.cost;\n            });\n    for (auto &e : es) {\n        if (!uf.issame(e.src,\
    \ e.to)) {\n            ret += e.cost;\n            uf.merge(e.src, e.to);\n \
    \       }\n    }\n\n    // // sort only the order to check\n    // vector<int>\
    \ ord(es.size());\n    // iota(ord.begin(), ord.end(), 0);\n    // sort(ord.begin(),\
    \ ord.end(), [&](int i,int j){\n    //         return es[i].cost < es[j].cost;\n\
    \    //         });\n    // for (auto i : ord) {\n    //     auto &e = es[i];\n\
    \    //     if (!uf.issame(e.src, e.to)) {\n    //         ret += e.cost;\n  \
    \  //         uf.merge(e.src, e.to);\n    //     }\n    // }\n\n    return ret;\n\
    }\n"
  code: "#include \"template.cpp\"\n\n#include \"../structure/union_find.cpp\"\n\n\
    /**\n * @brief\n * \u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5\uFF08\u6700\u5C0F\u5168\
    \u57DF\u6728\uFF09\n * O(|E|log|E|)\n * \u5927\u304D\u3055\u3060\u3051\u6C42\u3081\
    \u3066\u308B\u3051\u3069\u69CB\u7BC9\u3082\u3059\u3050\u66F8\u3051\u308B\u306F\
    \u305A\uFF08merge\u306E\u30BF\u30A4\u30DF\u30F3\u30B0\u3067\u767B\u9332\uFF09\n\
    \ *\n * @author ?\n * @date 2019/12\n */\n\ntemplate<typename T>\nT kruskal(vector<edge<T>>\
    \ &es, int V) {\n\n    UnionFind uf(V);\n    T ret = 0;\n\n    // sort destructively\n\
    \    sort(es.begin(), es.end(), [](edge<T> &a,edge<T> &b){\n            return\
    \ a.cost < b.cost;\n            });\n    for (auto &e : es) {\n        if (!uf.issame(e.src,\
    \ e.to)) {\n            ret += e.cost;\n            uf.merge(e.src, e.to);\n \
    \       }\n    }\n\n    // // sort only the order to check\n    // vector<int>\
    \ ord(es.size());\n    // iota(ord.begin(), ord.end(), 0);\n    // sort(ord.begin(),\
    \ ord.end(), [&](int i,int j){\n    //         return es[i].cost < es[j].cost;\n\
    \    //         });\n    // for (auto i : ord) {\n    //     auto &e = es[i];\n\
    \    //     if (!uf.issame(e.src, e.to)) {\n    //         ret += e.cost;\n  \
    \  //         uf.merge(e.src, e.to);\n    //     }\n    // }\n\n    return ret;\n\
    }\n"
  dependsOn:
  - lib/graph/template.cpp
  - lib/template.cpp
  - lib/structure/union_find.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/kruskal.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/kruskal.test.cpp
documentation_of: lib/graph/kruskal.cpp
layout: document
redirect_from:
- /library/lib/graph/kruskal.cpp
- /library/lib/graph/kruskal.cpp.html
title: lib/graph/kruskal.cpp
---
