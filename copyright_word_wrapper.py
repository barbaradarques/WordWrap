a98="""The Royal License (Royal)

Copyright (c) 2020 Alexandro Goncalves Dos Santos

Permissive license in which you must give unrestricted access, power to the license creator and the creator who used the license in its creation in addition to maintaining that right in any derivative works. In derivative works or original works, there may be more than one license including this one, in conflicts The Royal License wins. If there is any financial, social or other wins, it will be necessary to share it with the license creator and the creator who used the license in its creation. For specific cases that raise doubts, consult the license creator.  

ALEXANDRO GONCALVES DOS SANTOS, THE CREATORS, THE SUPPLIERS, THE GOVERNMENTS, THE ENTREPRENEURS, THE USERS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS CREATION, THIS LICENSE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL ALEXANDRO GONCALVES DOS SANTOS, THE CREATORS, THE SUPPLIERS, THE GOVERNMENTS, THE ENTREPRENEURS, THE USERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OR OTHER THIS CREATION.
"""
a97="Copyright (c) 2020 Alexandro Goncalves Dos Santos"
a96=len(a97)
a95=''
while a95 not ['n','N']:
	import os
	a92='/'.join(__file__.split('/')[:-1])
	a93=f'cd {a92}'
	os.system(a93)
	a94=os.system('git clone https://github.com/AlexandroGonSan/WordWrap_py')
	if a94!=0:
		exit()
	
	a91=f'python3 {a92}/WordWrap_py/wrapper.py --len 20 "{}"'
	os.system(a91)