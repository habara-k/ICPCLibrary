#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../../lib/structure/segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<int> seg(N, [](int a,int b){return min(a,b);},
            (1ll<<31)-1);
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0) seg.update(X, [&](int a){return Y;});
        else printf("%d\n", seg.query(X, Y + 1));
    }
}
