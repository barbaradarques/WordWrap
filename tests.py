import subprocess
a98="""
Ready, code working and here is your first wrap text.
Ready, code working and here is your first wrap text.
"""
a96=a98.replace('"','\\"')
a99=f'python3 ./wrapper.py --len 20 "{a96}"'
a97 = subprocess.check_output(a99, shell=True)
print(a97)
print(type(a97))