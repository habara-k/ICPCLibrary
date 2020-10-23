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
    document_title: "\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF O(n)"
    links:
    - https://onlinejudge.u-aizu.ac.jp/services/review.html#rupc2014_whiteboard/4508173
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/structure/convex_hull_trick.cpp\"\
    \n\n/**\n * @brief\n * ax + b \u306E\u6700\u5C0F\u5024\u3092\u7BA1\u7406\n * @author\
    \ habara-k\n * @date 2020/05/24\n * @verify https://onlinejudge.u-aizu.ac.jp/services/review.html#rupc2014_whiteboard/4508173\n\
    \ */\n\ntemplate<typename T>\nstruct ConvexHullTrick {\n\n    /**\n    * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF O(n)\n    * @param[in] n: \u8FFD\u52A0\
    \u3059\u308B\u7DDA\u5206\u306E\u4E0A\u9650\n    */\n    ConvexHullTrick(int n)\
    \ : deq(n), s(0), t(0), prev(numeric_limits<T>::min()) {}\n\n    /**\n    * @brief\
    \ \u8FFD\u52A0\u30AF\u30A8\u30EA \u306A\u3089\u3057O(1)\n    * @param[in] a, b:\
    \ ax + b \u3092\u8FFD\u52A0\n    */\n    void insert(T a, T b) {\n        Line\
    \ l = {a, b};\n        while (t - s >= 2 and check(deq[t - 2], deq[t - 1], l))\
    \ --t;\n        deq[t++] = l;\n    }\n\n    /**\n    * @brief \u53D6\u5F97\u30AF\
    \u30A8\u30EA \u306A\u3089\u3057O(1)\n    * @param[in] x: x\u306B\u304A\u3051\u308B\
    \u6700\u5C0F\u5024\u3092\u8FD4\u3059\n    * @details x \u306F\u6607\u9806\u306B\
    \u547C\u3076\u3053\u3068\n    */\n    T query(T x) {\n        assert(prev <= x);\n\
    \        prev = x;\n        while (t - s >= 2 and f(deq[s], x) >= f(deq[s + 1],\
    \ x)) ++s;\n        return f(deq[s], x);\n    }\n\nprivate:\n    struct Line {\n\
    \        T a, b;\n    };\n    vector<Line> deq;\n    int s, t;\n    T prev;\n\n\
    \    bool check(const Line& l1, const Line& l2, const Line& l3) const {\n    \
    \    return (l2.a - l1.a) * (l3.b - l2.b) >= (l2.b - l1.b) * (l3.a - l2.a);\n\
    \    }\n    T f(Line& l, T x) const {\n        return l.a * x + l.b;\n    }\n\
    };\n\n\n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief\n * ax + b \u306E\u6700\u5C0F\
    \u5024\u3092\u7BA1\u7406\n * @author habara-k\n * @date 2020/05/24\n * @verify\
    \ https://onlinejudge.u-aizu.ac.jp/services/review.html#rupc2014_whiteboard/4508173\n\
    \ */\n\ntemplate<typename T>\nstruct ConvexHullTrick {\n\n    /**\n    * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF O(n)\n    * @param[in] n: \u8FFD\u52A0\
    \u3059\u308B\u7DDA\u5206\u306E\u4E0A\u9650\n    */\n    ConvexHullTrick(int n)\
    \ : deq(n), s(0), t(0), prev(numeric_limits<T>::min()) {}\n\n    /**\n    * @brief\
    \ \u8FFD\u52A0\u30AF\u30A8\u30EA \u306A\u3089\u3057O(1)\n    * @param[in] a, b:\
    \ ax + b \u3092\u8FFD\u52A0\n    */\n    void insert(T a, T b) {\n        Line\
    \ l = {a, b};\n        while (t - s >= 2 and check(deq[t - 2], deq[t - 1], l))\
    \ --t;\n        deq[t++] = l;\n    }\n\n    /**\n    * @brief \u53D6\u5F97\u30AF\
    \u30A8\u30EA \u306A\u3089\u3057O(1)\n    * @param[in] x: x\u306B\u304A\u3051\u308B\
    \u6700\u5C0F\u5024\u3092\u8FD4\u3059\n    * @details x \u306F\u6607\u9806\u306B\
    \u547C\u3076\u3053\u3068\n    */\n    T query(T x) {\n        assert(prev <= x);\n\
    \        prev = x;\n        while (t - s >= 2 and f(deq[s], x) >= f(deq[s + 1],\
    \ x)) ++s;\n        return f(deq[s], x);\n    }\n\nprivate:\n    struct Line {\n\
    \        T a, b;\n    };\n    vector<Line> deq;\n    int s, t;\n    T prev;\n\n\
    \    bool check(const Line& l1, const Line& l2, const Line& l3) const {\n    \
    \    return (l2.a - l1.a) * (l3.b - l2.b) >= (l2.b - l1.b) * (l3.a - l2.a);\n\
    \    }\n    T f(Line& l, T x) const {\n        return l.a * x + l.b;\n    }\n\
    };\n\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/structure/convex_hull_trick.cpp
  requiredBy: []
  timestamp: '2020-05-24 21:07:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/structure/convex_hull_trick.cpp
layout: document
redirect_from:
- /library/lib/structure/convex_hull_trick.cpp
- /library/lib/structure/convex_hull_trick.cpp.html
title: "\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF O(n)"
---
