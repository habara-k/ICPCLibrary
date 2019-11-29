#include "template.cpp"

#include "../structure/union_find.cpp"

template<typename T>
T kruskal(vector<edge<T>> &es, int V) {

    UnionFind uf(V);
    T ret = 0;

    // es を破壊的にソートする
    sort(es.begin(), es.end(), [](edge<T> &a,edge<T> &b){
            return a.cost < b.cost;
            });
    for (auto &e : es) {
        if (!uf.issame(e.src, e.to)) {
            ret += e.cost;
            uf.merge(e.src, e.to);
        }
    }

    // es を見る順番だけをソート
    // vector<int> ord(es.size());
    // iota(ord.begin(), ord.end(), 0);
    // sort(ord.begin(), ord.end(), [&](int i,int j){
    //         return es[i].cost < es[j].cost;
    //         });
    // for (auto i : ord) {
    //     auto &e = es[i];
    //     if (!uf.issame(e.src, e.to)) {
    //         ret += e.cost;
    //         uf.merge(e.src, e.to);
    //     }
    // }

    return ret;
}
