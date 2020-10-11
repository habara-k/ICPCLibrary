#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include "../../lib/number/rmint.cpp"
#include "../../lib/number/comb.cpp"


int main() {

    int N, M; cin >> N >> M;

    using Int = rmint<ll>;
    Int::set_mod(M);

    auto ans = Montmort<Int>(N);
    for (int k = 1; k <= N; ++k) {
        if (k) cout << ' ';
        cout << ans[k];
    }
    cout << endl;

    return 0;
}
