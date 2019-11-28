#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include "../../number/prime_factor.cpp"

int main() {
    int64_t n; cin >> n;
    map<int64_t, int> fact = prime_factor(n);
    cout << n << ":";
    for (auto p : fact) {
        for (int i = 0; i < p.second; ++i) {
            cout << " " << p.first;
        }
    }
    cout << endl;
}
