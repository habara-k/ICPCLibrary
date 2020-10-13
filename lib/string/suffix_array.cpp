#include "../template.cpp"

/**
 * @brief 接尾辞配列 O(n(logn)^2) ありほんのやつそのまま
 * @detail
 *  construct_saにstringを投げると接尾辞配列が帰ってくる(1-indexed)
 *  construct_lcpにstringとsuffix_arrayを投げるとLCPの配列が帰ってくる(1-indexed)
 *
 *  配列サイズ(ma)に注意（文字列の長さ+1以上）
 * @author Md
 * @date 2020/10/12
 */

namespace SA {
  static const int ma = 1000000;
  int n, k;
  int rank[ma];
  int rank_lcp[ma];
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

  std::vector<int> construct_lcp(const std::string &s, const std::vector<int> &sa) {
    int n = s.length();
    std::vector<int> lcp(n+1);

    for(int i=0;i<=n;++i) rank_lcp[sa[i]] = i;

    int h = 0;
    lcp[0] = 0;
    for(int i=0;i<n;++i) {
      int j = sa[rank_lcp[i] - 1];

      if(h > 0) h--;
      for(; j + h < n && i + h < n; h++) {
        if(s[j+h] != s[i+h]) break;
      }

      lcp[rank_lcp[i] - 1] = h;
    }

    return lcp;
  }

};
