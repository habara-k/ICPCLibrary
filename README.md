# PROCON LIBRARY for WHITE-BOARD

[![Actions Status](https://github.com/habara-k/ICPClibrary/workflows/verify/badge.svg)](https://github.com/habara-k/ICPClibrary/actions)

## 手動テスト

### コンパイル・実行

- `test/`に移動
- `$ g++ graph/dijkstra.test.cpp`
- `$ ./a.out`

### 提出

- `template.cpp`の`#include <bits/stdc++.h>`をコメントアウトする
- `test/`に移動
- `$ g++ -E -C -P graph/dijkstra.cpp`
- 標準出力をコピーして`PROBLEM`のjudge に貼り付けて提出
- `//#include <bits/stdc++.h>`のコメントアウトを外す

## 自動テスト

`*.test.cpp`に従うファイルは [Online Judge Verify Helper](https://github.com/kmyk/online-judge-verify-helper) が自動でテストしてくれる。

## TeXファイルの出力

- `tex/`に移動
- `$ docker run --rm -v $PWD:/workdir -it paperist/alpine-texlive-ja /bin/sh`
- `# platex main.tex`
- `# dvipdfmx main.dvi`
- Ctrl-D で終了
- `$ open main.pdf`
