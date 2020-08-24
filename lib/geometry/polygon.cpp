#include "./2D_template.cpp"

/**
 * @brief
 * 多角形
 * @author habara-k
 * @date 2020/05/05
 */

using Polygon = vector<Point>;

/**
* @brief 符号付き面積を求める(反時計回りで正).
*/
Real area(const Polygon& U) {
    Real area = 0;
    for (int i = 0; i < U.size(); ++i) {
        area += cross(U[i], U[(i + 1) % U.size()]);
    }
    return area / 2.0;
}

/**
* @brief 凸判定
* @details 頂点は反時計回りで与えること.
*/
bool is_convex(const Polygon &U) {
    int n = U.size();
    for (int i = 0; i < n; ++i) {
        if (ccw(U[i], U[(i + 1) % n], U[(i + 2) % n]) == -1) return false;
    }
    return true;
}

/**
* @brief 点の内部判定
*/
const int OUT = 0,
          ON = 1,
          IN = 2;
int contains(const Polygon &U, const Point &p) {
    int in = 0;
    for (int i = 0; i < U.size(); ++i) {
        Point a = U[i] - p, b = U[(i + 1) % U.size()] - p;
        if (cross(a, b) == 0 and dot(a, b) <= 0) return ON;
        if (a.imag() > b.imag()) swap(a, b);
        if (a.imag() <= 0 and 0 < b.imag() and cross(a, b) < 0) in ^= 1;
    }
    return in ? IN : OUT;
}

/**
* @brief 凸包
* @param[in] includeOnLine: 凸包の辺上に位置する点も欲しいときにtrue にする.
* @return 凸包上の頂点(反時計回り).
*/
vector<Point> convex_hull(vector<Point>& p, bool includeOnLine = false) {
    int n = p.size(), k = 0;
    if (n <= 2) return p;
    sort(p.begin(), p.end(), [](Point& a, Point& b) {
            if (a.real() == b.real()) return a.imag() < b.imag();
            return a.real() < b.real();
            });
    vector<Point> ch(n * 2);
    const Real BOUND = includeOnLine ? -eps : eps;
    for (int i = 0; i < n; ch[k++] = p[i++]) {
        while (k >= 2 and cross(ch[k-1] - ch[k-2], p[i] - ch[k-1]) < BOUND) --k;
    }
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = p[i--]) {
        while (k >= t and cross(ch[k-1] - ch[k-2], p[i] - ch[k-1]) < BOUND) --k;
    }
    ch.resize(k-1);
    return ch;
}

/**
* @brief 凸多角形の直径
*/
Real convex_diameter(const Polygon &U) {
    int n = U.size();
    int is = 0, js = 0;
    for (int i = 1; i < n; ++i) {
        if (U[i].imag() > U[is].imag()) is = i;
        if (U[i].imag() < U[js].imag()) js = i;
    }
    Real maxnorm = norm(U[is] - U[js]);

    int i = is, j = js;
    do {
        if (cross(U[(i+1) % n] - U[i], U[(j+1) % n] - U[j]) >= 0) {
            j = (j+1) % n;
        } else {
            i = (i+1) % n;
        }
        if (norm(U[i] - U[j]) > maxnorm) {
            maxnorm = norm(U[i] - U[j]);
        }
    } while (i != is or j != js);
    return sqrt(maxnorm);
}

/**
* @brief 凸カット
* @param[in] U: カットしたい凸多角形
* @param[in] l: カットに用いる直線
* @return 直線l.a->l.b からみて反時計回り側の凸多角形を返す(入力と同じ回り順).
*/
Polygon convex_cut(const Polygon& U, const Line& l) {
    Polygon ret;
    for (int i = 0; i < U.size(); ++i) {
        Point now = U[i], nxt = U[(i + 1) % U.size()];
        if (ccw(l.a, l.b, now) != -1) ret.push_back(now);
        if (ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) == -1) {
            ret.push_back(crosspoint(Line{ now, nxt }, l));
        }
    }
    return ret;
}

