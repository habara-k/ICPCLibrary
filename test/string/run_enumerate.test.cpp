#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"

#include "../../lib/string/run_enumerate.cpp"

int main()
{
    string s; cin >> s;
    int n = s.size();

    map<pair<int,int>,int> res;
    run_enumerate(0, n, s, res);

    cout << res.size() << endl;
    vector<tuple<int,int,int>> ans;
    for (auto tp : res) {
        ans.emplace_back(tp.second, tp.first.first, tp.first.second);
    }
    sort(ALL(ans));
    for (auto& [t, l, r] : ans) {
        cout << t << ' ' << l << ' ' << r << endl;
    }
    return 0;
}
