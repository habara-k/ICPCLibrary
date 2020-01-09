#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

#include "../../graph/topological_sort.cpp"

int main() {
    int V, E; cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; ++i) {
        int s, t; cin >> s >> t;
        G[s].push_back(t);
    }
    vector<int> ord;
    topological_sort(G, ord);
    for (auto v : ord) {
        cout << v << endl;
    }
}
