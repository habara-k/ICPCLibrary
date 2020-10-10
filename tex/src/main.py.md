---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://{}:{}@github.com/{}.git
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import os\nimport re\nimport shutil\nimport subprocess\n\n\ndef toCamelCase(string):\n\
    \    return ''.join(x.title() for x in string.split('_'))\n\n\ndef find_all_files(directory):\n\
    \    for root, dirs, files in os.walk(directory):\n        for file in files:\n\
    \            yield os.path.join(root, file)\n\n\ndef insert_source_code(file):\n\
    \    src_dirs = set()\n\n    for src_path in find_all_files('lib'):\n\n      \
    \  if src_path == 'lib/template.cpp':\n            file.write('\\n\\section{Template}\\\
    n\\n')\n            file.write('\\lstinputlisting{../' + src_path + '}\\n\\n')\n\
    \            continue\n\n\n        snippet_only = False\n        with open(src_path,'r')\
    \ as src:\n\n            for row in src:\n                if re.match('#define\
    \ SNIPPET_ONLY', row):\n                    snippet_only = True\n\n        if\
    \ snippet_only:\n            continue\n\n\n        dir = os.path.dirname(src_path)[len('lib/'):]\n\
    \n        if dir not in src_dirs:\n            file.write('\\n\\section{' + toCamelCase(dir)\
    \ + '}\\n\\n')\n            src_dirs.add(dir)\n\n        title, _ = os.path.splitext(os.path.basename(src_path))\n\
    \n        file.write('\\subsection{' + toCamelCase(title) + '}\\n')\n        file.write('\\\
    lstinputlisting{../' + src_path + '}\\n\\n')\n\n\ndef create_texfile():\n    BASE_FILE\
    \ = 'tex/src/base.tex'\n    OUTPUT_FILE = 'tex/main.tex'\n\n    with open(OUTPUT_FILE,\
    \ 'w') as output_file:\n\n        with open(BASE_FILE, 'r') as base_file:\n\n\
    \            for row in base_file:\n                if re.match('% insert here',\
    \ row):\n                    insert_source_code(output_file)\n               \
    \ else:\n                    output_file.write(row)\n\n\ndef push_to_master():\n\
    \    url = 'https://{}:{}@github.com/{}.git'.format(\n            os.environ['GITHUB_ACTOR'],\n\
    \            os.environ['GITHUB_TOKEN'],\n            os.environ['GITHUB_REPOSITORY'])\n\
    \n    subprocess.check_call(['git', 'config', '--global', 'user.email', 'noreply@github.com'])\n\
    \    subprocess.check_call(['git', 'config', '--global', 'user.name', 'GitHub'])\n\
    \    subprocess.check_call(['git', 'add', 'tex'])\n    if subprocess.run(['git',\
    \ 'diff', '--quiet', '--staged']).returncode:\n        subprocess.check_call(['git',\
    \ 'commit', '-m', 'Create tex file'])\n        subprocess.check_call(['git', 'push',\
    \ url, 'HEAD'])\n\n\nif __name__ == '__main__':\n    create_texfile()\n    push_to_master()\n"
  dependsOn: []
  isVerificationFile: false
  path: tex/src/main.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tex/src/main.py
layout: document
redirect_from:
- /library/tex/src/main.py
- /library/tex/src/main.py.html
title: tex/src/main.py
---
