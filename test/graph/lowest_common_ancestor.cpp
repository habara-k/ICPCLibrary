#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../../graph/lowest_common_ancestor.cpp"

int main() {
    int N, Q;
    cin >> N;
    vector<vector<int>> g(N);
    for(int i = 0; i < N; i++) {
        int k; cin >> k;
        while (k--) {
            int c; cin >> c;
            g[i].push_back(c);
        }
    }
    LCA lca(g);
    cin >> Q;
    while (Q--) {
        int x, y; cin >> x >> y;
        printf("%d\n", lca.query(x, y));
    }
}
