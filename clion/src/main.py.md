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
  code: "import os\nimport re\nimport shutil\nimport subprocess\n\n\ndef find_all_files(directory):\n\
    \    for root, dirs, files in os.walk(directory):\n        for file in files:\n\
    \            yield os.path.join(root, file)\n\n\ndef create_live_template():\n\
    \    LIVE_TEMPLATE_FILE = 'clion/C_C__.xml'\n\n    with open(LIVE_TEMPLATE_FILE,'w')\
    \ as file:\n        file.write('<templateSet group=\"C/C++\">\\n')\n\n       \
    \ for src_path in find_all_files('lib'):\n\n            src_title, fext = os.path.splitext(os.path.basename(src_path))\n\
    \            if fext != '.cpp':\n                continue\n\n            if src_title\
    \ == 'template':\n                continue\n\n            name = src_title\n \
    \           description = src_title\n            value = \"\"\n\n            with\
    \ open(src_path,'r') as src:\n\n                for row in src:\n            \
    \        if re.match('#', row):\n                        continue\n\n        \
    \            row = row.replace('&', '&amp;')\n                    row = row.replace('\\\
    n', '&#10;')\n                    row = row.replace('<', '&lt;')\n           \
    \         row = row.replace('>', '&gt;')\n                    row = row.replace('\"\
    ', '&quot;')\n\n                    value += row\n\n            file.write(' \
    \ <template name=\"{}\" value=\"{}\" description=\"{}\" toReformat=\"true\" toShortenFQNames=\"\
    true\">\\n'.format(name, value, description))\n            file.write('    <context>\\\
    n')\n            file.write('      <option name=\"cpp\" value=\"true\" />\\n')\n\
    \            file.write('    </context>\\n')\n            file.write('  </template>\\\
    n')\n\n        file.write('</templateSet>\\n')\n\n\ndef push_to_master():\n  \
    \  url = 'https://{}:{}@github.com/{}.git'.format(\n            os.environ['GITHUB_ACTOR'],\n\
    \            os.environ['GITHUB_TOKEN'],\n            os.environ['GITHUB_REPOSITORY'])\n\
    \n    subprocess.check_call(['git', 'config', '--global', 'user.email', 'noreply@github.com'])\n\
    \    subprocess.check_call(['git', 'config', '--global', 'user.name', 'GitHub'])\n\
    \    subprocess.check_call(['git', 'add', 'clion'])\n    if subprocess.run(['git',\
    \ 'diff', '--quiet', '--staged']).returncode:\n        subprocess.check_call(['git',\
    \ 'commit', '-m', 'Create live-template files'])\n        subprocess.check_call(['git',\
    \ 'push', url, 'HEAD'])\n\n\nif __name__ == '__main__':\n    create_live_template()\n\
    \    push_to_master()\n"
  dependsOn: []
  isVerificationFile: false
  path: clion/src/main.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: clion/src/main.py
layout: document
redirect_from:
- /library/clion/src/main.py
- /library/clion/src/main.py.html
title: clion/src/main.py
---
