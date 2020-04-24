#include "../template.cpp"

#include "../structure/binary_indexed_tree.cpp"

template<typename T>
ll inversion(const vector<T>& a)
{
    map<T,int> mp;
    for (auto e : a) mp[e] = -1;
    int sz = 0;
    for (auto &q : mp) {
        q.second = sz++;
    }

    BIT<int> bit(sz+1);
    ll res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res += i - bit.sum(mp[a[i]]);
        bit.add(mp[a[i]], 1);
    }
    return res;
}
