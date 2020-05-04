#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A"

#include "../../../lib/geometry/polygon.cpp"

int main()
{
    cout << fixed << setprecision(0);

    int n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        double x, y; cin >> x >> y;
        p[i] = { x, y };
    }

    p = convex_hull(p, true);
    int m = p.size();

    Point s = p[0];
    int sid = 0;
    for (int i = 1; i < m; ++i) {
        if (p[i].imag() < s.imag() or
            (p[i].imag() == s.imag() and p[i].real() < s.real())) {
            s = p[i]; sid = i;
        }
    }

    cout << m << endl;
    for (int i = 0; i < m; ++i) {
        Point& q = p[(i + sid) % m];
        cout << q.real() << " " << q.imag() << endl;
    }

    return 0;
}
