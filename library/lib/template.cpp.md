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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: lib/template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-06 01:41:24+09:00




## Required by

* :heavy_check_mark: <a href="geometry/2D_template.cpp.html"> <small>(lib/geometry/2D_template.cpp)</small></a>
* :warning: <a href="geometry/3D_template.cpp.html">lib/geometry/3D_template.cpp</a>
* :heavy_check_mark: <a href="geometry/polygon.cpp.html"> <small>(lib/geometry/polygon.cpp)</small></a>
* :heavy_check_mark: <a href="graph/bfs01.cpp.html"> <small>(lib/graph/bfs01.cpp)</small></a>
* :heavy_check_mark: <a href="graph/dijkstra.cpp.html"> <small>(lib/graph/dijkstra.cpp)</small></a>
* :heavy_check_mark: <a href="graph/dinic.cpp.html"> <small>(lib/graph/dinic.cpp)</small></a>
* :heavy_check_mark: <a href="graph/heavy_light_decomposition.cpp.html">HL分解 <small>(lib/graph/heavy_light_decomposition.cpp)</small></a>
* :heavy_check_mark: <a href="graph/hopcroft_karp.cpp.html"> <small>(lib/graph/hopcroft_karp.cpp)</small></a>
* :heavy_check_mark: <a href="graph/kruskal.cpp.html"> <small>(lib/graph/kruskal.cpp)</small></a>
* :heavy_check_mark: <a href="graph/lowest_common_ancestor.cpp.html"> <small>(lib/graph/lowest_common_ancestor.cpp)</small></a>
* :warning: <a href="graph/lowlink.cpp.html">lib/graph/lowlink.cpp</a>
* :warning: <a href="graph/maximum_clique.cpp.html">lib/graph/maximum_clique.cpp</a>
* :heavy_check_mark: <a href="graph/primal_dual.cpp.html">lib/graph/primal_dual.cpp</a>
* :heavy_check_mark: <a href="graph/re_rooting.cpp.html"> <small>(lib/graph/re_rooting.cpp)</small></a>
* :heavy_check_mark: <a href="graph/scc.cpp.html"> <small>(lib/graph/scc.cpp)</small></a>
* :heavy_check_mark: <a href="graph/template.cpp.html">lib/graph/template.cpp</a>
* :warning: <a href="graph/topological_sort.cpp.html">lib/graph/topological_sort.cpp</a>
* :warning: <a href="graph/twoconnectedcomponents.cpp.html">lib/graph/twoconnectedcomponents.cpp</a>
* :heavy_check_mark: <a href="graph/warshall_floyd.cpp.html"> <small>(lib/graph/warshall_floyd.cpp)</small></a>
* :heavy_check_mark: <a href="number/combination.cpp.html">lib/number/combination.cpp</a>
* :heavy_check_mark: <a href="number/crt.cpp.html"> <small>(lib/number/crt.cpp)</small></a>
* :heavy_check_mark: <a href="number/extended_gcd.cpp.html">lib/number/extended_gcd.cpp</a>
* :warning: <a href="number/fft.cpp.html">FFT <small>(lib/number/fft.cpp)</small></a>
* :heavy_check_mark: <a href="number/gauss_jordan.cpp.html"> <small>(lib/number/gauss_jordan.cpp)</small></a>
* :heavy_check_mark: <a href="number/matrix.cpp.html"> <small>(lib/number/matrix.cpp)</small></a>
* :heavy_check_mark: <a href="number/mod.cpp.html"> <small>(lib/number/mod.cpp)</small></a>
* :warning: <a href="number/ntt.cpp.html"> <small>(lib/number/ntt.cpp)</small></a>
* :warning: <a href="others/LIS.cpp.html">lib/others/LIS.cpp</a>
* :warning: <a href="others/dice.cpp.html">lib/others/dice.cpp</a>
* :warning: <a href="others/inversion.cpp.html">lib/others/inversion.cpp</a>
* :warning: <a href="string/manacher.cpp.html">文字列の各位置を中心とする回文長をO(|S|)で求める <small>(lib/string/manacher.cpp)</small></a>
* :heavy_check_mark: <a href="string/rolling_hash.cpp.html">文字列のハッシュ化 <small>(lib/string/rolling_hash.cpp)</small></a>
* :heavy_check_mark: <a href="string/rolling_hash_2D.cpp.html">2次元文字列のハッシュ化 <small>(lib/string/rolling_hash_2D.cpp)</small></a>
* :warning: <a href="string/z_algorithm.cpp.html">lib/string/z_algorithm.cpp</a>
* :heavy_check_mark: <a href="structure/binary_indexed_tree.cpp.html">lib/structure/binary_indexed_tree.cpp</a>
* :warning: <a href="structure/bit_range_add.cpp.html">lib/structure/bit_range_add.cpp</a>
* :warning: <a href="structure/convex_hull_trick.cpp.html"> <small>(lib/structure/convex_hull_trick.cpp)</small></a>
* :heavy_check_mark: <a href="structure/lazy_segment_rbst.cpp.html"> <small>(lib/structure/lazy_segment_rbst.cpp)</small></a>
* :heavy_check_mark: <a href="structure/lazy_segment_tree.cpp.html">遅延セグメント木 <small>(lib/structure/lazy_segment_tree.cpp)</small></a>
* :warning: <a href="structure/multi_set.cpp.html"> <small>(lib/structure/multi_set.cpp)</small></a>
* :heavy_check_mark: <a href="structure/persistent_segment_tree.cpp.html">完全永続セグメント木 <small>(lib/structure/persistent_segment_tree.cpp)</small></a>
* :warning: <a href="structure/randomized_binary_search_tree.cpp.html"> <small>(lib/structure/randomized_binary_search_tree.cpp)</small></a>
* :heavy_check_mark: <a href="structure/segment_rbst.cpp.html"> <small>(lib/structure/segment_rbst.cpp)</small></a>
* :heavy_check_mark: <a href="structure/segment_tree.cpp.html">セグメント木 <small>(lib/structure/segment_tree.cpp)</small></a>
* :heavy_check_mark: <a href="structure/union_find.cpp.html">lib/structure/union_find.cpp</a>
* :heavy_check_mark: <a href="structure/weighted_union_find.cpp.html">lib/structure/weighted_union_find.cpp</a>
* :warning: <a href="../test/graph/maximum_clique.cpp.html">test/graph/maximum_clique.cpp</a>
* :warning: <a href="../test/graph/topological_sort.cpp.html">test/graph/topological_sort.cpp</a>
* :warning: <a href="../test/others/LIS.cpp.html">test/others/LIS.cpp</a>
* :warning: <a href="../test/others/dice.cpp.html">test/others/dice.cpp</a>
* :warning: <a href="../test/others/inversion.cpp.html">test/others/inversion.cpp</a>
* :warning: <a href="../test/string/z_algorithm.cpp.html">test/string/z_algorithm.cpp</a>
* :warning: <a href="../test/structure/bit_range_add.cpp.html">test/structure/bit_range_add.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/circle_crosspoint.test.cpp.html">test/geometry/2D_template/circle_crosspoint.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/circle_intersection.test.cpp.html">test/geometry/2D_template/circle_intersection.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/circle_line_crosspoint.test.cpp.html">test/geometry/2D_template/circle_line_crosspoint.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/common_tangent.test.cpp.html">test/geometry/2D_template/common_tangent.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/counter_clockwise.test.cpp.html">test/geometry/2D_template/counter_clockwise.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/crosspoint.test.cpp.html">test/geometry/2D_template/crosspoint.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/distance.test.cpp.html">test/geometry/2D_template/distance.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/intersection.test.cpp.html">test/geometry/2D_template/intersection.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/parallel_orthogonal.test.cpp.html">test/geometry/2D_template/parallel_orthogonal.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/projection.test.cpp.html">test/geometry/2D_template/projection.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/tangent.test.cpp.html">test/geometry/2D_template/tangent.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/polygon/area.test.cpp.html">test/geometry/polygon/area.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/polygon/contains.test.cpp.html">test/geometry/polygon/contains.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/polygon/convex_cut.test.cpp.html">test/geometry/polygon/convex_cut.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/polygon/convex_hull.test.cpp.html">test/geometry/polygon/convex_hull.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/polygon/diameter.test.cpp.html">test/geometry/polygon/diameter.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/polygon/is_convex.test.cpp.html">test/geometry/polygon/is_convex.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/bfs01.test.cpp.html">test/graph/bfs01.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/dijkstra.test.cpp.html">test/graph/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/dinic.test.cpp.html">test/graph/dinic.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/heavy_light_decomposition/hld.test.cpp.html">test/graph/heavy_light_decomposition/hld.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/heavy_light_decomposition/lca.test.cpp.html">test/graph/heavy_light_decomposition/lca.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/hopcroft_karp.test.cpp.html">test/graph/hopcroft_karp.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/kruskal.test.cpp.html">test/graph/kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/lowest_common_ancestor.test.cpp.html">test/graph/lowest_common_ancestor.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/primal_dual.test.cpp.html">test/graph/primal_dual.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/re_rooting.test.cpp.html">test/graph/re_rooting.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/scc.test.cpp.html">test/graph/scc.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/warshall_floyd.test.cpp.html">test/graph/warshall_floyd.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/Bell.test.cpp.html">test/number/Bell.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/C.test.cpp.html">test/number/C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/Partition1.test.cpp.html">test/number/Partition1.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/Partition2.test.cpp.html">test/number/Partition2.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/Stirling.test.cpp.html">test/number/Stirling.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/crt.test.cpp.html">test/number/crt.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/extended_gcd.test.cpp.html">test/number/extended_gcd.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/gauss_jordan.test.cpp.html">test/number/gauss_jordan.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/matrix.test.cpp.html">test/number/matrix.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/string/rolling_hash.test.cpp.html">test/string/rolling_hash.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/string/rolling_hash_2D.test.cpp.html">test/string/rolling_hash_2D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/binary_indexed_tree.test.cpp.html">test/structure/binary_indexed_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_segment_rbst.test.cpp.html">test/structure/lazy_segment_rbst.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_segment_tree.test.cpp.html">test/structure/lazy_segment_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/persistent_segment_tree.test.cpp.html">test/structure/persistent_segment_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/segment_rbst.test.cpp.html">test/structure/segment_rbst.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/segment_tree.test.cpp.html">test/structure/segment_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/union_find.test.cpp.html">test/structure/union_find.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/weighted_union_find.test.cpp.html">test/structure/weighted_union_find.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef TEMPLATE
#define TEMPLATE

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

#endif

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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

