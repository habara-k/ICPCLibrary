#ifndef GRAPH_TEMPLATE
#define GRAPH_TEMPLATE

#include "../template.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;
};

template<typename T>
using Graph = vector<vector<edge<T>>>;

#endif
