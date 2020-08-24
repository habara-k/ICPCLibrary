#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include "../../lib/graph/scc.cpp"

int main() {
    int V, E, Q;
    cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }

    StronglyConnectedComponents scc(G);
    scc.build();

    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << (scc.comp[a] == scc.comp[b] ? "1" : "0") << endl;
    }
}
