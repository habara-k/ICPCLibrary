---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: FFT
    links:
    - https://atcoder.jp/contests/atc001/submissions/13627626
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
    \n\n/**\n* @brief FFT\n* @author habara-k\n* @date 2020/05/27\n* @verify https://atcoder.jp/contests/atc001/submissions/13627626\n\
    * @details \u4F7F\u3044\u65B9\n*   e.g. \u591A\u9805\u5F0F\u306E\u7A4D\n*\n* \
    \  vector<complex<double>> a(2*n+1), b(2*n+1);\n*\n*   auto A = FFT<double>(a).solve();\n\
    *   auto B = FFT<double>(b).solve();\n*\n*   vector<complex<double>> C(A.size());\n\
    *   REP(i, C.size()) C[i] = A[i] * B[i];\n*\n*   auto c = FFT<double>(C).solve(true);\n\
    */\n\n\ntemplate<typename T>\nstruct FFT {\n\n    /**\n    * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF. O(n)\n    * @param[in] a_: \u591A\u9805\u5F0F\u306E\
    \u4FC2\u6570\n    */\n    FFT(const vector<complex<T>>& a_) : a(a_), n(1) {\n\
    \        while (n < a.size()) n <<= 1;\n        a.resize(n);\n    }\n\n    /**\n\
    \    * @brief FFT\u306E\u5B9F\u884C. O(nlog n)\n    * @param[in] inverse: \u9006\
    \u5909\u63DB\u306E\u30D5\u30E9\u30B0.\n    * @return FFT or inverse-FFT\n    */\n\
    \    vector<complex<T>> solve(bool inverse = false) {\n        return fft(0, 0,\
    \ inverse);\n    }\n\nprivate:\n    vector<complex<T>> a;\n    int n;\n    const\
    \ T PI = acos(-1);\n\n    vector<complex<T>> fft(int d, int bit, bool inverse)\
    \ {\n        int sz = n >> d;\n        if (sz == 1) return {a[bit] / (inverse\
    \ ? static_cast<T>(n) : 1.0)};\n\n        auto f0 = fft(d+1, bit, inverse);\n\
    \        auto f1 = fft(d+1, bit | 1<<d, inverse);\n        vector<complex<T>>\
    \ f(sz);\n        for (int i = 0; i < sz; ++i) {\n            f[i] = f0[i % (sz\
    \ / 2)] +\n                   std::polar(1.0, 2*PI / sz * i * (inverse ? -1 :\
    \ 1)) *\n                   f1[i % (sz / 2)];\n        }\n        return f;\n\
    \    }\n};\n"
  code: "#include \"../template.cpp\"\n\n/**\n* @brief FFT\n* @author habara-k\n*\
    \ @date 2020/05/27\n* @verify https://atcoder.jp/contests/atc001/submissions/13627626\n\
    * @details \u4F7F\u3044\u65B9\n*   e.g. \u591A\u9805\u5F0F\u306E\u7A4D\n*\n* \
    \  vector<complex<double>> a(2*n+1), b(2*n+1);\n*\n*   auto A = FFT<double>(a).solve();\n\
    *   auto B = FFT<double>(b).solve();\n*\n*   vector<complex<double>> C(A.size());\n\
    *   REP(i, C.size()) C[i] = A[i] * B[i];\n*\n*   auto c = FFT<double>(C).solve(true);\n\
    */\n\n\ntemplate<typename T>\nstruct FFT {\n\n    /**\n    * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF. O(n)\n    * @param[in] a_: \u591A\u9805\u5F0F\u306E\
    \u4FC2\u6570\n    */\n    FFT(const vector<complex<T>>& a_) : a(a_), n(1) {\n\
    \        while (n < a.size()) n <<= 1;\n        a.resize(n);\n    }\n\n    /**\n\
    \    * @brief FFT\u306E\u5B9F\u884C. O(nlog n)\n    * @param[in] inverse: \u9006\
    \u5909\u63DB\u306E\u30D5\u30E9\u30B0.\n    * @return FFT or inverse-FFT\n    */\n\
    \    vector<complex<T>> solve(bool inverse = false) {\n        return fft(0, 0,\
    \ inverse);\n    }\n\nprivate:\n    vector<complex<T>> a;\n    int n;\n    const\
    \ T PI = acos(-1);\n\n    vector<complex<T>> fft(int d, int bit, bool inverse)\
    \ {\n        int sz = n >> d;\n        if (sz == 1) return {a[bit] / (inverse\
    \ ? static_cast<T>(n) : 1.0)};\n\n        auto f0 = fft(d+1, bit, inverse);\n\
    \        auto f1 = fft(d+1, bit | 1<<d, inverse);\n        vector<complex<T>>\
    \ f(sz);\n        for (int i = 0; i < sz; ++i) {\n            f[i] = f0[i % (sz\
    \ / 2)] +\n                   std::polar(1.0, 2*PI / sz * i * (inverse ? -1 :\
    \ 1)) *\n                   f1[i % (sz / 2)];\n        }\n        return f;\n\
    \    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/fft.cpp
  requiredBy: []
  timestamp: '2020-05-27 02:06:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/number/fft.cpp
layout: document
redirect_from:
- /library/lib/number/fft.cpp
- /library/lib/number/fft.cpp.html
title: FFT
---
