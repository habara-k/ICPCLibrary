#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821"

#include "../../lib/tree/tree_hash.cpp"
#include "../../lib/structure/union_find.cpp"

int main() {
    int n1, m1; cin >> n1 >> m1;
    vector<vector<int>> g1(n1);
    UnionFind uf(n1);
    REP(i, m1) {
        int u, v; cin >> u >> v; --u, --v;
        g1[u].emplace_back(v);
        g1[v].emplace_back(u);
        uf.merge(u, v);
    }
    int n2; cin >> n2;
    vector<vector<int>> g2(n2);
    REP(i, n2-1) {
        int u, v; cin >> u >> v; --u, --v;
        g2[u].emplace_back(v);
        g2[v].emplace_back(u);
    }

    vector<int> roots;
    for (int i = 0; i < n1; ++i) if (uf.root(i) == i) roots.emplace_back(i);

    map<int,map<int,int>> ord;
    for (int i = 0; i < n1; ++i) {
        ord[uf.root(i)][i] = -1;
    }

    map<int,vector<vector<int>>> g;
    for (auto& tp : ord) {
        int cnt = 0;
        for (auto& p : tp.second) {
            p.second = cnt++;
        }
        g[tp.first].resize(cnt);
    }

    for (int u = 0; u < n1; ++u) {
        int r = uf.root(u);
        for (int v : g1[u]) {
            g[r][ord[r][u]].emplace_back(ord[r][v]);
        }
    }

    int ans = 0;
    auto hash = TreeHash(g2).get();
    for (auto &tp : g) {
        auto h = TreeHash(tp.second).get();
        ans += h == hash;
    }

    cout << ans << endl;
}

