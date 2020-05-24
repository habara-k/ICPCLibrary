#include "../template.cpp"

/**
 * @brief
 * ax + b の最小値を管理
 * @author habara-k
 * @date 2020/05/24
 * @verify https://onlinejudge.u-aizu.ac.jp/services/review.html#rupc2014_whiteboard/4508173
 */

template<typename T>
struct ConvexHullTrick {

    /**
    * @brief コンストラクタ O(n)
    * @param[in] n: 追加する線分の上限
    */
    ConvexHullTrick(int n) : deq(n), s(0), t(0), prev(numeric_limits<T>::min()) {}

    /**
    * @brief 追加クエリ ならしO(1)
    * @param[in] a, b: ax + b を追加
    */
    void insert(T a, T b) {
        Line l = {a, b};
        while (t - s >= 2 and check(deq[t - 2], deq[t - 1], l)) --t;
        deq[t++] = l;
    }

    /**
    * @brief 取得クエリ ならしO(1)
    * @param[in] x: xにおける最小値を返す
    * @details x は昇順に呼ぶこと
    */
    T query(T x) {
        assert(prev <= x);
        prev = x;
        while (t - s >= 2 and f(deq[s], x) >= f(deq[s + 1], x)) ++s;
        return f(deq[s], x);
    }

private:
    struct Line {
        T a, b;
    };
    vector<Line> deq;
    int s, t;
    T prev;

    bool check(const Line& l1, const Line& l2, const Line& l3) const {
        return (l2.a - l1.a) * (l3.b - l2.b) >= (l2.b - l1.b) * (l3.a - l2.a);
    }
    T f(Line& l, T x) const {
        return l.a * x + l.b;
    }
};


