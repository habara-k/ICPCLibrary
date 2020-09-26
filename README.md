# PROCON LIBRARY for WHITE-BOARD

[![Actions Status](https://github.com/habara-k/ICPClibrary/workflows/verify/badge.svg)](https://github.com/habara-k/ICPClibrary/actions)

## 手動テスト

- ### コンパイル・実行

1. `$ g++ test/graph/dijkstra.test.cpp`
2. `$ ./a.out`

- ### 提出

1. `lib/template.cpp`の`#include <bits/stdc++.h>`をコメントアウトする
2. `$ g++ test/graph/dijkstra.cpp -E -C -P`
3. 標準出力をコピーして`PROBLEM`のjudge に貼り付けて提出
4. `//#include <bits/stdc++.h>`のコメントアウトを外す

## CI

- ### テスト

`*.test.cpp`に従うファイルは [Online Judge Verify Helper](https://github.com/kmyk/online-judge-verify-helper) が自動でテストしてくれる。

- ### LaTeXのPDF出力

[Action](https://github.com/habara-k/ICPCLibrary/actions)でpassしてる最新のActionを開いて、Artifactsのmain.pdfを確認する。

- ### CLionのライブテンプレート


[Action](https://github.com/habara-k/ICPCLibrary/actions)でpassしてる最新のActionを開いて、ArtifactsのC_C__.xmlをダウンロードする。


- Macだと`~/Library/Application Support/JetBrains/CLion2020.1/templates/C_C__.xml`
- Linuxだと `~/.config/JetBrains/CLion2020.2/templates/C_C__.xml`

のファイルをこれに置き換える。


## Contribute

- `lib` 以下にライブラリを書いてください。

- `test` 以下にテストコードを書いてください。AOJは大体対応してるはず。書き方は既存のテストファイルを見てね

## Coding規約

- Md さんが書いてくれた `lib/graph/dinic.cpp` がとても読みやすいのでこんな感じにしたい。
