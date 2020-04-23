#include "template.cpp"

void topological_sort(const vector<vector<int>>& G, vector<int>& ord)
{
    int n = G.size();
    vector<int> num(n, 0);
    ord.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        for (auto u : G[i]) {
            ++num[u];
        }
    }
    stack<int> st;
    for(int i = 0; i < n; ++i) {
        if (num[i] == 0) {
            st.push(i);
        }
    }
    for (int k = 0; !st.empty(); ++k) {
        int i = st.top(); st.pop();
        ord[k] = i;
        for (auto u : G[i]) {
            if (--num[u] == 0) {
                st.push(u);
            }
        }
    }
}
