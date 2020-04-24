#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A"

#include "../../lib/graph/hopcroft_karp.cpp"

int main() {
    int X, Y, E;
    cin >> X >> Y >> E;
    HopcroftKarp bm(X, Y);
    for(int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        bm.add_edge(a, b);
    }
    cout << bm.bipartite_matching() << endl;
}
