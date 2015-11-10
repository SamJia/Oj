SIZE = 110
result = []
for i in range(SIZE):
	result.append([0]*SIZE)

result[1][1] = 1
for i in range(1, SIZE):
	result[1][i] = Compute(1, i)
	result[i][1] = Compute(i, 1)
for i in range(2, SIZE):
	for j in range(2, SIZE):
		result[i][j] = Compute()


