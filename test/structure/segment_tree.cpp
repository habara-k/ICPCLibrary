#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../../structure/segment_tree.cpp"

main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<int> seg(N);
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0) seg.update(X, Y);
        else printf("%d\n", seg.query(X, Y + 1));
    }
}
