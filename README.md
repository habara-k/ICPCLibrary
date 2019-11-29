# HOW TO USE

## COMPILE & TEST

- `test/`に移動
- `$ g++ graph/dijkstra.cpp`
- `$ ./a.out`

## SUBMIT

- `template.cpp`の`#include <bits/stdc++.h>`をコメントアウトする
- `test/`に移動
- `$ g++ -E -C -P graph/dijkstra.cpp`
- 標準出力をコピーして`PROBLEM`のjudge に貼り付けて提出
- `//#include <bits/stdc++.h>`のコメントアウトを外す

## TEX

- `tex/`に移動
- `$ docker run --rm -v $PWD:/workdir -it paperist/alpine-texlive-ja /bin/sh`
- `# platex main.tex`
- `# dvipdfmx main.dvi`
- Ctrl-D で終了
- `$ open main.pdf`
