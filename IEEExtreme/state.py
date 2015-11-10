import re

def convert(num):
	if num == '1' or num == 1:
		return '***'
	return '___'

tmp = raw_input().split()
total_state = int(tmp[0])
total_var = int(tmp[1])
outs = []
changes = []
to = []
for i in range(total_state):
	changes.append([])
	to.append([])
	tmp = raw_input().split()
	outs.append(int(tmp[0]))
	for transition in tmp[2:]:
		changes[-1].append(['.']*total_var)
		transition = transition.split('/')
		condition = transition[0].split(',')
		to[-1].append(int(transition[1]))
		for c in condition:
			changes[-1][-1][ord(c[0])-65] = c[2]
		changes[-1][-1] = ''.join(changes[-1][-1])
# print outs
# print changes
# print to
tmp = raw_input().split()
total_input = int(tmp[0])
state = int(tmp[1])

out_var = ['']*total_var;
out_out = ''
out_state = ''



for i in range(total_input):
	var = raw_input().strip().replace(' ', '')
	for j in range(len(var)):
			out_var[j] += convert(var[j])
	for j in range(len(changes[state])):
		if re.match(changes[state][j], var):
			state = to[state][j]
			break
	out_state += "%3d" % state
	# print "outs[state]:%d" %outs[state]
	out_out += convert(outs[state])

# print "total_input:%d" % total_input
for i in range(0, total_input, 16):
	print "Tick #%d" % (i+1)
	for j in range(len(out_var)):
		print "%s     %s" % (chr(j + 65), out_var[j][(i*3):(i*3)+48])
	print "OUT   %s" % out_out[(i*3):(i*3)+48]
	print "STATE %s" % out_state[(i*3):(i*3)+48]
	print 
