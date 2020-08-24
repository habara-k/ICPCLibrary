---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: lib/geometry/3D_template.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7096d029078708cdbb96f2303d66dee8">lib/geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/geometry/3D_template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-24 14:09:03+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

using Real = double;
const Real PI = acos(-1);

struct Point3D {
    double x, y, z;
    Point3D() {}
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
    Point3D operator+(const Point3D& b) const {
        return Point3D(x + b.x, y + b.y, z + b.z);
    }
    Point3D operator-(const Point3D& b) const {
        return Point3D(x - b.x, y - b.y, z - b.z);
    }
    friend double norm(const Point3D& p) {
        return p.x * p.x + p.y * p.y + p.z * p.z;
    };
    friend double abs(const Point3D& p) { return sqrt(norm(p)); }

    friend ostream &operator<<(ostream &os, Point3D &p) {
        return os << "(" << p.x << "," << p.y << "," << p.z << ")";
    }
    friend istream &operator>>(istream &is, Point3D &p) {
        return is >> p.x >> p.y >> p.z;
    }
};

struct Segment3D {
    Point3D a, b;
    Segment3D() {}
    Segment3D(const Point3D& a, const Point3D& b) : a(a), b(b) {}
    friend ostream &operator<<(ostream &os, Segment3D &l) {
        return os << "[" << l.a << "," << l.b << "]";
    }
    friend istream &operator>>(istream &is, Segment3D &l) {
        return is >> l.a >> l.b;
    }
};

inline bool eq(Real a, Real b) { return abs(b - a) < eps; }

double dot(const Point3D &a, const Point3D &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3D cross(const Point3D &a, const Point3D &b) {
    double x = a.y * b.z - a.z * b.y,
           y = a.z * b.x - a.x * b.z,
           z = a.x * b.y - a.y * b.x;
    return Point3D(x, y, z);
}

bool parallel(
        const Point3D &a1, const Point3D &a2,
        const Point3D &b1, const Point3D &b2) {
    return eq(abs(cross(a1-b1, a2-b2)), 0.);
}

bool parallel(const Segment3D& l1, const Segment3D& l2) {
    return parallel(l1.a, l1.b, l2.a, l2.b);
}

double distance(const Segment3D &l, const Point3D &p) {
    if (dot(l.b - l.a, p - l.a) < eps) return abs(p - l.a);
    if (dot(l.a - l.b, p - l.b) < eps) return abs(p - l.b);
    return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/template.cpp"



#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

template<class T>
ostream &operator<<(ostream &os, const vector <T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<class T, class U>
ostream &operator<<(ostream &os, const pair <T, U> &p) {
    return os << "(" << p.first << " " << p.second << ")";
}

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const ld eps = 1e-9;

/*
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    // ifstream in("in.txt");
    // cin.rdbuf(in.rdbuf());

    return 0;
}
*/


#line 2 "lib/geometry/3D_template.cpp"

using Real = double;
const Real PI = acos(-1);

struct Point3D {
    double x, y, z;
    Point3D() {}
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
    Point3D operator+(const Point3D& b) const {
        return Point3D(x + b.x, y + b.y, z + b.z);
    }
    Point3D operator-(const Point3D& b) const {
        return Point3D(x - b.x, y - b.y, z - b.z);
    }
    friend double norm(const Point3D& p) {
        return p.x * p.x + p.y * p.y + p.z * p.z;
    };
    friend double abs(const Point3D& p) { return sqrt(norm(p)); }

    friend ostream &operator<<(ostream &os, Point3D &p) {
        return os << "(" << p.x << "," << p.y << "," << p.z << ")";
    }
    friend istream &operator>>(istream &is, Point3D &p) {
        return is >> p.x >> p.y >> p.z;
    }
};

struct Segment3D {
    Point3D a, b;
    Segment3D() {}
    Segment3D(const Point3D& a, const Point3D& b) : a(a), b(b) {}
    friend ostream &operator<<(ostream &os, Segment3D &l) {
        return os << "[" << l.a << "," << l.b << "]";
    }
    friend istream &operator>>(istream &is, Segment3D &l) {
        return is >> l.a >> l.b;
    }
};

inline bool eq(Real a, Real b) { return abs(b - a) < eps; }

double dot(const Point3D &a, const Point3D &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3D cross(const Point3D &a, const Point3D &b) {
    double x = a.y * b.z - a.z * b.y,
           y = a.z * b.x - a.x * b.z,
           z = a.x * b.y - a.y * b.x;
    return Point3D(x, y, z);
}

bool parallel(
        const Point3D &a1, const Point3D &a2,
        const Point3D &b1, const Point3D &b2) {
    return eq(abs(cross(a1-b1, a2-b2)), 0.);
}

bool parallel(const Segment3D& l1, const Segment3D& l2) {
    return parallel(l1.a, l1.b, l2.a, l2.b);
}

double distance(const Segment3D &l, const Point3D &p) {
    if (dot(l.b - l.a, p - l.a) < eps) return abs(p - l.a);
    if (dot(l.a - l.b, p - l.b) < eps) return abs(p - l.b);
    return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);
}


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

