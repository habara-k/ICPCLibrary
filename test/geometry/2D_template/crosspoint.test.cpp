#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C"
#define ERROR "1e-8"

#include "../../../lib/geometry/2D_template.cpp"

int main()
{
    cout << fixed << setprecision(10);

    int q; cin >> q;
    while (q--) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Segment l1{Point{x1, y1}, Point{x2, y2}},
                l2{Point{x3, y3}, Point{x4, y4}};

        Point c = crosspoint(l1, l2);
        cout << c.real() << " " << c.imag() << endl;
    }

    return 0;
}
