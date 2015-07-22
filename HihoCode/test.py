import sys
def gcd(a, b):
	if b > a:
		a, b = b, a
	while a % b != 0:
		a, b = b, a % b
	return b

def cnt(num):
	if num == 1:
		return 1
	result = 0
	i = 2
	while i <= num:
		if num % i == 0:
			num /= i
			result += 1
		else:
			i += 1
	return result

def main():
	# print "main"
	a = set()
	test_number = input()
	for test in range(test_number):
		s = raw_input().strip().split()
		opt = s[0]
		num = (int)(s[1])
		if opt == "I":
			a.add(num)
		elif opt == "D":
			if num in a:
				a.remove(num)
		else:
			result = 0x7fffffff
			for i in a:
				tmp = gcd(i, num)
				result = min(result, cnt(i / tmp) + cnt(num / tmp))
			if result == 0x7fffffff:
				print -1
			else:
				print result

if __name__ == '__main__':
	sys.stdin = open("input", "r")
	# a = input()
	# print "a:", a
	main()