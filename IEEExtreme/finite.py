
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
		var = []
		low = []
		high = []
		value = []
		n = input()
		cnt = 0
		for i in range(n):
			tmp = raw_input().split()
			var.append(tmp[0])
			low.append(int(tmp[1]))
			high.append(int(tmp[2]))
			value.append(int(tmp[1]))
			exec("%s = %d" % (tmp[0], int(tmp[1])))
		exp = raw_input().strip().replace(' = ', ' == ')
		fun = compile(exp, '', 'eval')
		raw_input()

		calc_exp(0)

		# while True:
		# 	# print value
		# 	for j in range(len(value)-1, 0, -1):
		# 		if value[j] == high[j]+1:
		# 			value[j] = low[j]
		# 			value[j-1] += 1
		# 			exec("%s = %d" % (var[j], value[j]))
		# 			exec("%s = %d" % (var[j-1], value[j-1]))
		# 		else:
		# 			break
		# 	if value[0] == high[0]+1:
		# 		break
		# 	# print value
		# 	cnt += eval(fun)
		# 	value[-1] += 1
		# 	exec("%s = %d" % (var[-1], value[-1]))
		print cnt
	except EOFError:
		break