l = input()
r = input()
n = input()
dic = {}
for i in range(n):
  c = raw_input()
  result = [""]*r
  for j in range(r):
    line = raw_input()
    result[j] += line
  dic[c] = result

k = input()
for i in range(k):
  sen = raw_input()
  for j in range(r):
    tmp = ''
    for cha in sen:
      tmp += dic[cha][j]
    print tmp