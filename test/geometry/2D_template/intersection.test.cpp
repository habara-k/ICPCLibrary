#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B"

#include "../../../lib/geometry/2D_template.cpp"

int main()
{
    int q; cin >> q;
    while (q--) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Segment l1{Point{x1, y1}, Point{x2, y2}},
                l2{Point{x3, y3}, Point{x4, y4}};

        if (intersected(l1, l2)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
