/**
 * @brief
 * 最小流量制限付き最大流
 * Flowには（大抵の場合）Dinic<Int>を指定すればよい
 * 最小流量の制約を満たせない場合、max_flowで-1が返ってくる
 * @author Md
 * @date 2020/10/17
 */

#include "dinic.cpp"

template<class Flow, typename Int>
struct MaxFlowWithLowerLimit {
  int n;
  Flow flow;
  int S, T;
  Int su_l = 0;

  MaxFlowWithLowerLimit(int n): n(n), flow(n+2){
    S = n;
    T = n + 1;
  }

  void add_edge(int from, int to, Int l, Int r) {
    flow.add_edge(from, to, r - l);
    flow.add_edge(from, T, l);
    flow.add_edge(S, to, l);
    su_l += l;
  }

  Int max_flow(int s, int t) {
    Int val0 = flow.max_flow(S, T);
    Int val1 = flow.max_flow(s, T);
    Int val2 = flow.max_flow(S, t);
    Int val3 = flow.max_flow(s, t);
    return (val0 + val2 == su_l && val0 + val1 == su_l) ? val1 + val3 : -1;
  }
};
