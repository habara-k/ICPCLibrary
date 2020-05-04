#include "../template.cpp"

/**
 * @brief
 * 二次元幾何
 * @author habara-k
 * @date 2020/05/05
 */

// template {{{

using Real = double;
const Real PI = acos(-1);

using Point = complex<Real>;
struct Line {
    Point a, b;
    Line() {}
    Line(const Point& a, const Point& b) : a(a), b(b) {}
    friend ostream& operator<<(ostream& os, const Line& l) {
        return os << "[" << l.a << "," << l.b << "]";
    }
};
struct Segment : Line {
    Segment() {}
    // Segment() = default;

    Segment(const Point& a, const Point& b) : Line(a, b) {}
};

inline bool eq(Real a, Real b) { return abs(b - a) < eps; }

// }}}


// utils {{{

Real radian_to_degree(Real r) {
    return r * 180.0 / PI;
}

Real degree_to_radian(Real d) {
    return d * PI / 180.0;
}

Point rotate(const Point &p, Real theta) {
    return p * polar((Real)1.0, theta);
}

Real cross(const Point& a, const Point& b) {
    return a.real() * b.imag() - a.imag() * b.real();
}

Real dot(const Point& a, const Point& b) {
    return a.real() * b.real() + a.imag() * b.imag();
}

// }}}


/**
* @brief 点p の直線l への射影を求める.
*/
Point projection(const Line& l, const Point& p) {
    Real A = dot(l.b - l.a, p - l.a),
         B = dot(l.a - l.b, p - l.b);
    return (A * l.b + B * l.a) / (A + B);
}

/**
* @brief 2直線の並行判定
*/
bool parallel(const Line& l1, const Line& l2) {
    return eq(cross(l1.a - l1.b, l2.a - l2.b), 0.0);
}

/**
* @brief 2直線の直行判定
*/
bool orthogonal(const Line& l1, const Line& l2) {
    return eq(dot(l1.a - l1.b, l2.a - l2.b), 0.0);
}


/**
* @brief 有向線分と点の位置関係
* @param[in] a, b, c: 線分a->b, 点c
* @return 線分a->b からみて, 点c がどこにあるか.
*/
const int COUNTER_CLOCKWISE = 1,
          CLOCKWISE = -1,
          ONLINE_BACK = 2,
          ONLINE_FRONT = -2,
          ON_SEGMENT = 0;
int ccw(const Point& a, Point b, Point c) {
    b = b - a, c = c - a;
    if (cross(b, c) > eps) return COUNTER_CLOCKWISE;
    if (cross(b, c) < -eps) return CLOCKWISE;
    if (dot(b, c) < 0) return ONLINE_BACK;
    if (norm(b) < norm(c)) return ONLINE_FRONT;
    return ON_SEGMENT;
}


// 交差 {{{

/**
* @brief 直線と点の交差判定
*/
bool intersected(const Line& l, const Point& p) {
    return abs(ccw(l.a, l.b, p)) != 1;
}

/**
* @brief 線分と点の交差判定
*/
bool intersected(const Segment& s, const Point& p) {
    return ccw(s.a, s.b, p) == 0;
}

/**
* @brief 直線と線分の交差判定
*/
bool intersected(const Line& l, const Segment& s) {
    return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps;
}

/**
* @brief 2つの線分の交差判定
*/
bool intersected(const Segment& s1, const Segment& s2) {
    return ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 and
           ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0;
}


/**
* @brief 2直線の交点
*/
Point crosspoint(const Line& l1, const Line& l2) {
    Real A = cross(l2.a - l1.a, l2.b - l1.a),
         B = cross(l2.b - l1.b, l2.a - l1.b);
    return (A * l1.b + B * l1.a) / (A + B);
}

// }}}


// 距離 {{{

/**
* @brief 直線と点の距離
*/
Real distance(const Line& l, const Point& p) {
    return abs(p - projection(l, p));
}

/**
* @brief 線分と点の距離
*/
Real distance(const Segment& s, const Point& p) {
    Point r = projection(s, p);
    if (intersected(s, r)) return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}

/**
* @brief 直線と線分の距離
*/
Real distance(const Line &l, const Segment &s) {
    if (intersected(l, s)) return 0;
    return min(distance(l, s.a), distance(l, s.b));
}

/**
* @brief 2つの線分の距離
*/
Real distance(const Segment& s1, const Segment& s2) {
    if (intersected(s1, s2)) return 0.0;
    return min({ distance(s1, s2.a), distance(s1, s2.b),
                 distance(s2, s1.a), distance(s2, s1.b) });
}

// }}}



// 円 {{{

struct Circle {
    Point p;
    Real r;
    Circle() {}
    Circle(const Point& p, Real r) : p(p), r(r) {}
};


/**
* @brief 2つの円の交点の数
*/
int intersected(Circle c1, Circle c2) {
    if (c1.r < c2.r) swap(c1, c2);
    Real d = abs(c1.p - c2.p);
    if (c1.r + c2.r < d) return 4;
    if (eq(c1.r + c2.r, d)) return 3;
    if (c1.r - c2.r < d) return 2;
    if (eq(c1.r - c2.r, d)) return 1;
    return 0;
}

/**
* @brief 円と直線の交点のペア
* @details 交差することを確認してから呼ぶこと.
*/
pair<Point,Point> crosspoint(const Circle& c, const Line& l) {
    Real h = distance(l, c.p);
    Point p = projection(l, c.p);
    if (eq(h, c.r)) return { p, p };
    Point u = l.a - l.b; u /= abs(u);
    Real d = sqrt(c.r * c.r - h * h);
    return { p + u * d, p - u * d };
}

/**
* @brief 2つの円の交点のペア
* @details 交差することを確認してから呼ぶこと.
*/
pair<Point,Point> crosspoint(const Circle& c1, const Circle& c2) {
    Real d = abs(c2.p - c1.p), t = arg(c2.p - c1.p);
    Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    return { c1.p + polar(c1.r, t + a),
             c1.p + polar(c1.r, t - a) };
}

/**
* @brief 点p, 円c に対し, pを通るcの接線を返す(c上の2点のペアで返す).
* @details 点p が円c の外側にあることを確認してから呼ぶこと.
*/
pair<Point,Point> tangent(const Point& p, const Circle& c) {
    return crosspoint(c, Circle(p, sqrt(norm(p - c.p) - c.r * c.r)));
};

/**
* @brief 2つの円に共通する接線を返す(最大4本).
* @details 点p が円c の外側にあることを確認してから呼ぶこと.
*/
vector<Line> common_tangent(const Circle& c1, const Circle& c2) {
    vector<Line> lines;
    Point u = c2.p - c1.p;
    Real d = abs(u);
    if (eq(d, 0.0)) return lines;
    u /= d;
    for (Real s : { -1, 1 }) {
        // s = -1: 同じ側に2つの円があるとき.
        // s =  1: 反対側に2つの円があるとき.
        Real h = (c1.r + s * c2.r) / d;
        if (eq(abs(h), 1.0)) {
            // 2つの円が接しているとき.
            lines.emplace_back(
                    c1.p + u * h * c1.r,
                    c1.p + u * h * c1.r + rotate(u, PI / 2.0));
        } else if (abs(h) < 1) {
            // 2本の接線が引けるとき.
            Real a = acos(h);
            lines.emplace_back(
                    c1.p + u * polar(c1.r, a),
                    c2.p - s * u * polar(c2.r, a));
            lines.emplace_back(
                    c1.p + u * polar(c1.r, -a),
                    c2.p - s * u * polar(c2.r, -a));
        }
    }
    return lines;
}

// }}}
