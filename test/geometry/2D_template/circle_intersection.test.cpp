#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A"

#include "../../../lib/geometry/2D_template.cpp"

int main()
{
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    cout << intersected(
                Circle(Point(x1, y1), r1),
                Circle(Point(x2, y2), r2)) << endl;
    return 0;
}
