# PROCON LIBRARY for WHITE-BOARD

[![Actions Status](https://github.com/habara-k/ICPClibrary/workflows/verify/badge.svg)](https://github.com/habara-k/ICPClibrary/actions)

## 手動テスト

### コンパイル・実行

- `$ g++ test/graph/dijkstra.test.cpp`
- `$ ./a.out`

### 提出

- `lib/template.cpp`の`#include <bits/stdc++.h>`をコメントアウトする
- `$ g++ test/graph/dijkstra.cpp -E -C -P`
- 標準出力をコピーして`PROBLEM`のjudge に貼り付けて提出
- `//#include <bits/stdc++.h>`のコメントアウトを外す

## 自動テスト

`*.test.cpp`に従うファイルは [Online Judge Verify Helper](https://github.com/kmyk/online-judge-verify-helper) が自動でテストしてくれる。

## TeXファイル

[Action](https://github.com/habara-k/ICPCLibrary/actions)でpassしてる最新のActionを開いて、Artifactsのmain.pdfを確認する。

