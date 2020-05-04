#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C"

#include "../../../lib/geometry/polygon.cpp"

int main()
{
    int n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        double x, y; cin >> x >> y;
        p[i] = { x, y };
    }

    int q; cin >> q;
    while (q--) {
        double x, y; cin >> x >> y;
        cout << contains(p, Point{ x, y }) << endl;
    }

    return 0;
}
