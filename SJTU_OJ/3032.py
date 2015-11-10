total_number = ''
while total_number == '':
	total_number = raw_input().strip()
total_number = int(total_number)
number_list = []
while not total_number == 1:
	number_list.append(total_number)
	total_number = total_number // 2 + total_number % 2
# print number_list
number = 1
for i in number_list[::-1]:
	if i % 2:
		if number == 1:
			number = i
		else:
			number = 2 * (number - 2) + 1
	else:
		number = 2 * (number - 1) + 1
print number