#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E"
#define ERROR "1e-6"

#include "../../../lib/geometry/2D_template.cpp"

int main()
{
    cout << fixed << setprecision(10);

    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    Point p1, p2;
    tie(p1, p2) = crosspoint(
            Circle(Point(x1, y1), r1),
            Circle(Point(x2, y2), r2));

    if (p2 < p1) swap(p1, p2);
    cout << p1.real() << " " << p1.imag() << " " <<
            p2.real() << " " << p2.imag() << endl;

    return 0;
}
