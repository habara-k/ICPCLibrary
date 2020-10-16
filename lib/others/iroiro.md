だいたいはまやんはまやんはまやんさんのブログの内容
https://www.hamayanhamayan.com/entry/2100/01/01/000000

- Mo's Algorithm  
  区間クエリにこたえる問題で、次のときMoが使える
  1. 配列の要素が不変
  2. オフラインクエリ
  3. [l, r)の結果を用いて[l+1, r), [l-1, r), [l, r+1), [l, r-1)の結果が高速にわかる
  
  やりかた  
  1. 区間を平方分割  
  2. (区間の左端が属するブロックの番号, 右端の値) のペアでソート  
  3. 端を移動させながらソートした順番に処理する
  
- FFTをたくさんやるときはハミング符号っぽくやると、多項式のリテラルの個数の和をNとしてO(NlogN)

- ピックの定理  
格子点上に頂点があるような凸とは限らない多角形の面積は多角形の内部にある格子点の個数を i、辺上にある格子点の個数を b として  
S = i + b / 2 - 1  
となる

- K重対角行列はO(N^2 K)でガウスの消去法を適用できるらしい

- 任意の自然数はフィボナッチ数の和で表現可能

- エルデシュガライの定理  
  次数列d1>=d2>=d3>=...>=dnを満たす単純グラフが存在することの必要十分条件は
  1. 握手補題がなりたつ
  2. Σ[i=1,k]di <= k(k-1) + Σ[i=k+1,n]min(di, k)   forall 1 <= k <= n
  
- 無向グラフを適当に向きづけて強連結にできることとすべての頂点の次数が2以上であることは同値

- Dilworthの定理  
   推移律を満たすDAGの最大独立集合のサイズは最小パス被覆の本数に等しい
   
- 2部グラフの最大独立集合 = 頂点数 - 最大マッチング

- 文字列Sがあって、S[0,i]の最小の周期をすべてのiについて求めよ  
  KMPして、各位置では(0-indexedで)i + 1 - KMP[i]がこたえ
  
- GCCでつかえる魔法の呪文
  - \#pragma GCC target("avx2")
  - \#pragma GCC optimize("O3")
  - \#pragma GCC optimize("unroll-loops")
  
- pb_ds  
    \#include <ext/pb_ds/assoc_container.hpp>  
    \#include <ext/pb_ds/tree_policy.hpp>  
    
    二分木  
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
    

