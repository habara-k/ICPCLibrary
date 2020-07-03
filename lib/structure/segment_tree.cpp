#include "../template.cpp"

/**
* @brief セグメント木
* @author habara-k, Md
* @date 2020/06/17
*/

template<typename M>
struct SegmentTree {

    /**
    * @brief コンストラクタ. O(n)
    * @param[in] n セグ木のサイズ.
    * @param[in] f モノイドの演算(query).
    * @param[in] g モノイドの演算(update).
    * @param[in] e モノイドの単位元.
    * @details 使い方
    *   e.g. Update and Range Minimum
    *   SegmentTree<int> segt(
    *            n,
    *            [](int a,int b){ return min(a+b); },
    *            [](int a, int b){ return b; },
    *            INF);
    *               // 全て単位元で初期化される.
    */
    SegmentTree(
            int n,
            const function<M(M,M)>& f,
            const function<M(M, M)>& g,
            const M& e) : n(n), f(f), g(g), e(e) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2 * sz, e);
    }

    /**
    * @brief 全体に初期値を入れる. O(n)
    * @param[in] v 要素モノイドのvector. 初期化する.
    * @details 使い方
    *   segt.build(vector<int>(n, 0));
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
     * @brief 指定した位置に更新クエリを実行する O(log n)
     * @param[in] idx 位置idxに作用させる
     * @param[in] val 値xをg(data[idx+sz], val)で更新する
     */
    void update(int idx, M val) {
      idx += sz;
      data[idx] = g(data[idx], val);
      while(idx >>= 1) {
        data[idx] = f(data[2*idx], data[2*idx+1]);
      }
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
    M query(int a, int b) const {
        return query(a, b, 1, 0, sz);
    }

    /**
    * @brief 指定したindexの要素を取得. O(1)
    * @param[in] i 取得したい要素のindex
    * @return 取得した値.
    */
    M operator[](int k) const {
        return data[k + sz];
    }

    /**
    * @brief vector みたいに出力.
    */
    friend ostream& operator<<(ostream& os, SegmentTree& s) {
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
    const function<M(M,M)> f, g;
    const M e;

    M query(int a, int b, int k, int l, int r) const {
        if (r <= a || b <= l) {
            return e;
        } else if (a <= l && r <= b) {
            return data[k];
        } else {
            return f(query(a,b,2*k,  l,(l+r)/2),
                     query(a,b,2*k+1,(l+r)/2,r));
        }
    }
};
