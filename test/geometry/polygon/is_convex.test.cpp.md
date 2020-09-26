---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/geometry/polygon.cpp
    title: "\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D\u3092\u6C42\u3081\u308B(\u53CD\u6642\
      \u8A08\u56DE\u308A\u3067\u6B63)."
  - icon: ':heavy_check_mark:'
    path: lib/geometry/2D_template.cpp
    title: "\u70B9p \u306E\u76F4\u7DDAl \u3078\u306E\u5C04\u5F71\u3092\u6C42\u3081\
      \u308B."
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B
  bundledCode: "#line 1 \"test/geometry/polygon/is_convex.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B\"\n\n#line\
    \ 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i, n) for (int i=(int)(n)-1;\
    \ i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n); ++i)\n#define RFOR(i,\
    \ a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/geometry/2D_template.cpp\"\n\n/**\n\
    \ * @brief\n * \u4E8C\u6B21\u5143\u5E7E\u4F55\n * @author habara-k\n * @date 2020/05/05\n\
    \ */\n\nusing Real = double;\nconst Real PI = acos(-1);\n\nusing Point = complex<Real>;\n\
    namespace std {\n    bool operator<(const Point& a, const Point& b) {\n      \
    \  if (a.real() == b.real()) return a.imag() < b.imag();\n        return a.real()\
    \ < b.real();\n    }\n}\n\nstruct Line {\n    Point a, b;\n    Line() {}\n   \
    \ Line(const Point& a, const Point& b) : a(a), b(b) {}\n    friend ostream& operator<<(ostream&\
    \ os, const Line& l) {\n        return os << \"[\" << l.a << \",\" << l.b << \"\
    ]\";\n    }\n};\n\nstruct Segment : Line {\n    Segment() {}\n\n    Segment(const\
    \ Point& a, const Point& b) : Line(a, b) {}\n};\n\ninline bool eq(Real a, Real\
    \ b) { return abs(b - a) < eps; }\n\nReal radian_to_degree(Real r) {\n    return\
    \ r * 180.0 / PI;\n}\n\nReal degree_to_radian(Real d) {\n    return d * PI / 180.0;\n\
    }\n\nPoint rotate(const Point &p, Real theta) {\n    return p * polar((Real)1.0,\
    \ theta);\n}\n\nReal cross(const Point& a, const Point& b) {\n    return a.real()\
    \ * b.imag() - a.imag() * b.real();\n}\n\nReal dot(const Point& a, const Point&\
    \ b) {\n    return a.real() * b.real() + a.imag() * b.imag();\n}\n\n\n/**\n* @brief\
    \ \u70B9p \u306E\u76F4\u7DDAl \u3078\u306E\u5C04\u5F71\u3092\u6C42\u3081\u308B\
    .\n*/\nPoint projection(const Line& l, const Point& p) {\n    Real A = dot(l.b\
    \ - l.a, p - l.a),\n         B = dot(l.a - l.b, p - l.b);\n    return (A * l.b\
    \ + B * l.a) / (A + B);\n}\n\n/**\n* @brief 2\u76F4\u7DDA\u306E\u4E26\u884C\u5224\
    \u5B9A\n*/\nbool parallel(const Line& l1, const Line& l2) {\n    return eq(cross(l1.a\
    \ - l1.b, l2.a - l2.b), 0.0);\n}\n\n/**\n* @brief 2\u76F4\u7DDA\u306E\u76F4\u884C\
    \u5224\u5B9A\n*/\nbool orthogonal(const Line& l1, const Line& l2) {\n    return\
    \ eq(dot(l1.a - l1.b, l2.a - l2.b), 0.0);\n}\n\n\n/**\n* @brief \u6709\u5411\u7DDA\
    \u5206\u3068\u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2\n* @param[in] a, b, c: \u7DDA\
    \u5206a->b, \u70B9c\n* @return \u7DDA\u5206a->b \u304B\u3089\u307F\u3066, \u70B9\
    c \u304C\u3069\u3053\u306B\u3042\u308B\u304B.\n*/\nconst int COUNTER_CLOCKWISE\
    \ = 1,\n          CLOCKWISE = -1,\n          ONLINE_BACK = 2,\n          ONLINE_FRONT\
    \ = -2,\n          ON_SEGMENT = 0;\nint ccw(const Point& a, Point b, Point c)\
    \ {\n    b = b - a, c = c - a;\n    if (cross(b, c) > eps) return COUNTER_CLOCKWISE;\n\
    \    if (cross(b, c) < -eps) return CLOCKWISE;\n    if (dot(b, c) < 0) return\
    \ ONLINE_BACK;\n    if (norm(b) < norm(c)) return ONLINE_FRONT;\n    return ON_SEGMENT;\n\
    }\n\n\n/**\n* @brief \u76F4\u7DDA\u3068\u70B9\u306E\u4EA4\u5DEE\u5224\u5B9A\n\
    */\nbool intersected(const Line& l, const Point& p) {\n    return abs(ccw(l.a,\
    \ l.b, p)) != 1;\n}\n\n/**\n* @brief \u7DDA\u5206\u3068\u70B9\u306E\u4EA4\u5DEE\
    \u5224\u5B9A\n*/\nbool intersected(const Segment& s, const Point& p) {\n    return\
    \ ccw(s.a, s.b, p) == 0;\n}\n\n/**\n* @brief \u76F4\u7DDA\u3068\u7DDA\u5206\u306E\
    \u4EA4\u5DEE\u5224\u5B9A\n*/\nbool intersected(const Line& l, const Segment& s)\
    \ {\n    return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps;\n\
    }\n\n/**\n* @brief 2\u3064\u306E\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\n*/\n\
    bool intersected(const Segment& s1, const Segment& s2) {\n    return ccw(s1.a,\
    \ s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 and\n           ccw(s2.a, s2.b, s1.a)\
    \ * ccw(s2.a, s2.b, s1.b) <= 0;\n}\n\n\n/**\n* @brief 2\u76F4\u7DDA\u306E\u4EA4\
    \u70B9\n*/\nPoint crosspoint(const Line& l1, const Line& l2) {\n    Real A = cross(l2.a\
    \ - l1.a, l2.b - l1.a),\n         B = cross(l2.b - l1.b, l2.a - l1.b);\n    return\
    \ (A * l1.b + B * l1.a) / (A + B);\n}\n\n\n/**\n* @brief \u76F4\u7DDA\u3068\u70B9\
    \u306E\u8DDD\u96E2\n*/\nReal distance(const Line& l, const Point& p) {\n    return\
    \ abs(p - projection(l, p));\n}\n\n/**\n* @brief \u7DDA\u5206\u3068\u70B9\u306E\
    \u8DDD\u96E2\n*/\nReal distance(const Segment& s, const Point& p) {\n    Point\
    \ r = projection(s, p);\n    if (intersected(s, r)) return abs(r - p);\n    return\
    \ min(abs(s.a - p), abs(s.b - p));\n}\n\n/**\n* @brief \u76F4\u7DDA\u3068\u7DDA\
    \u5206\u306E\u8DDD\u96E2\n*/\nReal distance(const Line &l, const Segment &s) {\n\
    \    if (intersected(l, s)) return 0;\n    return min(distance(l, s.a), distance(l,\
    \ s.b));\n}\n\n/**\n* @brief 2\u3064\u306E\u7DDA\u5206\u306E\u8DDD\u96E2\n*/\n\
    Real distance(const Segment& s1, const Segment& s2) {\n    if (intersected(s1,\
    \ s2)) return 0.0;\n    return min({ distance(s1, s2.a), distance(s1, s2.b),\n\
    \                 distance(s2, s1.a), distance(s2, s1.b) });\n}\n\n\nstruct Circle\
    \ {\n    Point p;\n    Real r;\n    Circle() {}\n    Circle(const Point& p, Real\
    \ r) : p(p), r(r) {}\n};\n\n\n/**\n* @brief 2\u3064\u306E\u5186\u306E\u4EA4\u70B9\
    \u306E\u6570\n*/\nint intersected(Circle c1, Circle c2) {\n    if (c1.r < c2.r)\
    \ swap(c1, c2);\n    Real d = abs(c1.p - c2.p);\n    if (c1.r + c2.r < d) return\
    \ 4;\n    if (eq(c1.r + c2.r, d)) return 3;\n    if (c1.r - c2.r < d) return 2;\n\
    \    if (eq(c1.r - c2.r, d)) return 1;\n    return 0;\n}\n\n/**\n* @brief \u5186\
    \u3068\u76F4\u7DDA\u306E\u4EA4\u70B9\u306E\u30DA\u30A2\n* @details \u4EA4\u5DEE\
    \u3059\u308B\u3053\u3068\u3092\u78BA\u8A8D\u3057\u3066\u304B\u3089\u547C\u3076\
    \u3053\u3068.\n*/\npair<Point,Point> crosspoint(const Circle& c, const Line& l)\
    \ {\n    Real h = distance(l, c.p);\n    Point p = projection(l, c.p);\n    if\
    \ (eq(h, c.r)) return { p, p };\n    Point u = l.a - l.b; u /= abs(u);\n    Real\
    \ d = sqrt(c.r * c.r - h * h);\n    return { p + u * d, p - u * d };\n}\n\n/**\n\
    * @brief 2\u3064\u306E\u5186\u306E\u4EA4\u70B9\u306E\u30DA\u30A2\n* @details \u4EA4\
    \u5DEE\u3059\u308B\u3053\u3068\u3092\u78BA\u8A8D\u3057\u3066\u304B\u3089\u547C\
    \u3076\u3053\u3068.\n*/\npair<Point,Point> crosspoint(const Circle& c1, const\
    \ Circle& c2) {\n    Real d = abs(c2.p - c1.p), t = arg(c2.p - c1.p);\n    Real\
    \ a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));\n    return\
    \ { c1.p + polar(c1.r, t + a),\n             c1.p + polar(c1.r, t - a) };\n}\n\
    \n/**\n* @brief \u70B9p, \u5186c \u306B\u5BFE\u3057, p\u3092\u901A\u308Bc\u306E\
    \u63A5\u7DDA\u3092\u8FD4\u3059(c\u4E0A\u306E2\u70B9\u306E\u30DA\u30A2\u3067\u8FD4\
    \u3059).\n* @details \u70B9p \u304C\u5186c \u306E\u5916\u5074\u306B\u3042\u308B\
    \u3053\u3068\u3092\u78BA\u8A8D\u3057\u3066\u304B\u3089\u547C\u3076\u3053\u3068\
    .\n*/\npair<Point,Point> tangent(const Point& p, const Circle& c) {\n    return\
    \ crosspoint(c, Circle(p, sqrt(norm(p - c.p) - c.r * c.r)));\n};\n\n/**\n* @brief\
    \ 2\u3064\u306E\u5186\u306B\u5171\u901A\u3059\u308B\u63A5\u7DDA\u3092\u8FD4\u3059\
    (\u6700\u59274\u672C).\n* @details \u70B9p \u304C\u5186c \u306E\u5916\u5074\u306B\
    \u3042\u308B\u3053\u3068\u3092\u78BA\u8A8D\u3057\u3066\u304B\u3089\u547C\u3076\
    \u3053\u3068.\n*/\nvector<Line> common_tangent(const Circle& c1, const Circle&\
    \ c2) {\n    vector<Line> lines;\n    Point u = c2.p - c1.p;\n    Real d = abs(u);\n\
    \    if (eq(d, 0.0)) return lines;\n    u /= d;\n    for (Real s : { -1, 1 })\
    \ {\n        // s = -1: \u540C\u3058\u5074\u306B2\u3064\u306E\u5186\u304C\u3042\
    \u308B\u3068\u304D.\n        // s =  1: \u53CD\u5BFE\u5074\u306B2\u3064\u306E\u5186\
    \u304C\u3042\u308B\u3068\u304D.\n        Real h = (c1.r + s * c2.r) / d;\n   \
    \     if (eq(abs(h), 1.0)) {\n            // 2\u3064\u306E\u5186\u304C\u63A5\u3057\
    \u3066\u3044\u308B\u3068\u304D.\n            lines.emplace_back(\n           \
    \         c1.p + u * h * c1.r,\n                    c1.p + u * h * c1.r + rotate(u,\
    \ PI / 2.0));\n        } else if (abs(h) < 1) {\n            // 2\u672C\u306E\u63A5\
    \u7DDA\u304C\u5F15\u3051\u308B\u3068\u304D.\n            Real a = acos(h);\n \
    \           lines.emplace_back(\n                    c1.p + u * polar(c1.r, a),\n\
    \                    c2.p - s * u * polar(c2.r, a));\n            lines.emplace_back(\n\
    \                    c1.p + u * polar(c1.r, -a),\n                    c2.p - s\
    \ * u * polar(c2.r, -a));\n        }\n    }\n    return lines;\n}\n\n#line 2 \"\
    lib/geometry/polygon.cpp\"\n\n/**\n * @brief\n * \u591A\u89D2\u5F62\n * @author\
    \ habara-k\n * @date 2020/05/05\n */\n\nusing Polygon = vector<Point>;\n\n/**\n\
    * @brief \u7B26\u53F7\u4ED8\u304D\u9762\u7A4D\u3092\u6C42\u3081\u308B(\u53CD\u6642\
    \u8A08\u56DE\u308A\u3067\u6B63).\n*/\nReal area(const Polygon& U) {\n    Real\
    \ area = 0;\n    for (int i = 0; i < U.size(); ++i) {\n        area += cross(U[i],\
    \ U[(i + 1) % U.size()]);\n    }\n    return area / 2.0;\n}\n\n/**\n* @brief \u51F8\
    \u5224\u5B9A\n* @details \u9802\u70B9\u306F\u53CD\u6642\u8A08\u56DE\u308A\u3067\
    \u4E0E\u3048\u308B\u3053\u3068.\n*/\nbool is_convex(const Polygon &U) {\n    int\
    \ n = U.size();\n    for (int i = 0; i < n; ++i) {\n        if (ccw(U[i], U[(i\
    \ + 1) % n], U[(i + 2) % n]) == -1) return false;\n    }\n    return true;\n}\n\
    \n/**\n* @brief \u70B9\u306E\u5185\u90E8\u5224\u5B9A\n*/\nconst int OUT = 0,\n\
    \          ON = 1,\n          IN = 2;\nint contains(const Polygon &U, const Point\
    \ &p) {\n    int in = 0;\n    for (int i = 0; i < U.size(); ++i) {\n        Point\
    \ a = U[i] - p, b = U[(i + 1) % U.size()] - p;\n        if (cross(a, b) == 0 and\
    \ dot(a, b) <= 0) return ON;\n        if (a.imag() > b.imag()) swap(a, b);\n \
    \       if (a.imag() <= 0 and 0 < b.imag() and cross(a, b) < 0) in ^= 1;\n   \
    \ }\n    return in ? IN : OUT;\n}\n\n/**\n* @brief \u51F8\u5305\n* @param[in]\
    \ includeOnLine: \u51F8\u5305\u306E\u8FBA\u4E0A\u306B\u4F4D\u7F6E\u3059\u308B\u70B9\
    \u3082\u6B32\u3057\u3044\u3068\u304D\u306Btrue \u306B\u3059\u308B.\n* @return\
    \ \u51F8\u5305\u4E0A\u306E\u9802\u70B9(\u53CD\u6642\u8A08\u56DE\u308A).\n*/\n\
    vector<Point> convex_hull(vector<Point>& p, bool includeOnLine = false) {\n  \
    \  int n = p.size(), k = 0;\n    if (n <= 2) return p;\n    sort(p.begin(), p.end(),\
    \ [](Point& a, Point& b) {\n            if (a.real() == b.real()) return a.imag()\
    \ < b.imag();\n            return a.real() < b.real();\n            });\n    vector<Point>\
    \ ch(n * 2);\n    const Real BOUND = includeOnLine ? -eps : eps;\n    for (int\
    \ i = 0; i < n; ch[k++] = p[i++]) {\n        while (k >= 2 and cross(ch[k-1] -\
    \ ch[k-2], p[i] - ch[k-1]) < BOUND) --k;\n    }\n    for (int i = n-2, t = k+1;\
    \ i >= 0; ch[k++] = p[i--]) {\n        while (k >= t and cross(ch[k-1] - ch[k-2],\
    \ p[i] - ch[k-1]) < BOUND) --k;\n    }\n    ch.resize(k-1);\n    return ch;\n\
    }\n\n/**\n* @brief \u51F8\u591A\u89D2\u5F62\u306E\u76F4\u5F84\n*/\nReal convex_diameter(const\
    \ Polygon &U) {\n    int n = U.size();\n    int is = 0, js = 0;\n    for (int\
    \ i = 1; i < n; ++i) {\n        if (U[i].imag() > U[is].imag()) is = i;\n    \
    \    if (U[i].imag() < U[js].imag()) js = i;\n    }\n    Real maxnorm = norm(U[is]\
    \ - U[js]);\n\n    int i = is, j = js;\n    do {\n        if (cross(U[(i+1) %\
    \ n] - U[i], U[(j+1) % n] - U[j]) >= 0) {\n            j = (j+1) % n;\n      \
    \  } else {\n            i = (i+1) % n;\n        }\n        if (norm(U[i] - U[j])\
    \ > maxnorm) {\n            maxnorm = norm(U[i] - U[j]);\n        }\n    } while\
    \ (i != is or j != js);\n    return sqrt(maxnorm);\n}\n\n/**\n* @brief \u51F8\u30AB\
    \u30C3\u30C8\n* @param[in] U: \u30AB\u30C3\u30C8\u3057\u305F\u3044\u51F8\u591A\
    \u89D2\u5F62\n* @param[in] l: \u30AB\u30C3\u30C8\u306B\u7528\u3044\u308B\u76F4\
    \u7DDA\n* @return \u76F4\u7DDAl.a->l.b \u304B\u3089\u307F\u3066\u53CD\u6642\u8A08\
    \u56DE\u308A\u5074\u306E\u51F8\u591A\u89D2\u5F62\u3092\u8FD4\u3059(\u5165\u529B\
    \u3068\u540C\u3058\u56DE\u308A\u9806).\n*/\nPolygon convex_cut(const Polygon&\
    \ U, const Line& l) {\n    Polygon ret;\n    for (int i = 0; i < U.size(); ++i)\
    \ {\n        Point now = U[i], nxt = U[(i + 1) % U.size()];\n        if (ccw(l.a,\
    \ l.b, now) != -1) ret.push_back(now);\n        if (ccw(l.a, l.b, now) * ccw(l.a,\
    \ l.b, nxt) == -1) {\n            ret.push_back(crosspoint(Line{ now, nxt }, l));\n\
    \        }\n    }\n    return ret;\n}\n\n#line 4 \"test/geometry/polygon/is_convex.test.cpp\"\
    \n\nint main()\n{\n    int n; cin >> n;\n    vector<Point> p(n);\n    for (int\
    \ i = 0; i < n; ++i) {\n        double x, y; cin >> x >> y;\n        p[i] = {\
    \ x, y };\n    }\n\n    cout << is_convex(p) << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B\"\
    \n\n#include \"../../../lib/geometry/polygon.cpp\"\n\nint main()\n{\n    int n;\
    \ cin >> n;\n    vector<Point> p(n);\n    for (int i = 0; i < n; ++i) {\n    \
    \    double x, y; cin >> x >> y;\n        p[i] = { x, y };\n    }\n\n    cout\
    \ << is_convex(p) << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - lib/geometry/polygon.cpp
  - lib/geometry/2D_template.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/geometry/polygon/is_convex.test.cpp
  requiredBy: []
  timestamp: '2020-08-24 14:09:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/polygon/is_convex.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/polygon/is_convex.test.cpp
- /verify/test/geometry/polygon/is_convex.test.cpp.html
title: test/geometry/polygon/is_convex.test.cpp
---
