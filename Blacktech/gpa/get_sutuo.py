import xlrd, xlwt, urllib2, re

xls = xlrd.open_workbook('gpa.xls')
sheet = xls.sheet_by_index(3)
# sheet.put_cell(0,6,1,"test",0)
studentIDs = sheet.col_values(1)

base_url = "http://z.seiee.com/index.php/Score/search?sid=%d"
name_re = re.compile(r'<td width="70%">(.+?)</td>')
score_re = re.compile(r"<td width=\"70%\"><span class=\"badge badge-info\">(.+?)</span></td>")
scores = []
names = []
fp = open("scores.txt", "w")
for i in range(1, len(studentIDs)):
	print int(studentIDs[i])
	url = base_url % int(studentIDs[i])
	try:
		req = urllib2.Request(url)
		content = urllib2.urlopen(req).read().replace('\n', '\t')
		# print content
		name_match = name_re.search(content)
		if name_match:
			fp.write('%s\t' % name_match.group(1))
		else:
			print "no score!"
			exit(0)
		score_match = score_re.search(content)
		if score_match:
			fp.write('%s\n' % score_match.group(1))
			scores.append(float(score_match.group(1)))
		else:
			print "no score!"
			exit(0)
		# sheet.put_cell(i, 6, 2, float(score), 0) # row, col, type(2:number), value
	except Exception, e:
		print str(e)
fp.close()

# req = urllib2.Request(base_url)
	