---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/mod.cpp
    title: "\u96E2\u6563\u5BFE\u6570 BSGS O(sqrt(m))"
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/number/logm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#line 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/mod.cpp\"\n\nll powm(ll a, ll\
    \ n, ll m) {\n    ll ret = 1;\n    while (n > 0) {\n        if (n & 1) (ret *=\
    \ a) %= m;\n        (a *= a) %= m;\n        n >>= 1;\n    }\n    return ret;\n\
    }\n\nll invm(ll a, ll m) {\n    return powm(a, m-2, m);\n}\n\nll totient(ll m)\
    \ {\n    ll ret = m;\n    for (int i = 2; i*i <= m; ++i) {\n        if (m % i\
    \ == 0) {\n            ret -= ret / i;\n            while (m % i == 0) m /= i;\n\
    \        }\n    }\n    if (m > 1) ret -= ret / m;\n    return ret;\n}\n\nll inv_coprime(ll\
    \ a, ll m) {\n    return powm(a, totient(m)-1, m);\n}\n\n/**\n * @brief \u96E2\
    \u6563\u5BFE\u6570 BSGS O(sqrt(m))\n * @author habara-k\n * @date 2020/10/16\n\
    \ * @return x^k == y mod m \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306Ek(>=0) (\u306A\
    \u3051\u308C\u3070-1)\n * @require gcd(x, m) = 1\n */\nll log_coprime(ll x, ll\
    \ y, ll m) {\n    ((x %= m) += m) %= m;\n    ((y %= m) += m) %= m;\n    if (y\
    \ == 1 or m == 1) return 0;\n    if (x == 0) return y == 0 ? 1 : -1;\n\n    ll\
    \ s = sqrt(m) + 1;\n    map<ll,int> bs;\n    ll b = 1;\n    for (ll j = 0; j <\
    \ s; ++j, (b *= x) %= m) {\n        if (!bs.count(b)) bs[b] = j;\n    }\n    ll\
    \ inv = inv_coprime(b, m);\n    // m: \u7D20\u6570 \u306E\u3068\u304D\u306F inv\
    \ = invm(b, m) \u3067\u3088\u3044\n    for (ll g = 1, i = 0; i < s; ++i, (g *=\
    \ inv) %= m) {\n        if (bs.count((g * y) % m)) {\n            ll k = i * s\
    \ + bs[(g * y) % m];\n            assert(powm(x, k, m) == y);\n            return\
    \ k;\n        }\n    }\n    return -1;\n}\n\n/**\n * @brief \u96E2\u6563\u5BFE\
    \u6570 O(sqrt(m))\n * https://codeforces.com/blog/entry/56264\n * @author habara-k\n\
    \ * @date 2020/10/16\n * @return x^k == y mod m \u3092\u6E80\u305F\u3059\u6700\
    \u5C0F\u306Ek(>=0) (\u306A\u3051\u308C\u3070-1)\n */\nll logm(ll x, ll y, ll m)\
    \ {\n    ((x %= m) += m) %= m;\n    ((y %= m) += m) %= m;\n\n    if (y == 1 or\
    \ m == 1) return 0;\n    if (x == 0) return y == 0 ? 1 : -1;\n\n    map<ll,int>\
    \ f1, f2;\n    ll m1 = 1, m2 = 1;\n    {\n        ll tmp = m;\n        for (ll\
    \ p = 2; p*p <= m; ++p) {\n            if (tmp % p) continue;\n            while\
    \ (tmp % p == 0) {\n                tmp /= p;\n                ++(x % p ? f2 :\
    \ f1)[p];\n                (x % p ? m2 : m1) *= p;\n            }\n        }\n\
    \        if (tmp > 1) {\n            ++(x % tmp ? f2 : f1)[tmp];\n           \
    \ (x % tmp ? m2 : m1) *= tmp;\n        }\n    }\n\n    int K = 0;\n    for (auto&\
    \ tp : f1) chmax(K, tp.second);\n    for (ll a = 1, k = 0; k < K; ++k, (a *= x)\
    \ %= m) {\n        if (a == y) return k;\n    }\n    if (y % m1 != 0) return -1;\n\
    \n    ll ret = log_coprime(x, y * powm(inv_coprime(x, m2), K, m2), m2);\n    if\
    \ (ret == -1) return ret;\n    else return ret + K;\n}\n\n/**\n * @brief\n * \u5E73\
    \u65B9\u5270\u4F59 O(log(p)^2) ?\n * http://kirika-comp.hatenablog.com/entry/2018/03/12/210446\n\
    \ * @author habara-k\n * @date 2020/10/16\n * @return x^2 == a mod p \u3092\u6E80\
    \u305F\u3059x (\u306A\u3051\u308C\u3070-1)\n * @require p: \u7D20\u6570\n */\n\
    ll modsqrt(ll a, ll p) {\n    a %= p;\n    auto legendre = [&](ll a) {\n     \
    \   return powm(a, (p-1)/2, p);\n    };\n    if (a == 0) return 0;\n    if (p\
    \ == 2) return a;\n    if (legendre(a) != 1) return -1;\n    ll q = p-1, s = 0;\n\
    \    while (q % 2 == 0) q >>= 1, ++s;\n    mt19937 mt;\n    ll z;\n    do {z =\
    \ mt() % p;} while (legendre(z) != p-1);\n\n    ll m = s, c = powm(z, q, p), t\
    \ = powm(a, q, p), r = powm(a, (q+1)/2, p);\n    while (m > 1) {\n        ll k\
    \ = 0, tmp = t;\n        while (tmp != 1) (tmp *= tmp) %= p, ++k;\n        assert(k\
    \ < m);\n        (t *= powm(c, 1ll<<(m-k), p)) %= p;\n        (r *= powm(c, 1ll<<(m-k-1),\
    \ p)) %= p;\n        c = powm(c, 1ll<<(m-k), p);\n        m = k;\n    }\n    assert((r\
    \ * r) % p == a);\n    return r;\n}\n\n#line 4 \"test/number/logm.test.cpp\"\n\
    \nint main()\n{\n    int T; cin >> T;\n    while (T--) {\n        ll X, Y, M;\
    \ cin >> X >> Y >> M;\n        cout << logm(X, Y, M) << endl;\n\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include \"../../lib/number/mod.cpp\"\n\nint main()\n{\n    int T; cin >>\
    \ T;\n    while (T--) {\n        ll X, Y, M; cin >> X >> Y >> M;\n        cout\
    \ << logm(X, Y, M) << endl;\n\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/number/mod.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/number/logm.test.cpp
  requiredBy: []
  timestamp: '2020-10-17 08:43:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/logm.test.cpp
layout: document
redirect_from:
- /verify/test/number/logm.test.cpp
- /verify/test/number/logm.test.cpp.html
title: test/number/logm.test.cpp
---
