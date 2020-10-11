#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../lib/template.cpp"

int main() {
    int Q; cin >> Q;
    map<ll,ll> mp;
    while (Q--) {
        int type; cin >> type;
        if (type == 0) {
            ll k, v; cin >> k >> v;
            mp[k] = v;
        } else {
            ll k; cin >> k;
            cout << mp[k] << endl;
        }
    }

    return 0;
}
