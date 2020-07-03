import os
import re
import shutil
import subprocess


def find_all_files(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            yield os.path.join(root, file)


def create_live_template():
    LIVE_TEMPLATE_FILE = 'clion/live_template/C_C__.xml'

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
