---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning:  <small>(lib/structure/multi_set.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c4d905b3311a5371af1ce28a5d3ead13">lib/structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/structure/multi_set.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-06 01:41:24+09:00




## Depends on

* :warning: <a href="randomized_binary_search_tree.cpp.html"> <small>(lib/structure/randomized_binary_search_tree.cpp)</small></a>
* :question: <a href="../template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "./randomized_binary_search_tree.cpp"

/**
 * @brief
 * 常に昇順にソートされた配列（マルチセット）
 * 任意箇所の要素の更新・取得・挿入・削除をO(log n)で行う.
 * 昇順を保ったまま値の挿入・削除をO(log n)で行う.
 * @author habara-k
 * @date 2020/05/05
 * @details verify: https://arc033.contest.atcoder.jp/tasks/arc033_3
 */

template<typename T>
struct MultiSet : RandomizedBinarySearchTree<T> {
    using RBST = RandomizedBinarySearchTree<T>;
    using Node = typename RBST::Node;

    MultiSet() : RBST() {}

    /**
    * @brief 値の挿入を行う. O(log n)
    * @param[in] key: 要素の値
    */
    void insert_key(const T& key) {
        RBST::insert(lower_bound(this->root, key), key);
    }

    /**
    * @brief 値の削除を行う. O(log n)
    * @param[in] key: 要素の値
    */
    void erase_key(const T& key) {
        if (count(this->root, key) == 0) return;
        RBST::erase(lower_bound(this->root, key));
    }

private:
    int lower_bound(Node *t, const T& key) {
        if (!t) return 0;
        if (key <= t->data) return lower_bound(t->lch, key);
        return lower_bound(t->rch, key) + RBST::size(t->lch) + 1;
    }

    int upper_bound(Node *t, const T& key) {
        if (!t) return 0;
        if (key < t->data) return upper_bound(t->lch, key);
        return upper_bound(t->rch, key) + RBST::size(t->lch) + 1;
    }

    int count(Node *t, const T& key) {
        return upper_bound(t, key) - lower_bound(t, key);
    }
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/template.cpp"



#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

template<class T>
ostream &operator<<(ostream &os, const vector <T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<class T, class U>
ostream &operator<<(ostream &os, const pair <T, U> &p) {
    return os << "(" << p.first << " " << p.second << ")";
}

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const ld eps = 1e-9;

/*
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    // ifstream in("in.txt");
    // cin.rdbuf(in.rdbuf());

    return 0;
}
*/


#line 2 "lib/structure/randomized_binary_search_tree.cpp"

/**
 * @brief
 * 列を管理する平衡二分木
 * 任意箇所の要素の更新・取得・挿入・削除をO(log n)で行う.
 * @author habara-k
 * @date 2020/05/05
 */

template<typename T>
struct RandomizedBinarySearchTree {

    struct Node {
        Node *lch, *rch;
        int sz;
        T data;
        Node(const T& data) :
                lch(nullptr), rch(nullptr), sz(1),
                data(data) {}
    };

    RandomizedBinarySearchTree() : root(nullptr) {}

    /**
    * @brief 配列で初期化する. O(n)
    */
    void build(const vector<T>& v) { root = build(v, 0, v.size()); }

    /**
    * @brief 木のサイズを返す. O(1)
    */
    inline int size() {
        return size(root);
    }

    /**
    * @brief 要素の更新を行う. O(log n)
    * @param[in] i: 要素のindex
    * @param[in] q: x をq(x) で更新する.
    */
    template<class UpdateQuery>
    void update(int i, const UpdateQuery& q) {
        auto p0 = split(root, i);
        auto p1 = split(p0.second, 1);
        p1.first->data = q(p1.first->data);
        root = merge(p0.first, merge(p1.first, p1.second));
    }

    /**
    * @brief 要素の取得を行う. O(log n)
    * @param[in] i: 取得したい要素のindex
    * @return 取得した値
    */
    T operator[](int i) {
        auto p0 = split(root, i);
        auto p1 = split(p0.second, 1);
        T ret = p1.first->data;
        root = merge(p0.first, merge(p1.first, p1.second));
        return ret;
    }

    /**
    * @brief 要素の挿入を行う. O(log n)
    * @param[in] i: 挿入したいindex
    * @param[in] data: 挿入したい値
    */
    void insert(int i, const T& data) {
        auto q = _new(data);
        auto p = split(root, i);
        root = merge(merge(p.first, q), p.second);
    }

    /**
    * @brief 要素の削除を行う. O(log n)
    * @param[in] i: 挿入したいindex
    */
    T erase(int i) {
        auto p = split(root, i);
        auto q = split(p.second, 1);
        T ret = q.first->data;
        root = merge(p.first, q.second);
        return ret;
    }

    /**
    * @brief vector みたいに出力.
    */
    friend ostream& operator<<(ostream& os,
                               RandomizedBinarySearchTree& tr) {
        os << "[";
        for (int i = 0; i < tr.size(); ++i) {
            if (i) os << " ";
            os << tr[i];
        }
        return os << "]";
    }

protected:
    Node* root;

    inline int size(Node* t) const { return t ? t->sz : 0; }

    Node* merge(Node *l, Node *r) {
        if (!l) return r;
        if (!r) return l;
        if (xor128() % (size(l) + size(r)) < size(l)) {
            l->rch = merge(l->rch, r);
            return modify(l);
        } else {
            r->lch = merge(l, r->lch);
            return modify(r);
        }
    }

    pair<Node*, Node*> split(Node* t, int k) {
        if (!t) return {t, t};
        if (k > size(t->lch)) {
            auto p = split(t->rch, k-size(t->lch)-1);
            t->rch = p.first;
            return {modify(t), p.second};
        } else {
            auto p = split(t->lch, k);
            t->lch = p.second;
            return {p.first, modify(t)};
        }
    }

private:
    inline int xor128() {
        static int x = 123456789;
        static int y = 362436069;
        static int z = 521288629;
        static int w = 88675123;
        int t;

        t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }

    Node* build(const vector<T>& v, int l, int r) {
        if (l + 1 >= r) return _new(v[l]);
        return merge(build(v, l, (l + r) >> 1),
                     build(v, (l + r) >> 1, r));
    }

    inline Node* _new(const T& data) const { return new Node(data); }

    inline Node* modify(Node *t) {
        t->sz = size(t->lch) + size(t->rch) + 1;
        return t;
    }
};
#line 2 "lib/structure/multi_set.cpp"

/**
 * @brief
 * 常に昇順にソートされた配列（マルチセット）
 * 任意箇所の要素の更新・取得・挿入・削除をO(log n)で行う.
 * 昇順を保ったまま値の挿入・削除をO(log n)で行う.
 * @author habara-k
 * @date 2020/05/05
 * @details verify: https://arc033.contest.atcoder.jp/tasks/arc033_3
 */

template<typename T>
struct MultiSet : RandomizedBinarySearchTree<T> {
    using RBST = RandomizedBinarySearchTree<T>;
    using Node = typename RBST::Node;

    MultiSet() : RBST() {}

    /**
    * @brief 値の挿入を行う. O(log n)
    * @param[in] key: 要素の値
    */
    void insert_key(const T& key) {
        RBST::insert(lower_bound(this->root, key), key);
    }

    /**
    * @brief 値の削除を行う. O(log n)
    * @param[in] key: 要素の値
    */
    void erase_key(const T& key) {
        if (count(this->root, key) == 0) return;
        RBST::erase(lower_bound(this->root, key));
    }

private:
    int lower_bound(Node *t, const T& key) {
        if (!t) return 0;
        if (key <= t->data) return lower_bound(t->lch, key);
        return lower_bound(t->rch, key) + RBST::size(t->lch) + 1;
    }

    int upper_bound(Node *t, const T& key) {
        if (!t) return 0;
        if (key < t->data) return upper_bound(t->lch, key);
        return upper_bound(t->rch, key) + RBST::size(t->lch) + 1;
    }

    int count(Node *t, const T& key) {
        return upper_bound(t, key) - lower_bound(t, key);
    }
};


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

