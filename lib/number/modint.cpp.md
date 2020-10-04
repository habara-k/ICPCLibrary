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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/modint.cpp\"\
    \n\n#define SNIPPET_ONLY\n\ntemplate<int64_t mod>\nclass modint {\n    int64_t\
    \ x;\n\npublic:\n    modint(int64_t x = 0) : x(x < 0 ? ((x % mod) + mod) % mod\
    \ : x % mod) {}\n\n    const modint operator-() const { return x ? mod - x : 0;\
    \ }\n\n    modint& operator+=(const modint& rhs) {\n        if ((x += rhs.x) >=\
    \ mod) x -= mod;\n        return *this;\n    }\n    modint& operator-=(const modint&\
    \ rhs) {\n        return *this += -rhs;\n    }\n    modint& operator*=(const modint&\
    \ rhs) {\n        (x *= rhs.x) %= mod;\n        return *this;\n    }\n    modint&\
    \ operator/=(const modint& rhs) {\n        return *this *= rhs.pow(mod - 2);\n\
    \    }\n\n    friend const modint operator+(modint lhs, const modint& rhs) {\n\
    \        return lhs += rhs;\n    }\n    friend const modint operator-(modint lhs,\
    \ const modint& rhs) {\n        return lhs -= rhs;\n    }\n    friend const modint\
    \ operator*(modint lhs, const modint& rhs) {\n        return lhs *= rhs;\n   \
    \ }\n    friend const modint operator/(modint lhs, const modint& rhs) {\n    \
    \    return lhs /= rhs;\n    }\n\n    const modint pow(int64_t n) const {\n  \
    \      modint ret = 1, tmp = *this;\n        while (n) {\n            if (n &\
    \ 1) ret *= tmp;\n            tmp *= tmp; n >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    friend bool operator==(const modint& lhs, const modint& rhs)\
    \ {\n        return lhs.x == rhs.x;\n    }\n    friend bool operator!=(const modint&\
    \ lhs, const modint& rhs) {\n        return !(lhs == rhs);\n    }\n\n    friend\
    \ ostream& operator<<(ostream& os, const modint& a) {\n        return os << a.x;\n\
    \    }\n    friend istream& operator>>(istream& is, modint& a) {\n        int64_t\
    \ tmp; is >> tmp; a = tmp;\n        return is;\n    }\n};\n\n"
  code: "#include \"../template.cpp\"\n\n#define SNIPPET_ONLY\n\ntemplate<int64_t\
    \ mod>\nclass modint {\n    int64_t x;\n\npublic:\n    modint(int64_t x = 0) :\
    \ x(x < 0 ? ((x % mod) + mod) % mod : x % mod) {}\n\n    const modint operator-()\
    \ const { return x ? mod - x : 0; }\n\n    modint& operator+=(const modint& rhs)\
    \ {\n        if ((x += rhs.x) >= mod) x -= mod;\n        return *this;\n    }\n\
    \    modint& operator-=(const modint& rhs) {\n        return *this += -rhs;\n\
    \    }\n    modint& operator*=(const modint& rhs) {\n        (x *= rhs.x) %= mod;\n\
    \        return *this;\n    }\n    modint& operator/=(const modint& rhs) {\n \
    \       return *this *= rhs.pow(mod - 2);\n    }\n\n    friend const modint operator+(modint\
    \ lhs, const modint& rhs) {\n        return lhs += rhs;\n    }\n    friend const\
    \ modint operator-(modint lhs, const modint& rhs) {\n        return lhs -= rhs;\n\
    \    }\n    friend const modint operator*(modint lhs, const modint& rhs) {\n \
    \       return lhs *= rhs;\n    }\n    friend const modint operator/(modint lhs,\
    \ const modint& rhs) {\n        return lhs /= rhs;\n    }\n\n    const modint\
    \ pow(int64_t n) const {\n        modint ret = 1, tmp = *this;\n        while\
    \ (n) {\n            if (n & 1) ret *= tmp;\n            tmp *= tmp; n >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    friend bool operator==(const modint&\
    \ lhs, const modint& rhs) {\n        return lhs.x == rhs.x;\n    }\n    friend\
    \ bool operator!=(const modint& lhs, const modint& rhs) {\n        return !(lhs\
    \ == rhs);\n    }\n\n    friend ostream& operator<<(ostream& os, const modint&\
    \ a) {\n        return os << a.x;\n    }\n    friend istream& operator>>(istream&\
    \ is, modint& a) {\n        int64_t tmp; is >> tmp; a = tmp;\n        return is;\n\
    \    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/modint.cpp
  requiredBy: []
  timestamp: '2020-08-24 17:13:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/number/modint.cpp
layout: document
redirect_from:
- /library/lib/number/modint.cpp
- /library/lib/number/modint.cpp.html
title: lib/number/modint.cpp
---
