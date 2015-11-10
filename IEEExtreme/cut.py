SIZE = 2000
result = [];
for i in range(SIZE):
	result.append([0]*2)
total = [0]*SIZE

result[3][0] = 1
total[3] = 1
for i in range(4, SIZE): # side
	result[i][0] += total[i-1];
	for k in range(3, i): # line to another corner
		result[i][1] += result[k][0] * total[i+2-k]
	total[i] += result[i][0] + result[i][1]
dic = {}
for i in range(3, SIZE):
	dic[total[i]] = i
while True:
	try:
		num = raw_input().strip()
		print dic.get(int(num), 0)
	except EOFError:
		break
