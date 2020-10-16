---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: FFT
    links: []
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/fft.cpp\"\
    \n\n/**\n * @brief FFT\n * @author habara-k\n * @usage\n *   FFT<int> fft;\n *\
    \   vector<int> a, b;\n *   auto c = fft.multiply(a, b);\n */\n\ntemplate<typename\
    \ T>\nstruct FFT {\n    using C = complex<double>;\n    vector<T> multiply(vector<T>\
    \ a, vector<T> b) {\n        int need = SZ(a) + SZ(b) - 1;\n        ensure(need);\n\
    \        assert((n & (n-1)) == 0);\n\n        vector<C> fa, fb;\n        for (T\
    \ e : a) fa.emplace_back(e, 0);\n        for (T e : b) fb.emplace_back(e, 0);\n\
    \        fa.resize(n);\n        fb.resize(n);\n        fft(fa);\n        fft(fb);\n\
    \n        vector<C> fc(n);\n        for (int i = 0; i < n; ++i) fc[i] = fa[i]\
    \ * fb[i] / (double)n;\n        reverse(fc.begin() + 1, fc.end());\n        fft(fc);\n\
    \        vector<T> c;\n        for (C e : fc) {\n            assert(abs(e.imag())\
    \ < eps);\n            c.emplace_back(round(e.real()));\n        }\n        c.resize(need);\n\
    \        return c;\n    }\n\nprivate:\n    int n;\n    const double PI = acos(-1);\n\
    \n    void ensure(int need) {\n        n = 1;\n        while (n < need) n <<=\
    \ 1;\n    }\n\n    void fft(vector<C>& a) {\n        int p = 0;\n        for (int\
    \ i = 1; i < n - 1; ++i) {\n            for (int k = n >> 1; k > (p ^= k); k >>=\
    \ 1);\n            if (i < p) swap(a[i], a[p]);\n        }\n        for (int k\
    \ = 1; k < n; k <<= 1) {\n            for (int j = 0; j < k; ++j) {\n        \
    \        C z = polar(1.0, PI / k * j);\n                for (int i = j; i < n;\
    \ i += 2*k) {\n                    C u = a[i], v = a[i+k] * z;\n             \
    \       a[i] = u + v;\n                    a[i+k] = u - v;\n                }\n\
    \            }\n        }\n    }\n};\n\n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief FFT\n * @author habara-k\n\
    \ * @usage\n *   FFT<int> fft;\n *   vector<int> a, b;\n *   auto c = fft.multiply(a,\
    \ b);\n */\n\ntemplate<typename T>\nstruct FFT {\n    using C = complex<double>;\n\
    \    vector<T> multiply(vector<T> a, vector<T> b) {\n        int need = SZ(a)\
    \ + SZ(b) - 1;\n        ensure(need);\n        assert((n & (n-1)) == 0);\n\n \
    \       vector<C> fa, fb;\n        for (T e : a) fa.emplace_back(e, 0);\n    \
    \    for (T e : b) fb.emplace_back(e, 0);\n        fa.resize(n);\n        fb.resize(n);\n\
    \        fft(fa);\n        fft(fb);\n\n        vector<C> fc(n);\n        for (int\
    \ i = 0; i < n; ++i) fc[i] = fa[i] * fb[i] / (double)n;\n        reverse(fc.begin()\
    \ + 1, fc.end());\n        fft(fc);\n        vector<T> c;\n        for (C e :\
    \ fc) {\n            assert(abs(e.imag()) < eps);\n            c.emplace_back(round(e.real()));\n\
    \        }\n        c.resize(need);\n        return c;\n    }\n\nprivate:\n  \
    \  int n;\n    const double PI = acos(-1);\n\n    void ensure(int need) {\n  \
    \      n = 1;\n        while (n < need) n <<= 1;\n    }\n\n    void fft(vector<C>&\
    \ a) {\n        int p = 0;\n        for (int i = 1; i < n - 1; ++i) {\n      \
    \      for (int k = n >> 1; k > (p ^= k); k >>= 1);\n            if (i < p) swap(a[i],\
    \ a[p]);\n        }\n        for (int k = 1; k < n; k <<= 1) {\n            for\
    \ (int j = 0; j < k; ++j) {\n                C z = polar(1.0, PI / k * j);\n \
    \               for (int i = j; i < n; i += 2*k) {\n                    C u =\
    \ a[i], v = a[i+k] * z;\n                    a[i] = u + v;\n                 \
    \   a[i+k] = u - v;\n                }\n            }\n        }\n    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/fft.cpp
  requiredBy: []
  timestamp: '2020-10-13 02:22:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/number/fft.cpp
layout: document
redirect_from:
- /library/lib/number/fft.cpp
- /library/lib/number/fft.cpp.html
title: FFT
---