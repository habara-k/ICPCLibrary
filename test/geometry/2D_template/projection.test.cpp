#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"
#define ERROR "1e-8"

#include "../../../lib/geometry/2D_template.cpp"

int main()
{
    cout << fixed << setprecision(10);

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Segment l{Point{x1, y1}, Point{x2, y2}};
    int q; cin >> q;
    while (q--) {
        double x, y; cin >> x >> y;
        Point p{x, y};
        Point c = projection(l, p);
        cout << c.real() << " " << c.imag() << endl;
    }

    return 0;
}
