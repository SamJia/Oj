s = raw_input().split();
n = int(s[0])
a = int(s[1])
b = int(s[2])
result = [0]*500100
result[0] = 1
for i in range(n):
	result[i+a] += result[i]
	result[i+b] += result[i]
print(result[n])