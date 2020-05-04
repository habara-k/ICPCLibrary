#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A"

#include "../../../lib/geometry/polygon.cpp"

int main()
{
    cout << fixed << setprecision(1);

    int n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        double x, y; cin >> x >> y;
        p[i] = { x, y };
    }

    cout << abs(area(p)) << endl;

    return 0;
}
