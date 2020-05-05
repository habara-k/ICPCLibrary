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

