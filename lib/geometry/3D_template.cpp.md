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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/geometry/3D_template.cpp\"\
    \n\nusing Real = double;\nconst Real PI = acos(-1);\n\nstruct Point3D {\n    double\
    \ x, y, z;\n    Point3D() {}\n    Point3D(double x, double y, double z) : x(x),\
    \ y(y), z(z) {}\n    Point3D operator+(const Point3D& b) const {\n        return\
    \ Point3D(x + b.x, y + b.y, z + b.z);\n    }\n    Point3D operator-(const Point3D&\
    \ b) const {\n        return Point3D(x - b.x, y - b.y, z - b.z);\n    }\n    friend\
    \ double norm(const Point3D& p) {\n        return p.x * p.x + p.y * p.y + p.z\
    \ * p.z;\n    };\n    friend double abs(const Point3D& p) { return sqrt(norm(p));\
    \ }\n\n    friend ostream &operator<<(ostream &os, Point3D &p) {\n        return\
    \ os << \"(\" << p.x << \",\" << p.y << \",\" << p.z << \")\";\n    }\n    friend\
    \ istream &operator>>(istream &is, Point3D &p) {\n        return is >> p.x >>\
    \ p.y >> p.z;\n    }\n};\n\nstruct Segment3D {\n    Point3D a, b;\n    Segment3D()\
    \ {}\n    Segment3D(const Point3D& a, const Point3D& b) : a(a), b(b) {}\n    friend\
    \ ostream &operator<<(ostream &os, Segment3D &l) {\n        return os << \"[\"\
    \ << l.a << \",\" << l.b << \"]\";\n    }\n    friend istream &operator>>(istream\
    \ &is, Segment3D &l) {\n        return is >> l.a >> l.b;\n    }\n};\n\ninline\
    \ bool eq(Real a, Real b) { return abs(b - a) < eps; }\n\ndouble dot(const Point3D\
    \ &a, const Point3D &b) {\n    return a.x * b.x + a.y * b.y + a.z * b.z;\n}\n\n\
    Point3D cross(const Point3D &a, const Point3D &b) {\n    double x = a.y * b.z\
    \ - a.z * b.y,\n           y = a.z * b.x - a.x * b.z,\n           z = a.x * b.y\
    \ - a.y * b.x;\n    return Point3D(x, y, z);\n}\n\nbool parallel(\n        const\
    \ Point3D &a1, const Point3D &a2,\n        const Point3D &b1, const Point3D &b2)\
    \ {\n    return eq(abs(cross(a1-b1, a2-b2)), 0.);\n}\n\nbool parallel(const Segment3D&\
    \ l1, const Segment3D& l2) {\n    return parallel(l1.a, l1.b, l2.a, l2.b);\n}\n\
    \ndouble distance(const Segment3D &l, const Point3D &p) {\n    if (dot(l.b - l.a,\
    \ p - l.a) < eps) return abs(p - l.a);\n    if (dot(l.a - l.b, p - l.b) < eps)\
    \ return abs(p - l.b);\n    return abs(cross(l.b - l.a, p - l.a)) / abs(l.b -\
    \ l.a);\n}\n\n"
  code: "#include \"../template.cpp\"\n\nusing Real = double;\nconst Real PI = acos(-1);\n\
    \nstruct Point3D {\n    double x, y, z;\n    Point3D() {}\n    Point3D(double\
    \ x, double y, double z) : x(x), y(y), z(z) {}\n    Point3D operator+(const Point3D&\
    \ b) const {\n        return Point3D(x + b.x, y + b.y, z + b.z);\n    }\n    Point3D\
    \ operator-(const Point3D& b) const {\n        return Point3D(x - b.x, y - b.y,\
    \ z - b.z);\n    }\n    friend double norm(const Point3D& p) {\n        return\
    \ p.x * p.x + p.y * p.y + p.z * p.z;\n    };\n    friend double abs(const Point3D&\
    \ p) { return sqrt(norm(p)); }\n\n    friend ostream &operator<<(ostream &os,\
    \ Point3D &p) {\n        return os << \"(\" << p.x << \",\" << p.y << \",\" <<\
    \ p.z << \")\";\n    }\n    friend istream &operator>>(istream &is, Point3D &p)\
    \ {\n        return is >> p.x >> p.y >> p.z;\n    }\n};\n\nstruct Segment3D {\n\
    \    Point3D a, b;\n    Segment3D() {}\n    Segment3D(const Point3D& a, const\
    \ Point3D& b) : a(a), b(b) {}\n    friend ostream &operator<<(ostream &os, Segment3D\
    \ &l) {\n        return os << \"[\" << l.a << \",\" << l.b << \"]\";\n    }\n\
    \    friend istream &operator>>(istream &is, Segment3D &l) {\n        return is\
    \ >> l.a >> l.b;\n    }\n};\n\ninline bool eq(Real a, Real b) { return abs(b -\
    \ a) < eps; }\n\ndouble dot(const Point3D &a, const Point3D &b) {\n    return\
    \ a.x * b.x + a.y * b.y + a.z * b.z;\n}\n\nPoint3D cross(const Point3D &a, const\
    \ Point3D &b) {\n    double x = a.y * b.z - a.z * b.y,\n           y = a.z * b.x\
    \ - a.x * b.z,\n           z = a.x * b.y - a.y * b.x;\n    return Point3D(x, y,\
    \ z);\n}\n\nbool parallel(\n        const Point3D &a1, const Point3D &a2,\n  \
    \      const Point3D &b1, const Point3D &b2) {\n    return eq(abs(cross(a1-b1,\
    \ a2-b2)), 0.);\n}\n\nbool parallel(const Segment3D& l1, const Segment3D& l2)\
    \ {\n    return parallel(l1.a, l1.b, l2.a, l2.b);\n}\n\ndouble distance(const\
    \ Segment3D &l, const Point3D &p) {\n    if (dot(l.b - l.a, p - l.a) < eps) return\
    \ abs(p - l.a);\n    if (dot(l.a - l.b, p - l.b) < eps) return abs(p - l.b);\n\
    \    return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);\n}\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/geometry/3D_template.cpp
  requiredBy: []
  timestamp: '2020-08-24 14:09:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/geometry/3D_template.cpp
layout: document
redirect_from:
- /library/lib/geometry/3D_template.cpp
- /library/lib/geometry/3D_template.cpp.html
title: lib/geometry/3D_template.cpp
---
