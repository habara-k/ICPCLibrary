---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/mint.cpp
    title: lib/number/mint.cpp
  - icon: ':heavy_check_mark:'
    path: lib/number/ntt.cpp
    title: NTT
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/yosupo-judge/convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#line 1 \"lib/template.cpp\"\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/mint.cpp\"\n\ntemplate<int m>\n\
    struct mint {\n    int x;\n    mint(ll x = 0) : x(((x % m) + m) % m) {}\n    mint\
    \ operator-() const { return x ? m-x : 0; }\n    mint &operator+=(mint r) {\n\
    \        if ((x += r.x) >= m) x -= m;\n        return *this;\n    }\n    mint\
    \ &operator-=(mint r) {\n        if ((x -= r.x) < 0) x += m;\n        return *this;\n\
    \    }\n    mint &operator*=(mint r) {\n        x = ((ll)x * r.x) % m;\n     \
    \   return *this;\n    }\n    mint inv() const { return pow(m-2); }\n    mint\
    \ &operator/=(mint r) { return *this *= r.inv(); }\n\n    friend mint operator+(mint\
    \ l, mint r) { return l += r; }\n    friend mint operator-(mint l, mint r) { return\
    \ l -= r; }\n    friend mint operator*(mint l, mint r) { return l *= r; }\n  \
    \  friend mint operator/(mint l, mint r) { return l /= r; }\n    mint pow(ll n)\
    \ const {\n        mint ret = 1, tmp = *this;\n        while (n) {\n         \
    \   if (n & 1) ret *= tmp;\n            tmp *= tmp, n >>= 1;\n        }\n    \
    \    return ret;\n    }\n    friend bool operator==(mint l, mint r) { return l.x\
    \ == r.x; }\n    friend bool operator!=(mint l, mint r) { return l.x != r.x; }\n\
    \    friend ostream &operator<<(ostream &os, mint a) {\n        return os << a.x;\n\
    \    }\n    friend istream &operator>>(istream &is, mint& a) {\n        ll x;\
    \ is >> x; a = x; return is;\n    }\n};\n\n#line 2 \"lib/number/ntt.cpp\"\n\n\
    /*\n * @brief NTT\n * @ref https://ei1333.github.io/library/math/fft/number-theoretic-transform-friendly-mod-int.cpp\n\
    \ * @author habara-k\n * @usage\n *   vector<NTT<>::Int> a, b;\n *   auto c =\
    \ NTT<>::multiply(a, b);\n *\n * root\u306E\u63A2\u7D22\n * int root = 2;\n *\
    \ while (Int{root}.pow((mod-1)/2) == 1) ++root;\n */\ntemplate<int mod = 998244353,\
    \ int root = 3>\nstruct NTT {\n    using Int = mint<mod>;\n    constexpr static\
    \ int sz = __builtin_ctz(mod-1);\n\n    static void ntt(vector<Int> &a) {\n  \
    \      const int n = (int) a.size();\n        assert((n & (n - 1)) == 0);\n  \
    \      assert(__builtin_ctz(n) <= sz);\n        Int dw[sz];\n        REP(i, sz)\
    \ {\n            dw[i] = -Int{root}.pow((mod-1) >> (i+2));\n        }\n      \
    \  for (int m = n; m >>= 1;) {\n            Int w = 1;\n            for (int s\
    \ = 0, k = 0; s < n; s += 2 * m) {\n                for (int i = s, j = s + m;\
    \ i < s + m; ++i, ++j) {\n                    auto x = a[i], y = a[j] * w;\n \
    \                   a[i] = x + y, a[j] = x - y;\n                }\n         \
    \       w *= dw[__builtin_ctz(++k)];\n            }\n        }\n    }\n\n    static\
    \ void intt(vector<Int> &a) {\n        const int n = (int) a.size();\n       \
    \ assert((n & (n - 1)) == 0);\n        assert(__builtin_ctz(n) <= sz);\n     \
    \   Int idw[sz];\n        REP(i, sz) {\n            idw[i] = (-Int{root}.pow((mod-1)\
    \ >> (i+2))).inv();\n        }\n        for (int m = 1; m < n; m *= 2) {\n   \
    \         Int w = 1;\n            for (int s = 0, k = 0; s < n; s += 2 * m) {\n\
    \                for (int i = s, j = s + m; i < s + m; ++i, ++j) {\n         \
    \           auto x = a[i], y = a[j];\n                    a[i] = x + y, a[j] =\
    \ (x - y) * w;\n                }\n                w *= idw[__builtin_ctz(++k)];\n\
    \            }\n        }\n        Int inv_n = Int{n}.inv();\n        REP(i, n)\
    \ a[i] *= inv_n;\n    }\n\n    static vector<Int> multiply(vector<Int> a, vector<Int>\
    \ b) {\n        int need = SZ(a) + SZ(b) - 1;\n        int n = 1;\n        while\
    \ (n < need) n <<= 1;\n        a.resize(n);\n        b.resize(n);\n        ntt(a);\n\
    \        ntt(b);\n        REP(i, n) a[i] *= b[i];\n        intt(a);\n        a.resize(need);\n\
    \        return a;\n    }\n};\n\n#line 5 \"test/yosupo-judge/convolution.test.cpp\"\
    \n\nint main() {\n    int n, m; cin >> n >> m;\n    vector<NTT<>::Int> a(n), b(m);\n\
    \    REP(i, n) cin >> a[i];\n    REP(i, m) cin >> b[i];\n\n    NTT<> ntt;\n  \
    \  auto c = ntt.multiply(a,b);\n    REP(i, SZ(c)) {\n        if (i) cout << '\
    \ ';\n        cout << c[i];\n    }\n    cout << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"../../lib/number/mint.cpp\"\n#include \"../../lib/number/ntt.cpp\"\n\nint\
    \ main() {\n    int n, m; cin >> n >> m;\n    vector<NTT<>::Int> a(n), b(m);\n\
    \    REP(i, n) cin >> a[i];\n    REP(i, m) cin >> b[i];\n\n    NTT<> ntt;\n  \
    \  auto c = ntt.multiply(a,b);\n    REP(i, SZ(c)) {\n        if (i) cout << '\
    \ ';\n        cout << c[i];\n    }\n    cout << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - lib/number/mint.cpp
  - lib/template.cpp
  - lib/number/ntt.cpp
  isVerificationFile: true
  path: test/yosupo-judge/convolution.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 19:29:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/convolution.test.cpp
- /verify/test/yosupo-judge/convolution.test.cpp.html
title: test/yosupo-judge/convolution.test.cpp
---
