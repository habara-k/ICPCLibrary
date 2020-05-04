#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F"
#define ERROR "1e-5"

#include "../../../lib/geometry/2D_template.cpp"

int main()
{
    cout << fixed << setprecision(10);

    double px, py, cx, cy, r;
    cin >> px >> py >> cx >> cy >> r;

    Point p1, p2;
    tie(p1, p2) = tangent(
            Point(px, py),
            Circle(Point(cx, cy), r));

    if (p2 < p1) swap(p1, p2);
    cout << p1.real() << " " << p1.imag() << endl <<
            p2.real() << " " << p2.imag() << endl;

    return 0;
}
