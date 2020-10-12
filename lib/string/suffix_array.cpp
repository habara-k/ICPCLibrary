#include "../template.cpp"

namespace SA {
  static const int ma = 1000000;
  int n, k;
  int rank[ma];
  int tmp[ma];

  bool compare_sa(int i, int j) {
    if (rank[i] != rank[j]) return rank[i] < rank[j];
    else {
      int ri = i + k <= n ? rank[i + k] : -1;
      int rj = j + k <= n ? rank[j + k] : -1;
      return ri < rj;
    }
  }

  std::vector<int> construct_sa(const std::string &s) {
    n = s.length();
    std::vector<int> sa(n + 1);
    for (int i = 0; i <= n; ++i) {
      sa[i] = i;
      rank[i] = i < n ? s[i] : -1;
    }

    for (k = 1; k <= n; k *= 2) {
      sort(sa.begin(), sa.end(), compare_sa);

      tmp[sa[0]] = 0;
      for(int i=1;i<=n;++i) {
        tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
      }
      for(int i=0;i<=n;++i) {
        rank[i] = tmp[i];
      }
    }

    return sa;
  }
};
