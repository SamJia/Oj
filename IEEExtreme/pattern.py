def Compute(string, min_len = 1):
	for length in range(min_len, len(string) / 2 + 1):
		if len(string) % length == 0:
			if string[:length] * (len(string) / length) == string:
				return length;
	return len(string);
total_case = input()
for i in range(total_case):
	result = 0
	string = raw_input().strip()
	length = len(string)
	result = Compute(string)
	if result and result != len(string):
		print result
		continue;
	result = 10000000
	for j in range(length - 1, 1, -1):
		if string[j] == string[0]:
			if string[:length-j] == string[j:]:
				if length-j > result:
					break
				result = min(result, Compute(string[:j], length-j))
				# if result:
				# 	pass
					# print result
					# break
	if result == 10000000:
		print length
	else:
		print result