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
