---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/red_black_tree.cpp
    title: lib/structure/red_black_tree.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
  bundledCode: "#line 1 \"test/structure/red_black_tree/shift_rmq.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\n\n\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/structure/red_black_tree.cpp\"\n\n/**\n\
    \ * @breif \u8D64\u9ED2\u6728\n * @ref\n * https://ei1333.github.io/luzhiled/snippets/structure/red-black-tree.html\n\
    \ * http://blog.mitaki28.info/1447078746296/\n * @author habara-k\n * @data 2020/10/22\n\
    \ * @details\n * merge, split, insert, erase, range-query, range-update: O(log\
    \ n)\n * WARNING: POOL >= 2*MAX_N \u3068\u306A\u308B\u3088\u3046\u306BPOOL\u3092\
    \u3068\u308B\n */\ntemplate<\n        class M,\n        M (*f)(M,M),\n       \
    \ M (*e)(),\n        class OM,\n        M (*g)(M, OM),\n        OM (*h)(OM, OM),\n\
    \        OM (*id)(),\n        int POOL>\nstruct RBTree {\n    RBTree() : pool(POOL),\
    \ stock(POOL) { clear(); }\n\n    static const bool R = 0, B = 1;\n    struct\
    \ node;\n    using ptr = node*;\n    struct node {\n        ptr l=nullptr, r=nullptr;\n\
    \        M prd = e();\n        OM lazy = id();\n        int sz=1, rnk=0;\n   \
    \     bool color=B;\n        node() {}\n        node(M val) : prd(val) {}\n  \
    \      node(ptr l, ptr r, int color) : l(l), r(r), prd(f(l->prd,r->prd)),\n  \
    \                                      sz(l->sz + r->sz), rnk(l->rnk + l->color),\
    \ color(color) {}\n    };\n    int size() { return size(root); }\n    int size(ptr\
    \ p) { return p ? p->sz : 0; }\n\n    void build(const vector<M>& init) {\n  \
    \      root = build(init, 0, init.size());\n    }\n\n    ptr merge(ptr a, ptr\
    \ b) {\n        if (!a) return b;\n        if (!b) return a;\n        auto c =\
    \ mergeSub(a, b);\n        return asRoot(c);\n    }\n    pair<ptr,ptr> split(ptr\
    \ a, int k) {\n        assert(0 <= k and k <= size(a));\n        if (k == 0) return\
    \ {nullptr, a};\n        if (k == size(a)) return {a, nullptr};\n        a = push(a);\n\
    \        ptr l = a->l, r = a->r;\n        del(a);\n        if (k < l->sz) {\n\
    \            auto p = split(l, k);\n            return {p.first, merge(p.second,\
    \ asRoot(r))};\n        }\n        if (k > l->sz) {\n            auto p = split(r,\
    \ k - l->sz);\n            return {merge(asRoot(l), p.first), p.second};\n   \
    \     }\n        return {asRoot(l), asRoot(r)};\n    }\n\n    void insert(int\
    \ k, M val) {\n        assert(0 <= k and k <= size());\n        auto p = split(root,\
    \ k);\n        root = merge(merge(p.first, alloc(val)), p.second);\n    }\n  \
    \  M erase(int k) {\n        assert(0 <= k and k < size());\n        auto p =\
    \ split(root, k);\n        auto q = split(p.second, 1);\n        M val = q.first->prd;\n\
    \        del(q.first);\n        root = merge(p.first, q.second);\n        return\
    \ val;\n    }\n\n    M prod(int l, int r) {\n        assert(0 <= l and l <= r\
    \ and r <= size());\n        return prod(root, 0, root->sz, id(), l, r);\n   \
    \ }\n    M operator[](int k) {\n        assert(0 <= k and k < size());\n     \
    \   return prod(k, k+1);\n    }\n    void apply(int l, int r, OM lazy) {\n   \
    \     assert(0 <= l and l <= r and r <= size());\n        auto p = split(root,\
    \ l);\n        auto q = split(p.second, r-l);\n        root = merge(p.first, merge(set_lazy(q.first,\
    \ lazy), q.second));\n    }\n    friend ostream &operator<<(ostream &os, RBTree\
    \ &t) {\n        for (int i = 0; i < t.root->sz; ++i) {\n            if (i) cout\
    \ << ' ';\n            cout << t[i];\n        }\n        return os;\n    }\n \
    \   ptr root;\n\nprotected:\n\n    vector<node> pool;\n    vector<ptr> stock;\n\
    \    int head = POOL;\n\n    template<typename... U>\n    ptr alloc(U... args)\
    \ {\n        return &(*stock[--head] = node(args...));\n    }\n    void delf(ptr\
    \ p) {\n        stock[head++] = p;\n    }\n    virtual void del(ptr p) {\n   \
    \     delf(p);\n    }\n    void clear() {\n        head = POOL;\n        for (int\
    \ i = 0; i < POOL; ++i) stock[i] = &pool[i];\n    }\n    inline virtual ptr clone(ptr\
    \ p) {\n        return p;\n    }\n\n    ptr set_lazy(ptr p, const OM& lazy) {\n\
    \        p = clone(p);\n        p->prd = g(p->prd, lazy);\n        if (p->l) p->lazy\
    \ = h(p->lazy, lazy);\n        return p;\n    }\n\n    ptr push(ptr p) {\n   \
    \     if (p->lazy == id()) return p;\n        p->l = set_lazy(p->l, p->lazy);\n\
    \        p->r = set_lazy(p->r, p->lazy);\n        p->lazy = id();\n        return\
    \ p;\n    }\n\n    ptr build(const vector<M>& init, int l, int r) {\n        if\
    \ (r - l == 1) return alloc(init[l]);\n        return merge(build(init, l, (l+r)/2),\
    \ build(init, (l+r)/2, r));\n    }\n\n    ptr mergeSub(ptr a, ptr b) {\n     \
    \   if (a->rnk < b->rnk) {\n            b = push(b);\n            auto c = mergeSub(a,\
    \ b->l);\n            ptr ret;\n            if (b->color and !c->color and !c->l->color)\
    \ {\n                if (b->r->color) ret = alloc(c->l, alloc(c->r, b->r, R),\
    \ B), delf(c);\n                else ret = alloc(asRoot(c), asRoot(b->r), R);\n\
    \            } else {\n                ret = alloc(c, b->r, b->color);\n     \
    \       }\n            del(b); return ret;\n        } else if (a->rnk > b->rnk)\
    \ {\n            a = push(a);\n            auto c = mergeSub(a->r, b);\n     \
    \       ptr ret;\n            if (a->color and !c->color and !c->r->color) {\n\
    \                if (a->l->color) ret = alloc(alloc(a->l, c->l, R), c->r, B),\
    \ delf(c);\n                else ret = alloc(asRoot(a->l), asRoot(c), R);\n  \
    \          } else {\n                ret = alloc(a->l, c, a->color);\n       \
    \     }\n            del(a); return ret;\n        } else {\n            return\
    \ alloc(a, b, R);\n        }\n    }\n\n    ptr asRoot(ptr p) {\n        if (!p\
    \ or p->color) return p;\n        p->color = B;\n        return p;\n    }\n\n\
    \    M prod(ptr p, int a, int b, OM lazy, int l, int r) {\n        if (b <= l\
    \ or r <= a) return e();\n        if (l <= a and b <= r) return g(p->prd, lazy);\n\
    \        return f(prod(p->l, a, a + p->l->sz, h(p->lazy, lazy), l, r),\n     \
    \            prod(p->r, b - p->r->sz, b, h(p->lazy, lazy), l, r));\n    }\n};\n\
    \n/**\n * @breif \u6C38\u7D9A\u8D64\u9ED2\u6728\n * @ref\n * https://ei1333.github.io/luzhiled/snippets/structure/red-black-tree.html\n\
    \ * http://blog.mitaki28.info/1447078746296/\n * @author habara-k\n * @data 2020/10/22\n\
    \ * @details\n * copy-and-paste \u304C\u3067\u304D\u308B.\n * WARNING: POOL\u306F\
    \u3067\u304D\u308B\u3060\u3051\u5927\u304D\u304F\u3068\u308B(\u30E1\u30E2\u30EA\
    \u5236\u7D04\u3092\u78BA\u8A8D)\n * WARNING: \u30AF\u30A8\u30EA\u306E\u7D42\u308F\
    \u308A\u306B\u5FC5\u305A if (full()) rebuild() \u3092\u547C\u3076.\n */\ntemplate<\n\
    \        class M,\n        M (*f)(M,M),\n        M (*e)(),\n        class OM,\n\
    \        M (*g)(M, OM),\n        OM (*h)(OM, OM),\n        OM (*id)(),\n     \
    \   int POOL,\n        int FULL=1000>\nstruct PersistentRBTree : RBTree<M,f,e,OM,g,h,id,POOL>\
    \ {\n    using RBT = RBTree<M,f,e,OM,g,h,id,POOL>;\n    using ptr = typename RBT::ptr;\n\
    \    inline ptr clone(ptr p) override {\n        return &(*this->stock[--this->head]\
    \ = *p);\n    }\n    inline void del(ptr p) override {}\n    bool full() {\n \
    \       return this->head < FULL;\n    }\n    void rebuild() {\n        vector<M>\
    \ data(this->size());\n        auto it = data.begin();\n        dfs(this->root,\
    \ id(), it);\n        this->clear();\n        this->build(data);\n    }\n    void\
    \ dfs(ptr p, OM lazy, typename vector<M>::iterator& it) {\n        if (!p->l)\
    \ {\n            *it++ = g(p->prd, lazy);\n            return;\n        }\n  \
    \      lazy = h(lazy, p->lazy);\n        dfs(p->l, lazy, it);\n        dfs(p->r,\
    \ lazy, it);\n    }\n};\n\n#line 4 \"test/structure/red_black_tree/shift_rmq.test.cpp\"\
    \n\nusing M = int;\nusing OM = int;\nM f(M a, M b) { return min(a,b); }\nM e()\
    \ { return INF; }\nOM id() { return INF; }\nOM h(OM a, OM b) {\n    if (a==id())\
    \ return b;\n    if (b==id()) return a;\n    return b;\n}\nM g(M a, OM b) {\n\
    \    if (b==id()) return a;\n    return b;\n}\n\nint main() {\n    int n, q; cin\
    \ >> n >> q;\n    vi a(n); REP(i, n) cin >> a[i];\n    RBTree<M,f,e,OM,g,h,id,500000>\
    \ tree;\n    tree.build(a);\n    while (q--) {\n        int t; cin >> t;\n   \
    \     if (t == 0) {\n            int l, r; cin >> l >> r;\n            M val =\
    \ tree.erase(r);\n            tree.insert(l, val);\n        }\n        if (t ==\
    \ 1) {\n            int l, r; cin >> l >> r;\n            cout << tree.prod(l,\
    \ r+1) << endl;\n        }\n        if (t == 2) {\n            int pos, val; cin\
    \ >> pos >> val;\n            tree.apply(pos, pos+1, val);\n        }\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\
    \n\n#include \"../../../lib/structure/red_black_tree.cpp\"\n\nusing M = int;\n\
    using OM = int;\nM f(M a, M b) { return min(a,b); }\nM e() { return INF; }\nOM\
    \ id() { return INF; }\nOM h(OM a, OM b) {\n    if (a==id()) return b;\n    if\
    \ (b==id()) return a;\n    return b;\n}\nM g(M a, OM b) {\n    if (b==id()) return\
    \ a;\n    return b;\n}\n\nint main() {\n    int n, q; cin >> n >> q;\n    vi a(n);\
    \ REP(i, n) cin >> a[i];\n    RBTree<M,f,e,OM,g,h,id,500000> tree;\n    tree.build(a);\n\
    \    while (q--) {\n        int t; cin >> t;\n        if (t == 0) {\n        \
    \    int l, r; cin >> l >> r;\n            M val = tree.erase(r);\n          \
    \  tree.insert(l, val);\n        }\n        if (t == 1) {\n            int l,\
    \ r; cin >> l >> r;\n            cout << tree.prod(l, r+1) << endl;\n        }\n\
    \        if (t == 2) {\n            int pos, val; cin >> pos >> val;\n       \
    \     tree.apply(pos, pos+1, val);\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/structure/red_black_tree.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/structure/red_black_tree/shift_rmq.test.cpp
  requiredBy: []
  timestamp: '2020-10-26 23:14:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/red_black_tree/shift_rmq.test.cpp
layout: document
redirect_from:
- /verify/test/structure/red_black_tree/shift_rmq.test.cpp
- /verify/test/structure/red_black_tree/shift_rmq.test.cpp.html
title: test/structure/red_black_tree/shift_rmq.test.cpp
---
