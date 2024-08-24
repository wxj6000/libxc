import os
import re
import glob

left = r'p->params = libxc_malloc(sizeof('
right= r'));'

new_left = r'p->params = malloc(sizeof('
new_right= r'));'

pattern = fr'{re.escape(left)}(.*?){re.escape(right)}'
count = 0
for file_path in glob.iglob('*.c'):
    if os.path.isfile(file_path):
        with open(file_path, 'r', encoding='utf-8') as file:
            file_content = file.read()

        match = re.search(pattern, file_content)
        
        if match:
            count += 1
            struct_name = match.group(1)
            new_line = f'{new_left}{struct_name}{new_right} \n  p->params_size = sizeof({struct_name});'
            print(f'in {file_path}, find {new_line}')
            
            file_content = re.sub(pattern, new_line, file_content)
            print(file_content)
        
        with open(file_path, 'w', encoding='utf-8') as file:
            file.write(file_content)
        
print(f'{count} files are changed')
