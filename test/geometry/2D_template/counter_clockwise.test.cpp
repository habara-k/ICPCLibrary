#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"

#include "../../../lib/geometry/2D_template.cpp"

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Segment l{Point{x1, y1}, Point{x2, y2}};
    int q; cin >> q;
    while (q--) {
        double x, y; cin >> x >> y;
        Point p{x, y};

        int c = ccw(l.a, l.b, p);
        if (c == COUNTER_CLOCKWISE) {
            cout << "COUNTER_CLOCKWISE" << endl;
        }
        if (c == CLOCKWISE) {
            cout << "CLOCKWISE" << endl;
        }
        if (c == ONLINE_BACK) {
            cout << "ONLINE_BACK" << endl;
        }
        if (c == ONLINE_FRONT) {
            cout << "ONLINE_FRONT" << endl;
        }
        if (c == ON_SEGMENT) {
            cout << "ON_SEGMENT" << endl;
        }
    }

    return 0;
}
