#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include "../../graph/scc.cpp"

int main() {
    int V, E, Q;
    cin >> V >> E;
    Graph<int> g(V);
    for (int i = 0; i < E; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back({a, b, 0});
    }
    SCC<int> scc(g);
    scc.build(g);
    vector<int> comp = scc.get_comp();
    cin >> Q;
    while (Q--) {
        int a, b; cin >> a >> b;
        puts(comp[a] == comp[b] ? "1" : "0");
    }
}
