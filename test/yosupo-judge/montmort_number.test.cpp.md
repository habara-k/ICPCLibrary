---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/comb.cpp
    title: lib/number/comb.cpp
  - icon: ':heavy_check_mark:'
    path: lib/number/rmint.cpp
    title: lib/number/rmint.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/montmort_number_mod
    links:
    - https://judge.yosupo.jp/problem/montmort_number_mod
  bundledCode: "#line 1 \"test/yosupo-judge/montmort_number.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/montmort_number_mod\"\n\n#line 1 \"lib/template.cpp\"\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/rmint.cpp\"\n\ntemplate<typename\
    \ T=int>\nstruct rmint {\n    static T &m() {\n        static T m = 0;\n     \
    \   return m;\n    }\n    static void set_mod(T md) { m() = md; }\n    T x;\n\
    \    rmint(T x = 0) : x(((x % m()) + m()) % m()) {}\n    rmint operator-() { return\
    \ x ? m()-x : 0; }\n    rmint &operator+=(rmint r) {\n        if ((x += r.x) >=\
    \ m()) x -= m();\n        return *this;\n    }\n    rmint &operator-=(rmint r)\
    \ {\n        if ((x -= r.x) < 0) x += m();\n        return *this;\n    }\n   \
    \ rmint &operator*=(rmint r) {\n        x = ((ll)x * r.x) % m();\n        return\
    \ *this;\n    }\n    rmint inv() {\n        int a = x, b = m, u = 1, v = 0, t;\n\
    \        while (b > 0) {\n            t = a / b;\n            swap(a -= t * b,\
    \ b);\n            swap(u -= t * v, v);\n        }\n        return u;\n    }\n\
    \    rmint &operator/=(rmint r) { return *this *= r.inv(); }\n\n    friend rmint\
    \ operator+(rmint l, rmint r) { return l += r; }\n    friend rmint operator-(rmint\
    \ l, rmint r) { return l -= r; }\n    friend rmint operator*(rmint l, rmint r)\
    \ { return l *= r; }\n    friend rmint operator/(rmint l, rmint r) { return l\
    \ /= r; }\n    rmint pow(T n) {\n        rmint ret = 1, tmp = *this;\n       \
    \ while (n) {\n            if (n & 1) ret *= tmp;\n            tmp *= tmp, n >>=\
    \ 1;\n        }\n        return ret;\n    }\n    friend bool operator==(rmint\
    \ l, rmint r) { return l.x == r.x; }\n    friend bool operator!=(rmint l, rmint\
    \ r) { return l.x != r.x; }\n    friend ostream &operator<<(ostream &os, rmint\
    \ a) {\n        return os << a.x;\n    }\n    friend istream &operator>>(istream\
    \ &is, rmint& a) {\n        ll x; is >> x; a = x; return is;\n    }\n};\n\n#line\
    \ 2 \"lib/number/comb.cpp\"\n\n#define SNIPPET_ONLY\n\ntemplate<typename T>\n\
    struct Combination {\n    int _n = 1;\n    vector<T> _fact{1}, _rfact{1};\n\n\
    \    void extend(int n) {\n        if (n <= _n) return;\n        _fact.resize(n);\n\
    \        _rfact.resize(n);\n        for (int i = _n; i < n; ++i) _fact[i] = _fact[i\
    \ - 1] * i;\n        _rfact[n - 1] = 1 / _fact[n - 1];\n        for (int i = n\
    \ - 1; i > _n; --i) _rfact[i - 1] = _rfact[i] * i;\n        _n = n;\n    }\n\n\
    \    T fact(int k) {\n        extend(k + 1);\n        return _fact.at(k);\n  \
    \  }\n\n    T rfact(int k) {\n        extend(k + 1);\n        return _rfact.at(k);\n\
    \    }\n\n    T P(int n, int r) {\n        if (r < 0 or n < r) return 0;\n   \
    \     return fact(n) * rfact(n - r);\n    }\n\n    T C(int n, int r) {\n     \
    \   if (r < 0 or n < r) return 0;\n        return fact(n) * rfact(r) * rfact(n\
    \ - r);\n    }\n\n    T H(int n, int r) {\n        return (n == 0 and r == 0)\
    \ ? 1 : C(n + r - 1, r);\n    }\n\n    // O(k logn)\n    // \u30B9\u30BF\u30FC\
    \u30EA\u30F3\u30B0\u6570\n    // Stirling(n, k) := n \u500B\u306E\u533A\u5225\u3067\
    \u304D\u308B\u30DC\u30FC\u30EB\u3092 k \u500B\u306E\u533A\u5225\u3067\u304D\u306A\
    \u3044\u7BB1\u306B\u3044\u308C\u308B\u5834\u5408\u306E\u6570\n    //         \
    \          \u305D\u308C\u305E\u308C\u306E\u7BB1\u306B\u306F1\u500B\u4EE5\u4E0A\
    \u30DC\u30FC\u30EB\u3092\u3044\u308C\u308B\n    // ---\n    // S(n, k) = S(n-1,\
    \ k-1) + k * S(n-1, k)\n    // * \u7279\u5B9A\u306E1\u500B\u3060\u3051\u30671\u500B\
    \u306E\u7BB1\u306B\u3044\u308C\u308B\u5834\u5408\u306F S(n-1, k-1)\n    // * \u305D\
    \u3046\u3067\u306A\u3044\u5834\u5408\u306F S(n-1, k) \u901A\u308A\u306B\u5BFE\u3057\
    \u3066\u7279\u5B9A\u306E1\u500B\u3092\u3044\u308C\u308B\u306E\u304C k \u901A\u308A\
    \n    // ---\n    // \u5404\u30B0\u30EB\u30FC\u30D7\u306B\u3064\u304Dr\u500B\u4EE5\
    \u4E0A, \u306E\u5236\u9650\u304C\u3042\u308B\u5834\u5408\n    // S(n, k) = C(n-1,\
    \ r-1) * S(n-r, k-1) + k * S(n-1, k)\n    // ---\n    // \u7389\u304Cn\u500B\u3042\
    \u308B\u3046\u3061\u306E\u3044\u304F\u3064\u304B\u3092\u9078\u3093\u3067k\u30B0\
    \u30EB\u30FC\u30D7\u306B\u5206\u3051\u308B\u5834\u5408\n    // S(n, k) = S(n-1,\
    \ k-1) + (k+1) * S(n-1, k)\n    T Stirling(ll n, int k) {\n        T ret = 0;\n\
    \        for (int l = 0; l <= k; ++l) {\n            ret += C(k, l) * T{k-l}.pow(n)\
    \ * (l & 1 ? -1 : 1);\n        }\n        return ret / fact(k);\n    }\n\n   \
    \ // O(k^2 logn)\n    // \u30D9\u30EB\u6570\n    // Bell(n, k) := n \u500B\u306E\
    \u533A\u5225\u3067\u304D\u308B\u30DC\u30FC\u30EB\u3092 k \u500B\u306E\u533A\u5225\
    \u3067\u304D\u306A\u3044\u7BB1\u306B\u3044\u308C\u308B\u5834\u5408\u306E\u6570\
    \n    // ---\n    // B(n+1) := Bell(n+1, n+1) = n \u500B\u306E\u533A\u5225\u3067\
    \u304D\u308B\u30DC\u30FC\u30EB\u306E\u5206\u5272\u306E\u7DCF\u6570\n    // B(n+1)\
    \ = \\sum_{i=0}^n C(n,i) * B(i)\n    // * \u7279\u5B9A\u306E1\u500B\u304C\u5C5E\
    \u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306B, \u4ED6\u306E\u30DC\u30FC\u30EB\u304C\
    n-i \u500B\u5165\u3063\u3066\u3044\u308B\u3068\u304D,\n    // * \u6B8B\u308Ai\
    \ \u500B\u306E\u4E26\u3079\u65B9\u306FB(i)\n    T Bell(ll n, int k) {\n      \
    \  T ret = 0;\n        for (int l = 0; l <= k; ++l) {\n            ret += Stirling(n,\
    \ l);\n        }\n        return ret;\n    }\n\n};\n\n// O(nk)\n// Partition[n][k]\
    \ := n \u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\u30DC\u30FC\u30EB\u3092\
    \ k \u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\u7BB1\u306B\u3044\u308C\u308B\
    \u5834\u5408\u306E\u6570\n// ---\n// \u5404\u30B0\u30EB\u30FC\u30D7\u306B\u3064\
    \u304D1\u500B\u4EE5\u4E0A, \u306E\u5236\u9650\u304C\u3042\u308B\u5834\u5408, Part[n][k]\
    \ - Part[n][k-1]\ntemplate<typename T>\nvector<vector<T>> Partition(int n, int\
    \ k) {\n    vector<vector<T>> ret(n+1, vector<T>(k+1));\n    ret[0][0] = 1;\n\
    \    for (int i = 0; i <= n; ++i) {\n        for (int j = 1; j <= k; ++j) {\n\
    \            ret[i][j] = ret[i][j-1] + (i-j >= 0 ? ret[i-j][j] : 0);\n       \
    \ }\n    }\n    return ret;\n}\n\n// O(n)\n// Montmort[n] := 1, ..., n \u306E\u64B9\
    \u4E71\u9806\u5217\u306E\u7DCF\u6570(n > 0)\ntemplate<typename T>\nvector<T> Montmort(int\
    \ n) {\n    vector<T> ret(n+1);\n    ret[2] = 1;\n    for (int k = 3; k <= n;\
    \ ++k) {\n        ret[k] = (k-1) * (ret[k-1] + ret[k-2]);\n    }\n    return ret;\n\
    }\n#line 5 \"test/yosupo-judge/montmort_number.test.cpp\"\n\n\nint main() {\n\n\
    \    int N, M; cin >> N >> M;\n\n    using Int = rmint<ll>;\n    Int::set_mod(M);\n\
    \n    auto ans = Montmort<Int>(N);\n    for (int k = 1; k <= N; ++k) {\n     \
    \   if (k) cout << ' ';\n        cout << ans[k];\n    }\n    cout << endl;\n\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/montmort_number_mod\"\n\
    \n#include \"../../lib/number/rmint.cpp\"\n#include \"../../lib/number/comb.cpp\"\
    \n\n\nint main() {\n\n    int N, M; cin >> N >> M;\n\n    using Int = rmint<ll>;\n\
    \    Int::set_mod(M);\n\n    auto ans = Montmort<Int>(N);\n    for (int k = 1;\
    \ k <= N; ++k) {\n        if (k) cout << ' ';\n        cout << ans[k];\n    }\n\
    \    cout << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - lib/number/rmint.cpp
  - lib/template.cpp
  - lib/number/comb.cpp
  isVerificationFile: true
  path: test/yosupo-judge/montmort_number.test.cpp
  requiredBy: []
  timestamp: '2020-10-23 18:09:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/montmort_number.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/montmort_number.test.cpp
- /verify/test/yosupo-judge/montmort_number.test.cpp.html
title: test/yosupo-judge/montmort_number.test.cpp
---
