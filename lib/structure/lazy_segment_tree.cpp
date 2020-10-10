#include "../template.cpp"

/**
* @brief 遅延セグメント木
* @author habara-k
* @date 2020/04/26
*/

template<typename M, typename OM = M>
struct LazySegmentTree {

    /**
    * @brief コンストラクタ. O(n)
    * @param[in] n 遅延セグ木のサイズ.
    * @param[in] f 要素モノイドの演算.
    * @param[in] g 要素に作用素を作用させる演算.
    * @param[in] h 作用素モノイドの演算.
    * @param[in] e 要素モノイドの単位元.
    * @param[in] oe 作用素モノイドの単位元.
    * @details 使い方
    *   e.g. Range Add Range Sum
    *   LazySegmentTree<int> segt(
    *            n,
    *            [](int a,int b){ return a+b; },
    *            [](int a,int b,int w){ return a + b*w; },
    *            [](int a,int b){ return a+b; },
    *            0, 0);
    *               // 全て単位元で初期化される.
    */
    LazySegmentTree(
            int n,
            const function<M(M,M)>& f,
            const function<M(M,OM,int)>& g,
            const function<OM(OM,OM)>& h,
            const M& e, const OM& oe
            ) : n(n), f(f), g(g), h(h), e(e), oe(oe) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2 * sz, e);
        lazy.assign(2 * sz, oe);
    }

    /**
    * @brief 全体に初期値を入れる. O(n)
    * @param[in] v 要素モノイドのvector. 初期化する.
    * @details 使い方
    *   segt.build(vector<int>(n, INF));
    */
    void build(const vector<M>& v) {
        assert(v.size() <= n);
        for (int i = 0; i < v.size(); ++i) {
            data[i + sz] = v[i];
        }
        for (int i = sz-1; i > 0; --i) {
            data[i] = f(data[2 * i], data[2 * i + 1]);
        }
    }

    /**
    * @brief 指定した区間に作用素x を作用させる. O(log n)
    * @param[in] l, r 区間[l, r) に作用させる.
    * @param[in] x 作用素モノイドの元.
    * @details 使い方
    *   e.g. Range Update
    *   int l, r, x; // 区間[l, r) をx に更新したい.
    *   segt.update(l, r, x);
    */
    void update(int a, int b, const OM& x) {
        update(a, b, x, 1, 0, sz);
    }

    /**
    * @brief 指定した区間に取得クエリを実行する. O(log n)
    * @param[in] l, r 区間[l, r) を取得する.
    * @return 取得した値.
    * @details 使い方
    *   e.g. Range Minimum
    *   int l, r; // 区間[l, r) のminを取得したい.
    *   cout << segt.query(l, r) << endl;
    */
    M query(int a, int b) {
        return query(a, b, 1, 0, sz);
    }

    /**
    * @brief 指定したindexの要素を取得. O(1)
    * @param[in] i 取得したい要素のindex
    * @return 取得した値.
    */
    M operator[](int i) {
        return query(i, i + 1);
    }

    /**
    * @brief vector みたいに出力.
    */
    friend ostream& operator<<(ostream& os, LazySegmentTree& s) {
        os << "[";
        for (int i = 0; i < s.n; ++i) {
            if (i) os << " ";
            os << s[i];
        }
        return os << "]";
    }

private:

    int n, sz;
    vector<M> data;
    vector<OM> lazy;
    const function<M(M,M)> f;
    const function<M(M,OM,int)> g;
    const function<OM(OM,OM)> h;
    const M e;
    const OM oe;

    void propagate(int k, int len) {
        if (lazy[k] == oe) return;
        if (k < sz) {
            lazy[2 * k    ] = h(lazy[2 * k    ], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
        }
        data[k] = g(data[k], lazy[k], len);
        lazy[k] = oe;
    }

    void update(int a, int b, const OM& x, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a or b <= l) return;
        else if (a <= l and r <= b) {
            lazy[k] = h(lazy[k], x);
            propagate(k, r - l);
        } else {
            update(a, b, x, 2 * k,     l, (l + r) >> 1);
            update(a, b, x, 2 * k + 1, (l + r) >> 1, r);
            data[k] = f(data[2 * k], data[2 * k + 1]);
        }
    }

    M query(int a, int b, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a or b <= l) return e;
        else if (a <= l and r <= b) return data[k];
        else return f(
                query(a, b, 2 * k,     l, (l + r) >> 1),
                query(a, b, 2 * k + 1, (l + r) >> 1, r));
    }
};

/* Usage
 *
 * Range Add Range Sum
 * LazySegmentTree<int> segt(
 *            n,
 *            [](int a,int b){ return a+b; },
 *            [](int a,int b,int w){ return a + b*w; },
 *            [](int a,int b){ return a+b; },
 *            0, 0);
 *
 * Range Update Range Sum
 * LazySegmentTree<int> segt(
 *            n,
 *            [](int a,int b){ return a+b; },
 *            [](int a,int b,int w){ return b; },
 *            [](int a,int b){ return b; },
 *            0, INF);
 *
 * Range Add Range min
 * LazySegmentTree<int> segt(
 *            n,
 *            [](int a,int b){ return min(a, b); },
 *            [](int a,int b,int w){ return a + b*w; },
 *            [](int a,int b){ return a+b; },
 *            INF, 0);
 *
 * Range Update Range min
 * LazySegmentTree<int> segt(
 *            n,
 *            [](int a,int b){ return min(a, b); },
 *            [](int a,int b,int w){ return b; },
 *            [](int a,int b){ return b; },
 *            INF, INF);
 *
 * Range Add Range max
 * LazySegmentTree<int> segt(
 *            n,
 *            [](int a,int b){ return max(a, b); },
 *            [](int a,int b,int w){ return a + b*w; },
 *            [](int a,int b){ return a+b; },
 *            -INF, 0);
 *
 * Range Update Range max
 * LazySegmentTree<int> segt(
 *            n,
 *            [](int a,int b){ return max(a, b); },
 *            [](int a,int b,int w){ return b; },
 *            [](int a,int b){ return b; },
 *            -INF, INF);
 */
