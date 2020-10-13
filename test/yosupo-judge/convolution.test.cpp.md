---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/mint.cpp
    title: lib/number/mint.cpp
  - icon: ':heavy_check_mark:'
    path: lib/number/ntt.cpp
    title: NTT
  - icon: ':heavy_check_mark:'
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/mint.cpp\"\n\ntemplate<ll m>\n\
    struct mint {\n    ll x;\n    mint(ll x = 0) : x(((x % m) + m) % m) {}\n    mint\
    \ operator-() { return x ? m-x : 0; }\n    mint &operator+=(mint r) {\n      \
    \  if ((x += r.x) >= m) x -= m;\n        return *this;\n    }\n    mint &operator-=(mint\
    \ r) { return *this += -r; }\n    mint &operator*=(mint r) {\n        (x *= r.x)\
    \ %= m;\n        return *this;\n    }\n    mint &operator/=(mint r) { return *this\
    \ *= r.pow(m-2); }\n\n    friend mint operator+(mint l, mint r) { return l +=\
    \ r; }\n    friend mint operator-(mint l, mint r) { return l -= r; }\n    friend\
    \ mint operator*(mint l, mint r) { return l *= r; }\n    friend mint operator/(mint\
    \ l, mint r) { return l /= r; }\n    mint pow(ll n) {\n        mint ret = 1, tmp\
    \ = *this;\n        while (n) {\n            if (n & 1) ret *= tmp;\n        \
    \    tmp *= tmp, n >>= 1;\n        }\n        return ret;\n    }\n    friend ostream\
    \ &operator<<(ostream &os, mint a) {\n        return os << a.x;\n    }\n    friend\
    \ istream &operator>>(istream &is, mint& a) {\n        ll x; is >> x; a = x; return\
    \ is;\n    }\n};\n\n#line 2 \"lib/number/ntt.cpp\"\n\n/**\n * @brief NTT\n * @author\
    \ habara-k\n * @usage\n *   vector<NTT<>::Int> a, b;\n *   NTT<> ntt;\n *   auto\
    \ c = ntt.multiply(a, b);\n */\n\ntemplate<ll mod=998244353, ll primitive=3>\n\
    struct NTT {\n    using Int = mint<mod>;\n    vector<Int> multiply(vector<Int>\
    \ a, vector<Int> b) {\n        int need = SZ(a) + SZ(b) - 1;\n        ensure(need);\n\
    \        assert((n & (n-1)) == 0);\n        a.resize(n);\n        b.resize(n);\n\
    \        ntt(a);\n        ntt(b);\n\n        vector<Int> c(n);\n        for (int\
    \ i = 0; i < n; ++i) c[i] = a[i] * b[i] / n;\n        reverse(c.begin() + 1, c.end());\n\
    \        ntt(c); c.resize(need);\n        return c;\n    }\n\nprivate:\n    int\
    \ n;\n    Int root;\n\n    void ensure(int need) {\n        n = 1;\n        while\
    \ (n < need) n <<= 1;\n        root = Int{primitive}.pow((mod-1) / n);\n    }\n\
    \n    void ntt(vector<Int>& a) {\n        int p = 0;\n        for (int i = 1;\
    \ i < n - 1; ++i) {\n            for (int k = n >> 1; k > (p ^= k); k >>= 1);\n\
    \            if (i < p) swap(a[i], a[p]);\n        }\n        for (int k = 1;\
    \ k < n; k <<= 1) {\n            Int base = root.pow(n / (2*k));\n           \
    \ Int z = 1;\n            for (int j = 0; j < k; ++j) {\n                for (int\
    \ i = j; i < n; i += 2*k) {\n                    Int u = a[i], v = a[i+k] * z;\n\
    \                    a[i] = u + v;\n                    a[i+k] = u - v;\n    \
    \            }\n                z *= base;\n            }\n        }\n    }\n\
    };\n\n#line 5 \"test/yosupo-judge/convolution.test.cpp\"\n\nint main() {\n   \
    \ int n, m; cin >> n >> m;\n    vector<NTT<>::Int> a(n), b(m);\n    REP(i, n)\
    \ cin >> a[i];\n    REP(i, m) cin >> b[i];\n\n    NTT<> ntt;\n    auto c = ntt.multiply(a,b);\n\
    \    REP(i, SZ(c)) {\n        if (i) cout << ' ';\n        cout << c[i];\n   \
    \ }\n    cout << endl;\n\n    return 0;\n}\n"
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
  timestamp: '2020-10-13 20:06:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/convolution.test.cpp
- /verify/test/yosupo-judge/convolution.test.cpp.html
title: test/yosupo-judge/convolution.test.cpp
---
