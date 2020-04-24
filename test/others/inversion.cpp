#define PROBLEM "https://atcoder.jp/contests/agc034/tasks/agc034_b"

#include "../../lib/others/inversion.cpp"

int main()
{
    string s; cin >> s;

    vector<vector<int>> vs;
    vector<int> v;
    for (int i = 0; i <= s.size(); ++i) {
        if (i == s.size()) {
            if (v.size()) vs.push_back(v);
            v.clear();
        } else if (s[i] == 'A') {
            v.push_back(1);
        } else if (i+1 < s.size() && s[i] == 'B' && s[i+1] == 'C') {
            v.push_back(0);
            ++i;
        } else {
            if (v.size()) vs.push_back(v);
            v.clear();
        }
    }

    ll ans = 0;
    for (auto v : vs) {
        ans += inversion(v);
    }
    cout << ans << endl;

    return 0;
}
