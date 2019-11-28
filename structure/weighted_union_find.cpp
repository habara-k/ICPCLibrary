#include "../template.cpp"

template<typename A>
struct WeightedUnionFind
{
    vector<int> par, sz;
    vector<A> data;     // data[x]: root から見たx の重み
    WeightedUnionFind(int n, A e=0) :
        par(n), sz(n, 1), data(n, e) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        int r = root(par[x]);
        data[x] += data[par[x]];
        return par[x] = r;
    }

    A weight(int x) {
        root(x);
        return data[x];
    }

    A diff(int x, int y) {
        // x から見たy の重み
        return data[y] - data[x];
    }

    void merge(int x, int y, A w) {
        // x から見たy の重みがw になるようにmerge
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y), w = -w;
        par[y] = x;
        sz[x] += sz[y];
        sz[y] = 0;
        data[y] = w;
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }
};
