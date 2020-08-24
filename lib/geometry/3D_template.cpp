#include "../template.cpp"

using Real = double;
const Real PI = acos(-1);

struct Point3D {
    double x, y, z;
    Point3D() {}
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
    Point3D operator+(const Point3D& b) const {
        return Point3D(x + b.x, y + b.y, z + b.z);
    }
    Point3D operator-(const Point3D& b) const {
        return Point3D(x - b.x, y - b.y, z - b.z);
    }
    friend double norm(const Point3D& p) {
        return p.x * p.x + p.y * p.y + p.z * p.z;
    };
    friend double abs(const Point3D& p) { return sqrt(norm(p)); }

    friend ostream &operator<<(ostream &os, Point3D &p) {
        return os << "(" << p.x << "," << p.y << "," << p.z << ")";
    }
    friend istream &operator>>(istream &is, Point3D &p) {
        return is >> p.x >> p.y >> p.z;
    }
};

struct Segment3D {
    Point3D a, b;
    Segment3D() {}
    Segment3D(const Point3D& a, const Point3D& b) : a(a), b(b) {}
    friend ostream &operator<<(ostream &os, Segment3D &l) {
        return os << "[" << l.a << "," << l.b << "]";
    }
    friend istream &operator>>(istream &is, Segment3D &l) {
        return is >> l.a >> l.b;
    }
};

inline bool eq(Real a, Real b) { return abs(b - a) < eps; }

double dot(const Point3D &a, const Point3D &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3D cross(const Point3D &a, const Point3D &b) {
    double x = a.y * b.z - a.z * b.y,
           y = a.z * b.x - a.x * b.z,
           z = a.x * b.y - a.y * b.x;
    return Point3D(x, y, z);
}

bool parallel(
        const Point3D &a1, const Point3D &a2,
        const Point3D &b1, const Point3D &b2) {
    return eq(abs(cross(a1-b1, a2-b2)), 0.);
}

bool parallel(const Segment3D& l1, const Segment3D& l2) {
    return parallel(l1.a, l1.b, l2.a, l2.b);
}

double distance(const Segment3D &l, const Point3D &p) {
    if (dot(l.b - l.a, p - l.a) < eps) return abs(p - l.a);
    if (dot(l.a - l.b, p - l.b) < eps) return abs(p - l.b);
    return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);
}

