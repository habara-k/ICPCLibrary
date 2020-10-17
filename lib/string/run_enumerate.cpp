#include "../template.cpp"
#include "z_algorithm.cpp"

/**
* @brief Run列挙
* @maintainer habara-k
* @date 2020/09/19
* @param[in] l, r, s: 文字列(or vector)sの区間[l, r) におけるRunを列挙
* @param[out] res: 極大なRun[l, r)に対する最小周期を格納したmap
* @details Z-Algorithm に依存
*/

template<typename T>
void run_enumerate(int l, int r, const T& s, map<pair<int,int>,int>& res) {
    if (r - l <= 1) return;
    int m = (l + r) >> 1;
    run_enumerate(l, m, s, res);
    run_enumerate(m, r, s, res);

    auto func = [&](bool rev) {
        T t, tl, tr;
        copy(s.begin() + l, s.begin() + r, back_inserter(t));
        if (rev) {
            reverse(t.begin(), t.end());
            m = l + r - m;
        }
        int len = r - l, mid = m - l;
        copy(t.begin(), t.begin() + mid, back_inserter(tl));
        reverse(tl.begin(), tl.end());
        copy(t.begin() + mid, t.end(), back_inserter(tr));
        copy(t.begin(), t.end(), back_inserter(tr));
        auto zl = z_algorithm(tl), zr = z_algorithm(tr);
        zl.push_back(0);
        for (int k = 1; k <= mid; ++k) {
            int li = m - k - zl[k], ri = m + min(r - m, zr[len - k]);
            if (rev) {
                swap(li, ri);
                li = l + r - li;
                ri = l + r - ri;
            }
            if (ri - li < 2 * k) continue;
            if (li > 0 && s[li - 1] == s[li - 1 + k]) continue;
            if (ri < s.size() && s[ri] == s[ri - k]) continue;
            if (res.count({li, ri})) res[{li, ri}] = min(res[{li, ri}], k);
            else res[{li, ri}] = k;
        }
    };
    func(0);
    func(1);
}

