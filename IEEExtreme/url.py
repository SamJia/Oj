# -*- coding: utf-8 -*-
import sys 

ALPHABET = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

def base62_encode(num, alphabet=ALPHABET):
	if (num == 0):
		return alphabet[0]
	arr = ''
	base = len(alphabet)
	while num:
		rem = num % base
		num = num / base
		arr += alphabet[rem]
	return arr[::-1]

# encoding = 'utf-8' if sys.stdin.encoding in (None, 'ascii') else sys.stdin.encoding

# base_url = "http://www.ieee.com"
base_url = raw_input().strip()
BASE = base_url

n = input()
for i in range(n):
	base_url = BASE
	# target_url = "http://www.ieee.org/xtreme"
	target_url = raw_input().strip()
	tmp_arr = []

	while len(base_url) < len(target_url):
		base_url = base_url + BASE

	for i in range(len(target_url)):
		tmp_arr = tmp_arr +  [ord(base_url[i])^ord(target_url[i])]

 	tmp_num = 0
 	for digit in tmp_arr[-8:]:
 		# print format(digit, '02x')
 		tmp_num += tmp_num*255 + digit
 	fin_str = base62_encode(tmp_num)

 	print BASE + "/" + fin_str