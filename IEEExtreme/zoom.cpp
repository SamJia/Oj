l = input()
r = input()
n = input()
dic = {}
for i in range(n):
  c = raw_input()
  res = ['']*r
  for j in range(r):
    line = raw_input()
    res[j] += line
  dic[c] = res

k = input()
for i in range(k):
  sen = raw_input()
  for j in range(r):
    tmp = ''
    for cha in sen:
      tmp += dic[cha][j]
    print tmp