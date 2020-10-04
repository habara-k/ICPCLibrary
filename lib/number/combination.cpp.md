---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/number/mod.cpp
    title: lib/number/mod.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/number/Bell.test.cpp
    title: test/number/Bell.test.cpp
  - icon: ':x:'
    path: test/number/C.test.cpp
    title: test/number/C.test.cpp
  - icon: ':x:'
    path: test/number/Partition1.test.cpp
    title: test/number/Partition1.test.cpp
  - icon: ':x:'
    path: test/number/Partition2.test.cpp
    title: test/number/Partition2.test.cpp
  - icon: ':x:'
    path: test/number/Stirling.test.cpp
    title: test/number/Stirling.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/mod.cpp\"\
    \n\nll powm(ll a, ll n, ll m) {\n    ll ret = 1;\n    while (n > 0) {\n      \
    \  if (n & 1) (ret *= a) %= m;\n        (a *= a) %= m;\n        n >>= 1;\n   \
    \ }\n    return ret;\n}\n\nll invm(ll a, ll m) {\n    return powm(a, m-2, m);\n\
    }\n\n\n/**\n * @brief\n * \u96E2\u6563\u5BFE\u6570 O(sqrt(m))\n * @author habara-k\n\
    \ * @date 2020/05/18\n * @verify https://atcoder.jp/contests/arc042/submissions/13372745\n\
    \ *\n * @param[in] a: 0 < a < m\n * @param[in] b: 0 <= b < m\n * @param[in] m:\
    \ prime\n * @return:\n *     minimum x >= 0 s.t. a^x == b mod m\n *     if no\
    \ x satisfies the condition, return -1\n */\n\nll logm(ll a, ll b, ll m) {\n\n\
    \    ll sm = sqrt(m);\n\n    map<ll,int> mp;\n    for (ll t = 1, r = 0; r < sm;\
    \ (t *= a) %= m, ++r) {\n        if (!mp.count(t)) mp[t] = r;\n    }\n\n    ll\
    \ A = invm(powm(a, sm, m), m);\n    for (ll t = b, p = 0; p <= sm; (t *= A) %=\
    \ m, ++p) {\n        if (mp.count(t)) {\n            return sm * p + mp[t];\n\
    \        }\n    }\n    return -1;\n}\n#line 2 \"lib/number/combination.cpp\"\n\
    \nvector<ll> fact;\nvoid init_fact(int n, ll m) {\n    fact.assign(n+1, 1);\n\
    \    for (int i = 2; i <= n; ++i) {\n        (fact[i] = fact[i-1] * i) %= m;\n\
    \    }\n}\n\n// require init_fact(GREATER THAN OR EQUAL TO n, m)\nll C(ll n, ll\
    \ r, ll m) {\n    return (fact[n] * invm((fact[r] * fact[n-r]) % m, m)) % m;\n\
    }\n\n// Stirling number O(klogn)\n// Stirling(n, k) := the number of cases\n//\
    \            to split n balls(distinguished)\n//            into k boxes(not distinguished)\n\
    //            s.t. each box contains at least one ball.\n//\n// S(n, k) = S(n-1,\
    \ k-1) + k * S(n-1, k) : n, k\u307E\u3067\u306E\u30C6\u30FC\u30D6\u30EB\u3092\u4F5C\
    \u308A\u305F\u3044\u3068\u304D\u306F\u3053\u3063\u3061\n//\n// require init_fact(GREATER\
    \ THAN OR EQUAL TO k, m)\nll Stirling(ll n, ll k, ll m) {\n    ll ret = 0;\n \
    \   for (ll l = 0; l <= k; ++l) {\n        ll tmp = (C(k, l, m) * powm((k-l) %\
    \ m, n, m)) % m;\n        if (l & 1) tmp = (-tmp + m) % m;\n        (ret += tmp)\
    \ %= m;\n    }\n    return (ret *= invm(fact[k], m)) %= m;\n}\n\n// \u30B9\u30BF\
    \u30FC\u30EA\u30F3\u30B0\u6570\u306E\u5FDC\u7528(\u3051\u3093\u3061\u3087\u3093\
    \u3055\u3093\u306E\u5199\u50CF12\u76F8\u306E\u30D6\u30ED\u30B0\uFF09\n// \u30FB\
    \u300C\u5404\u30B0\u30EB\u30FC\u30D7\u306B\u3064\u304Dr\u500B\u4EE5\u4E0A\u300D\
    \u306E\u5236\u9650\u304C\u3042\u308B\u5834\u5408\n// S'(n, k) = C(n-1, r-1) *\
    \ S'(n-r, k-1) + k * S'(n-1, k)\n// \n// \u30FB\u7389\u304Cn\u500B\u3042\u308B\
    \u3046\u3061\u306E\u3044\u304F\u3064\u304B\u3092\u9078\u3093\u3067k\u30B0\u30EB\
    \u30FC\u30D7\u306B\u5206\u3051\u308B\u5834\u5408\n// S'(n, k) = S'(n-1, k-1) +\
    \ (k+1) * S'(n-1, k)\n\n// Bell number O(n^2)\n// Bell(n, k) := the number of\
    \ cases\n//            to split n balls(distinguished)\n//            into k boxes(not\
    \ distinguished)\n//\n// B(n, k) = S(n, 0) + S(n, 1) + ... + S(n, k)\n//\n// B(n+1)\
    \ := B(n+1, n+1) = \u03A3[i=0; n]{C(n, i) * B(i)}\n//\n// require init_fact(GREATER\
    \ THAN OR EQUAL TO k, m)\nll Bell(ll n, ll k, ll m) {\n    ll ret = 0;\n    for\
    \ (ll l = 0; l <= k; ++l) {\n        (ret += Stirling(n, l, m)) %= m;\n    }\n\
    \    return ret;\n}\n\n// Partition function O(nk)\n// Partition[k][n] := the\
    \ number of cases\n//            to split n balls(not distinguished)\n//     \
    \       into k boxes(not distinguished)\n//\n// P(n, k) = P(n, k-1) + P(n-k, k)\n\
    vector<vector<ll>> Part;\nvoid init_partition(ll k, ll n, ll m) {\n    Part.assign(k+1,\
    \ vector<ll>(n+1, 0));\n    Part[0][0] = 1;\n    for (int i = 1; i <= k; ++i)\
    \ {\n        for (int j = 0; j <= n; ++j) {\n            if (j-i >= 0) {\n   \
    \             Part[i][j] = (Part[i-1][j] + Part[i][j-i]) % m;\n            } else\
    \ {\n                Part[i][j] = Part[i-1][j];\n            }\n        }\n  \
    \  }\n}\n\n// \u8B0E\u6F38\u5316\u5F0F\u3067O(n * sqrt(n))\n// \u3051\u3093\u3061\
    \u3087\u3093\u3055\u3093\u306E\u5199\u50CF12\u76F8\u30D6\u30ED\u30B0\nvector<ll>\
    \ P2;\nvoid partition_fast(ll n, ll m) {\n    P2[0] = 1;\n    for(int i=1;i<100;++i)\
    \ {\n        for(int j=1, sign = 1; i - (j*j*3-j)/2 >= 0; ++j, sign *= -1) {\n\
    \            P2[i] += P[i-(j*j*3-j)/2] * sign;\n            if(i - (j*j*3+j)/2\
    \ >= 0) P[i] += P[i-(j*j*3+j)/2] * sign;\n        }\n    }\n}\n"
  code: "#include \"mod.cpp\"\n\nvector<ll> fact;\nvoid init_fact(int n, ll m) {\n\
    \    fact.assign(n+1, 1);\n    for (int i = 2; i <= n; ++i) {\n        (fact[i]\
    \ = fact[i-1] * i) %= m;\n    }\n}\n\n// require init_fact(GREATER THAN OR EQUAL\
    \ TO n, m)\nll C(ll n, ll r, ll m) {\n    return (fact[n] * invm((fact[r] * fact[n-r])\
    \ % m, m)) % m;\n}\n\n// Stirling number O(klogn)\n// Stirling(n, k) := the number\
    \ of cases\n//            to split n balls(distinguished)\n//            into\
    \ k boxes(not distinguished)\n//            s.t. each box contains at least one\
    \ ball.\n//\n// S(n, k) = S(n-1, k-1) + k * S(n-1, k) : n, k\u307E\u3067\u306E\
    \u30C6\u30FC\u30D6\u30EB\u3092\u4F5C\u308A\u305F\u3044\u3068\u304D\u306F\u3053\
    \u3063\u3061\n//\n// require init_fact(GREATER THAN OR EQUAL TO k, m)\nll Stirling(ll\
    \ n, ll k, ll m) {\n    ll ret = 0;\n    for (ll l = 0; l <= k; ++l) {\n     \
    \   ll tmp = (C(k, l, m) * powm((k-l) % m, n, m)) % m;\n        if (l & 1) tmp\
    \ = (-tmp + m) % m;\n        (ret += tmp) %= m;\n    }\n    return (ret *= invm(fact[k],\
    \ m)) %= m;\n}\n\n// \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u5FDC\u7528\
    (\u3051\u3093\u3061\u3087\u3093\u3055\u3093\u306E\u5199\u50CF12\u76F8\u306E\u30D6\
    \u30ED\u30B0\uFF09\n// \u30FB\u300C\u5404\u30B0\u30EB\u30FC\u30D7\u306B\u3064\u304D\
    r\u500B\u4EE5\u4E0A\u300D\u306E\u5236\u9650\u304C\u3042\u308B\u5834\u5408\n//\
    \ S'(n, k) = C(n-1, r-1) * S'(n-r, k-1) + k * S'(n-1, k)\n// \n// \u30FB\u7389\
    \u304Cn\u500B\u3042\u308B\u3046\u3061\u306E\u3044\u304F\u3064\u304B\u3092\u9078\
    \u3093\u3067k\u30B0\u30EB\u30FC\u30D7\u306B\u5206\u3051\u308B\u5834\u5408\n//\
    \ S'(n, k) = S'(n-1, k-1) + (k+1) * S'(n-1, k)\n\n// Bell number O(n^2)\n// Bell(n,\
    \ k) := the number of cases\n//            to split n balls(distinguished)\n//\
    \            into k boxes(not distinguished)\n//\n// B(n, k) = S(n, 0) + S(n,\
    \ 1) + ... + S(n, k)\n//\n// B(n+1) := B(n+1, n+1) = \u03A3[i=0; n]{C(n, i) *\
    \ B(i)}\n//\n// require init_fact(GREATER THAN OR EQUAL TO k, m)\nll Bell(ll n,\
    \ ll k, ll m) {\n    ll ret = 0;\n    for (ll l = 0; l <= k; ++l) {\n        (ret\
    \ += Stirling(n, l, m)) %= m;\n    }\n    return ret;\n}\n\n// Partition function\
    \ O(nk)\n// Partition[k][n] := the number of cases\n//            to split n balls(not\
    \ distinguished)\n//            into k boxes(not distinguished)\n//\n// P(n, k)\
    \ = P(n, k-1) + P(n-k, k)\nvector<vector<ll>> Part;\nvoid init_partition(ll k,\
    \ ll n, ll m) {\n    Part.assign(k+1, vector<ll>(n+1, 0));\n    Part[0][0] = 1;\n\
    \    for (int i = 1; i <= k; ++i) {\n        for (int j = 0; j <= n; ++j) {\n\
    \            if (j-i >= 0) {\n                Part[i][j] = (Part[i-1][j] + Part[i][j-i])\
    \ % m;\n            } else {\n                Part[i][j] = Part[i-1][j];\n   \
    \         }\n        }\n    }\n}\n\n// \u8B0E\u6F38\u5316\u5F0F\u3067O(n * sqrt(n))\n\
    // \u3051\u3093\u3061\u3087\u3093\u3055\u3093\u306E\u5199\u50CF12\u76F8\u30D6\u30ED\
    \u30B0\nvector<ll> P2;\nvoid partition_fast(ll n, ll m) {\n    P2[0] = 1;\n  \
    \  for(int i=1;i<100;++i) {\n        for(int j=1, sign = 1; i - (j*j*3-j)/2 >=\
    \ 0; ++j, sign *= -1) {\n            P2[i] += P[i-(j*j*3-j)/2] * sign;\n     \
    \       if(i - (j*j*3+j)/2 >= 0) P[i] += P[i-(j*j*3+j)/2] * sign;\n        }\n\
    \    }\n}\n"
  dependsOn:
  - lib/number/mod.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/combination.cpp
  requiredBy: []
  timestamp: '2020-10-05 04:39:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/number/C.test.cpp
  - test/number/Stirling.test.cpp
  - test/number/Bell.test.cpp
  - test/number/Partition1.test.cpp
  - test/number/Partition2.test.cpp
documentation_of: lib/number/combination.cpp
layout: document
redirect_from:
- /library/lib/number/combination.cpp
- /library/lib/number/combination.cpp.html
title: lib/number/combination.cpp
---
