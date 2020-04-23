# PROCON LIBRARY for WHITE-BOARD

[![Actions Status](https://github.com/habara-k/ICPClibrary/workflows/verify/badge.svg)](https://github.com/habara-k/ICPClibrary/actions)

## 手動テスト

- ### コンパイル・実行

- `$ g++ test/graph/dijkstra.test.cpp`
- `$ ./a.out`

- ### 提出

- `lib/template.cpp`の`#include <bits/stdc++.h>`をコメントアウトする
- `$ g++ test/graph/dijkstra.cpp -E -C -P`
- 標準出力をコピーして`PROBLEM`のjudge に貼り付けて提出
- `//#include <bits/stdc++.h>`のコメントアウトを外す

## CI

- ### テスト

`*.test.cpp`に従うファイルは [Online Judge Verify Helper](https://github.com/kmyk/online-judge-verify-helper) が自動でテストしてくれる。

- ### PDFコンパイル

[Action](https://github.com/habara-k/ICPCLibrary/actions)でpassしてる最新のActionを開いて、Artifactsのmain.pdfを確認する。



## Contribute

- `lib` 以下にライブラリを書いてください。
-　`test` 以下にテストコードを書いてください。AOJは大体対応してるはず。書き方は既存のテストファイルを見てね

## Coding規約

- Md さんが書いてくれた `lib/graph/dinic.cpp` がとても読みやすいのでこんな感じにしたい。
