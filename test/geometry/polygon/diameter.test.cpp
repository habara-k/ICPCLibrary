#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B"
#define ERROR "1e-6"

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

    cout << convex_diameter(p) << endl;

    return 0;
}
