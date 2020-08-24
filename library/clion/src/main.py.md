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


# :warning: clion/src/main.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ed6a026ddead4378a6f388dc9d849bf0">clion/src</a>
* <a href="{{ site.github.repository_url }}/blob/master/clion/src/main.py">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
import os
import re
import shutil
import subprocess


def find_all_files(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            yield os.path.join(root, file)


def create_live_template():
    LIVE_TEMPLATE_FILE = 'clion/live-template/C_C__.xml'

    with open(LIVE_TEMPLATE_FILE,'w') as file:
        file.write('<templateSet group="C/C++">\n')

        for src_path in find_all_files('lib'):

            src_title, fext = os.path.splitext(os.path.basename(src_path))
            if fext != '.cpp':
                continue

            if src_title == 'template':
                continue

            name = src_title
            description = src_title
            value = ""

            with open(src_path,'r') as src:

                for row in src:
                    if re.match('#', row):
                        continue

                    row = row.replace('&', '&amp;')
                    row = row.replace('\n', '&#10;')
                    row = row.replace('<', '&lt;')
                    row = row.replace('>', '&gt;')
                    row = row.replace('"', '&quot;')

                    value += row

            file.write('  <template name="{}" value="{}" description="{}" toReformat="true" toShortenFQNames="true">\n'.format(name, value, description))
            file.write('    <context>\n')
            file.write('      <option name="cpp" value="true" />\n')
            file.write('    </context>\n')
            file.write('  </template>\n')

        file.write('</templateSet>\n')


def push_to_master():
    url = 'https://{}:{}@github.com/{}.git'.format(
            os.environ['GITHUB_ACTOR'],
            os.environ['GITHUB_TOKEN'],
            os.environ['GITHUB_REPOSITORY'])

    subprocess.check_call(['git', 'config', '--global', 'user.email', 'noreply@github.com'])
    subprocess.check_call(['git', 'config', '--global', 'user.name', 'GitHub'])
    subprocess.check_call(['git', 'add', 'clion'])
    if subprocess.run(['git', 'diff', '--quiet', '--staged']).returncode:
        subprocess.check_call(['git', 'commit', '-m', 'Create live-template files'])
        subprocess.check_call(['git', 'push', url, 'HEAD'])


if __name__ == '__main__':
    create_live_template()
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

