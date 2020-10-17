---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/mint.cpp
    title: lib/number/mint.cpp
  - icon: ':heavy_check_mark:'
    path: lib/structure/lazy_segment_tree.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo-judge/range_affine_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#line\
    \ 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i, n) for (int i=(int)(n)-1;\
    \ i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n); ++i)\n#define RFOR(i,\
    \ a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/structure/lazy_segment_tree.cpp\"\n\n\
    /**\n* @brief \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n* @author habara-k\n\
    * @date 2020/04/26\n*/\n\ntemplate<typename M, typename OM = M>\nstruct LazySegmentTree\
    \ {\n\n    /**\n    * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. O(n)\n\
    \    * @param[in] n \u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30B5\u30A4\u30BA.\n\
    \    * @param[in] f \u8981\u7D20\u30E2\u30CE\u30A4\u30C9\u306E\u6F14\u7B97.\n\
    \    * @param[in] g \u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\u4F5C\u7528\u3055\
    \u305B\u308B\u6F14\u7B97.\n    * @param[in] h \u4F5C\u7528\u7D20\u30E2\u30CE\u30A4\
    \u30C9\u306E\u6F14\u7B97.\n    * @param[in] e \u8981\u7D20\u30E2\u30CE\u30A4\u30C9\
    \u306E\u5358\u4F4D\u5143.\n    * @param[in] oe \u4F5C\u7528\u7D20\u30E2\u30CE\u30A4\
    \u30C9\u306E\u5358\u4F4D\u5143.\n    * @details \u4F7F\u3044\u65B9\n    *   e.g.\
    \ Range Add Range Sum\n    *   LazySegmentTree<int> segt(\n    *            n,\n\
    \    *            [](int a,int b){ return a+b; },\n    *            [](int a,int\
    \ b,int w){ return a + b*w; },\n    *            [](int a,int b){ return a+b;\
    \ },\n    *            0, 0);\n    *               // \u5168\u3066\u5358\u4F4D\
    \u5143\u3067\u521D\u671F\u5316\u3055\u308C\u308B.\n    */\n    LazySegmentTree(\n\
    \            int n,\n            const function<M(M,M)>& f,\n            const\
    \ function<M(M,OM,int)>& g,\n            const function<OM(OM,OM)>& h,\n     \
    \       const M& e, const OM& oe\n            ) : n(n), f(f), g(g), h(h), e(e),\
    \ oe(oe) {\n        sz = 1;\n        while (sz < n) sz <<= 1;\n        data.assign(2\
    \ * sz, e);\n        lazy.assign(2 * sz, oe);\n    }\n\n    /**\n    * @brief\
    \ \u5168\u4F53\u306B\u521D\u671F\u5024\u3092\u5165\u308C\u308B. O(n)\n    * @param[in]\
    \ v \u8981\u7D20\u30E2\u30CE\u30A4\u30C9\u306Evector. \u521D\u671F\u5316\u3059\
    \u308B.\n    * @details \u4F7F\u3044\u65B9\n    *   segt.build(vector<int>(n,\
    \ INF));\n    */\n    void build(const vector<M>& v) {\n        assert(v.size()\
    \ <= n);\n        for (int i = 0; i < v.size(); ++i) {\n            data[i + sz]\
    \ = v[i];\n        }\n        for (int i = sz-1; i > 0; --i) {\n            data[i]\
    \ = f(data[2 * i], data[2 * i + 1]);\n        }\n    }\n\n    /**\n    * @brief\
    \ \u6307\u5B9A\u3057\u305F\u533A\u9593\u306B\u4F5C\u7528\u7D20x \u3092\u4F5C\u7528\
    \u3055\u305B\u308B. O(log n)\n    * @param[in] l, r \u533A\u9593[l, r) \u306B\u4F5C\
    \u7528\u3055\u305B\u308B.\n    * @param[in] x \u4F5C\u7528\u7D20\u30E2\u30CE\u30A4\
    \u30C9\u306E\u5143.\n    * @details \u4F7F\u3044\u65B9\n    *   e.g. Range Update\n\
    \    *   int l, r, x; // \u533A\u9593[l, r) \u3092x \u306B\u66F4\u65B0\u3057\u305F\
    \u3044.\n    *   segt.update(l, r, x);\n    */\n    void update(int a, int b,\
    \ const OM& x) {\n        update(a, b, x, 1, 0, sz);\n    }\n\n    /**\n    *\
    \ @brief \u6307\u5B9A\u3057\u305F\u533A\u9593\u306B\u53D6\u5F97\u30AF\u30A8\u30EA\
    \u3092\u5B9F\u884C\u3059\u308B. O(log n)\n    * @param[in] l, r \u533A\u9593[l,\
    \ r) \u3092\u53D6\u5F97\u3059\u308B.\n    * @return \u53D6\u5F97\u3057\u305F\u5024\
    .\n    * @details \u4F7F\u3044\u65B9\n    *   e.g. Range Minimum\n    *   int\
    \ l, r; // \u533A\u9593[l, r) \u306Emin\u3092\u53D6\u5F97\u3057\u305F\u3044.\n\
    \    *   cout << segt.query(l, r) << endl;\n    */\n    M query(int a, int b)\
    \ {\n        return query(a, b, 1, 0, sz);\n    }\n\n    /**\n    * @brief \u6307\
    \u5B9A\u3057\u305Findex\u306E\u8981\u7D20\u3092\u53D6\u5F97. O(1)\n    * @param[in]\
    \ i \u53D6\u5F97\u3057\u305F\u3044\u8981\u7D20\u306Eindex\n    * @return \u53D6\
    \u5F97\u3057\u305F\u5024.\n    */\n    M operator[](int i) {\n        return query(i,\
    \ i + 1);\n    }\n\n    /**\n    * @brief vector \u307F\u305F\u3044\u306B\u51FA\
    \u529B.\n    */\n    friend ostream& operator<<(ostream& os, LazySegmentTree&\
    \ s) {\n        os << \"[\";\n        for (int i = 0; i < s.n; ++i) {\n      \
    \      if (i) os << \" \";\n            os << s[i];\n        }\n        return\
    \ os << \"]\";\n    }\n\nprivate:\n\n    int n, sz;\n    vector<M> data;\n   \
    \ vector<OM> lazy;\n    const function<M(M,M)> f;\n    const function<M(M,OM,int)>\
    \ g;\n    const function<OM(OM,OM)> h;\n    const M e;\n    const OM oe;\n\n \
    \   void propagate(int k, int len) {\n        if (lazy[k] == oe) return;\n   \
    \     if (k < sz) {\n            lazy[2 * k    ] = h(lazy[2 * k    ], lazy[k]);\n\
    \            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);\n        }\n     \
    \   data[k] = g(data[k], lazy[k], len);\n        lazy[k] = oe;\n    }\n\n    void\
    \ update(int a, int b, const OM& x, int k, int l, int r) {\n        propagate(k,\
    \ r - l);\n        if (r <= a or b <= l) return;\n        else if (a <= l and\
    \ r <= b) {\n            lazy[k] = h(lazy[k], x);\n            propagate(k, r\
    \ - l);\n        } else {\n            update(a, b, x, 2 * k,     l, (l + r) >>\
    \ 1);\n            update(a, b, x, 2 * k + 1, (l + r) >> 1, r);\n            data[k]\
    \ = f(data[2 * k], data[2 * k + 1]);\n        }\n    }\n\n    M query(int a, int\
    \ b, int k, int l, int r) {\n        propagate(k, r - l);\n        if (r <= a\
    \ or b <= l) return e;\n        else if (a <= l and r <= b) return data[k];\n\
    \        else return f(\n                query(a, b, 2 * k,     l, (l + r) >>\
    \ 1),\n                query(a, b, 2 * k + 1, (l + r) >> 1, r));\n    }\n};\n\n\
    /* Usage\n *\n * Range Add Range Sum\n * LazySegmentTree<int> segt(\n *      \
    \      n,\n *            [](int a,int b){ return a+b; },\n *            [](int\
    \ a,int b,int w){ return a + b*w; },\n *            [](int a,int b){ return a+b;\
    \ },\n *            0, 0);\n *\n * Range Update Range Sum\n * LazySegmentTree<int>\
    \ segt(\n *            n,\n *            [](int a,int b){ return a+b; },\n * \
    \           [](int a,int b,int w){ return b; },\n *            [](int a,int b){\
    \ return b; },\n *            0, INF);\n *\n * Range Add Range min\n * LazySegmentTree<int>\
    \ segt(\n *            n,\n *            [](int a,int b){ return min(a, b); },\n\
    \ *            [](int a,int b,int w){ return a + b*w; },\n *            [](int\
    \ a,int b){ return a+b; },\n *            INF, 0);\n *\n * Range Update Range\
    \ min\n * LazySegmentTree<int> segt(\n *            n,\n *            [](int a,int\
    \ b){ return min(a, b); },\n *            [](int a,int b,int w){ return b; },\n\
    \ *            [](int a,int b){ return b; },\n *            INF, INF);\n *\n *\
    \ Range Add Range max\n * LazySegmentTree<int> segt(\n *            n,\n *   \
    \         [](int a,int b){ return max(a, b); },\n *            [](int a,int b,int\
    \ w){ return a + b*w; },\n *            [](int a,int b){ return a+b; },\n *  \
    \          -INF, 0);\n *\n * Range Update Range max\n * LazySegmentTree<int> segt(\n\
    \ *            n,\n *            [](int a,int b){ return max(a, b); },\n *   \
    \         [](int a,int b,int w){ return b; },\n *            [](int a,int b){\
    \ return b; },\n *            -INF, INF);\n */\n#line 2 \"lib/number/mint.cpp\"\
    \n\ntemplate<ll m>\nstruct mint {\n    ll x;\n    mint(ll x = 0) : x(((x % m)\
    \ + m) % m) {}\n    mint operator-() { return x ? m-x : 0; }\n    mint &operator+=(mint\
    \ r) {\n        if ((x += r.x) >= m) x -= m;\n        return *this;\n    }\n \
    \   mint &operator-=(mint r) { return *this += -r; }\n    mint &operator*=(mint\
    \ r) {\n        (x *= r.x) %= m;\n        return *this;\n    }\n    mint &operator/=(mint\
    \ r) { return *this *= r.pow(m-2); }\n\n    friend mint operator+(mint l, mint\
    \ r) { return l += r; }\n    friend mint operator-(mint l, mint r) { return l\
    \ -= r; }\n    friend mint operator*(mint l, mint r) { return l *= r; }\n    friend\
    \ mint operator/(mint l, mint r) { return l /= r; }\n    mint pow(ll n) {\n  \
    \      mint ret = 1, tmp = *this;\n        while (n) {\n            if (n & 1)\
    \ ret *= tmp;\n            tmp *= tmp, n >>= 1;\n        }\n        return ret;\n\
    \    }\n    friend ostream &operator<<(ostream &os, mint a) {\n        return\
    \ os << a.x;\n    }\n    friend istream &operator>>(istream &is, mint& a) {\n\
    \        ll x; is >> x; a = x; return is;\n    }\n};\n\n#line 5 \"test/yosupo-judge/range_affine_range_sum.test.cpp\"\
    \n\n\nusing Mint = mint<998244353>;\n\nstruct S {\n    Mint val;\n};\n\nstruct\
    \ T {\n    Mint b;\n    Mint c;\n\n    bool operator==(const T &rhs) const {\n\
    \        return b.x == rhs.b.x && c.x == rhs.c.x;\n    }\n};\n\nint main() {\n\
    \    int N, Q;\n    cin >> N >> Q;\n\n    LazySegmentTree<S, T> segt(\n      \
    \      N,\n            [](S a, S b) { return S{a.val + b.val}; },\n          \
    \  [](S l, T r, int w) { return S{l.val * r.b + r.c * w}; },\n            [](T\
    \ l, T r) { return T{l.b * r.b, r.b * l.c + r.c}; },\n            S{0}, T{1, 0});\n\
    \n    vector <S> a(N);\n    REP(i, N) {\n        int tmp;\n        cin >> tmp;\n\
    \        a[i] = {tmp};\n    }\n\n    segt.build(a);\n\n    while (Q--) {\n   \
    \     int t;\n        cin >> t;\n        if (t == 0) {\n            ll l, r, b,\
    \ c;\n            cin >> l >> r >> b >> c;\n            segt.update(l, r, {b,\
    \ c});\n        } else {\n            ll l, r;\n            cin >> l >> r;\n \
    \           Mint val = segt.query(l, r).val;\n            cout << val << endl;\n\
    \        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../lib/structure/lazy_segment_tree.cpp\"\n#include \"../../lib/number/mint.cpp\"\
    \n\n\nusing Mint = mint<998244353>;\n\nstruct S {\n    Mint val;\n};\n\nstruct\
    \ T {\n    Mint b;\n    Mint c;\n\n    bool operator==(const T &rhs) const {\n\
    \        return b.x == rhs.b.x && c.x == rhs.c.x;\n    }\n};\n\nint main() {\n\
    \    int N, Q;\n    cin >> N >> Q;\n\n    LazySegmentTree<S, T> segt(\n      \
    \      N,\n            [](S a, S b) { return S{a.val + b.val}; },\n          \
    \  [](S l, T r, int w) { return S{l.val * r.b + r.c * w}; },\n            [](T\
    \ l, T r) { return T{l.b * r.b, r.b * l.c + r.c}; },\n            S{0}, T{1, 0});\n\
    \n    vector <S> a(N);\n    REP(i, N) {\n        int tmp;\n        cin >> tmp;\n\
    \        a[i] = {tmp};\n    }\n\n    segt.build(a);\n\n    while (Q--) {\n   \
    \     int t;\n        cin >> t;\n        if (t == 0) {\n            ll l, r, b,\
    \ c;\n            cin >> l >> r >> b >> c;\n            segt.update(l, r, {b,\
    \ c});\n        } else {\n            ll l, r;\n            cin >> l >> r;\n \
    \           Mint val = segt.query(l, r).val;\n            cout << val << endl;\n\
    \        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - lib/structure/lazy_segment_tree.cpp
  - lib/template.cpp
  - lib/number/mint.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/yosupo-judge/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-10-13 20:06:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/range_affine_range_sum.test.cpp
- /verify/test/yosupo-judge/range_affine_range_sum.test.cpp.html
title: test/yosupo-judge/range_affine_range_sum.test.cpp
---
