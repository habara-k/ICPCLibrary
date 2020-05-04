#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270"

#include "../../lib/structure/persistent_segment_tree.cpp"
#include "../../lib/graph/lowest_common_ancestor.cpp"

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // compress
    map<int,int> comp, comp_inv;
    for (auto X : x) comp[X] = -1;
    int comp_size = 0;
    for (auto &p : comp) {
        p.second = comp_size++;
    }
    for (auto p : comp) {
        comp_inv[p.second] = p.first;
    }

    // lca
    auto lca = LCA(G);

    // persistent segtree
    PersistentSegmentTree<int> segt(
            comp.size(), [](int a,int b){ return a+b; }, 0);

    map<int,PersistentSegmentTree<int>::Node*> root;
    vector<int> par(N);

    function<void(int,int)> dfs = [&](int v, int p) {
        par[v] = p;
        root[v] = segt.update(root[p],
                comp[x[v]], [](int a){ return a+1; });
        for (int u : G[v]) {
            if (u != p) dfs(u, v);
        }
    };

    root[-1] = segt.build();
    dfs(0, -1);

    for (int i = 0; i < Q; ++i)
    {
        int v, w, l; cin >> v >> w >> l; --v, --w;

        // search x s.t. there are more than l numbers less than or equal to x

        int u = lca.query(v, w);

        auto check = [&](int m) {
            int nv = segt.query(root[v], 0, m+1),
                nw = segt.query(root[w], 0, m+1),
                nu = segt.query(root[u], 0, m+1),
                np = segt.query(root[par[u]], 0, m+1);

            return nv + nw - nu - np >= l;
        };

        int ng = -1, ok = comp.size()-1;
        while (abs(ok - ng) > 1) {
            int mid = (ng + ok) / 2;
            (check(mid) ? ok : ng) = mid;
        }

        cout << comp_inv[ok] << endl;
    }

    return 0;
}
