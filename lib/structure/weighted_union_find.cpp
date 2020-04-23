#include "../template.cpp"

template<typename A>
struct WeightedUnionFind
{
    vector<int> par, sz;
    vector<A> data;     // data[x]: diff from root to x
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
        // diff from x to y
        return data[y] - data[x];
    }

    void merge(int x, int y, A w) {
        // merge so that "diff from x to y" will be w.
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
