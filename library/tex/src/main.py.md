---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: tex/src/main.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a027bd23603dcb83d224b0c0ea5ce216">tex/src</a>
* <a href="{{ site.github.repository_url }}/blob/master/tex/src/main.py">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
import os
import re
import shutil
import subprocess


def toCamelCase(string):
    return ''.join(x.title() for x in string.split('_'))


def find_all_files(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            yield os.path.join(root, file)


def insert_source_code(file):
    src_dirs = set()

    for src_path in find_all_files('lib'):

        if src_path == 'lib/template.cpp':
            file.write('\n\section{Template}\n\n')
            file.write('\lstinputlisting{../' + src_path + '}\n\n')
            continue


        snippet_only = False
        with open(src_path,'r') as src:

            for row in src:
                if re.match('#define SNIPPET_ONLY', row):
                    snippet_only = True

        if snippet_only:
            continue


        dir = os.path.dirname(src_path)[len('lib/'):]

        if dir not in src_dirs:
            file.write('\n\section{' + toCamelCase(dir) + '}\n\n')
            src_dirs.add(dir)

        title, _ = os.path.splitext(os.path.basename(src_path))

        file.write('\subsection{' + toCamelCase(title) + '}\n')
        file.write('\lstinputlisting{../' + src_path + '}\n\n')


def create_texfile():
    BASE_FILE = 'tex/src/base.tex'
    OUTPUT_FILE = 'tex/main.tex'

    with open(OUTPUT_FILE, 'w') as output_file:

        with open(BASE_FILE, 'r') as base_file:

            for row in base_file:
                if re.match('% insert here', row):
                    insert_source_code(output_file)
                else:
                    output_file.write(row)


def push_to_master():
    url = 'https://{}:{}@github.com/{}.git'.format(
            os.environ['GITHUB_ACTOR'],
            os.environ['GITHUB_TOKEN'],
            os.environ['GITHUB_REPOSITORY'])

    subprocess.check_call(['git', 'config', '--global', 'user.email', 'noreply@github.com'])
    subprocess.check_call(['git', 'config', '--global', 'user.name', 'GitHub'])
    subprocess.check_call(['git', 'add', 'tex'])
    if subprocess.run(['git', 'diff', '--quiet', '--staged']).returncode:
        subprocess.check_call(['git', 'commit', '-m', 'Create tex file'])
        subprocess.check_call(['git', 'push', url, 'HEAD'])


if __name__ == '__main__':
    create_texfile()
    push_to_master()

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py", line 84, in bundle
    raise NotImplementedError
NotImplementedError

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

