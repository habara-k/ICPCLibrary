#include "../template.cpp"

template<typename M>
struct SegmentTree {
    int sz;
    vector<M> data;

    // RMQ
    const M e = inf<M>();
    const function<M(M,M)> f = [](M a,M b){ return min(a,b); };

    SegmentTree(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2*sz, e);
    }

    void update(int k, M &x) {
        k += sz;
        data[k] = x;
        while (k >>= 1) {
            data[k] = f(data[2*k], data[2*k+1]);
        }
    }

    M query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return e;
        } else if (a <= l && r <= b) {
            return data[k];
        } else {
            return f(query(a,b,2*k,  l,(l+r)/2),
                     query(a,b,2*k+1,(l+r)/2,r));
        }
    }

    M query(int a, int b) {
        // return f[a,b)
        return query(a, b, 1, 0, sz);
    }

    M operator[](int k) {
        return data[k + sz];
    }
};
