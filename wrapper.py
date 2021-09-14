#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
a95=50
if '--len' in sys.argv:
	a98=[]
	for a99 in sys.argv:
		try:
			a98.append(int(a99))
		except:
			None
	if len(a98)==0:
		None
	elif len(a98)==2:
		a97=sys.argv.index('--len')
		a96=a97+1
		a95=sys.argv[a96]
	elif len(a98)>2:
		print('muitos inteiros, nao foi possivel identificar o valor da flag --len')
	else:
		pass
for a94 in range(len(sys.argv)):
	if a94==a95 or a94==0 or sys.argv[a94]=='--len':
		continue
	a93=sys.argv[a94].split(' ')
	a91=''
	for a92 in a93:
		a91+=a92
		if a92=='\n':
			print(a91)
			a91=''
		elif len(a91)<a95:
			a91+=' '
		elif len(a91)==a95:
			print(a91)
			a91=''
		elif len(a91)>a95:
			a88=a91.split(' ')
			a90=a88[-1]
			a91=' '.join(a88[:-1])
			print(a91)
			a91=a90
			a91+=' '
	print(a91)
	print()