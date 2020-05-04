#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C"
#define ERROR "1e-5"

#include "../../../lib/geometry/polygon.cpp"

int main()
{
    cout << fixed << setprecision(10);

    int n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        double x, y; cin >> x >> y;
        p[i] = { x, y };
    }

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        Point p1 = { x1, y1 }, p2 = { x2, y2 };
        Polygon c = convex_cut(p, Line{ p1, p2 });
        cout << area(convex_cut(p, Line{ p1, p2 })) << endl;
    }

    return 0;
}
