#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"

#include "../../lib/structure/union_find.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    while (Q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) uf.merge(x, y);
        else printf("%d\n", uf.root(x) == uf.root(y));
    }
}
