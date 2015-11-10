n = 0
var = ['']*12
low = [0]*12
high = [0]*12
exp = ''
op = ''
cnt = 0

def calc_exp(i):
	global cnt, n, fun
	for val in range(low[i], high[i]+1):
		globals()[var[i]] = val
		if i < n - 1:
			calc_exp(i+1)
		else:
			cnt += eval(fun)
			
while True:
	try:
		n = input()
		# var = low = high = []*
		exp = op = ''
		cnt = 0
		for i in range(n):
			inputList = raw_input().split()
			var[i] = inputList[0]
			low[i] = int(inputList[1])
			# print low[0], int(inputList[1])
			high[i] = int(inputList[2])
		exp = raw_input().strip().replace(' = ', ' == ')
		tmp = raw_input().strip()
		# while tmp != '0':
		# 	exp += ' or ' + tmp.replace(' = ', ' == ')
		# 	tmp = raw_input().strip()
		
		fun = compile(exp, '', 'eval')
		if '<' in exp:
			op = '<'
		else:
			op = '='
		# raw_input()
		calc_exp(0)
		print cnt
	except EOFError: 
		break