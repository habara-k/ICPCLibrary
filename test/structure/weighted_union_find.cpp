#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B"

#include "../../structure/weighted_union_find.cpp"

int main() {
    int N, M;
    cin >> N >> M;
    WeightedUnionFind<int> uf(N);
    while (M--) {
        int A, B, C, D;
        cin >> A >> B >> C;
        if (A == 0) {
            cin >> D;
            uf.merge(B, C, D);
        } else {
            if (uf.root(B) == uf.root(C)) {
                cout << uf.diff(B, C) << endl;
            } else {
                cout << "?" << endl;
            }
        }
    }
}
