#include "../../lib/structure/multi_set.cpp"

int main() {
    int Q; cin >> Q;

    MultiSet<int> tree;

    while (Q--) {
        int t, x; cin >> t >> x;
        if (t == 1) {
            tree.insert_key(x);
        }
        else {
            cout << tree[x-1] << endl;
            tree.erase(x-1);
        }
    }

    return 0;
}
