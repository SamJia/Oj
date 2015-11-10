days_in_month = [0,31,29,31,30,31,30,31,31,30,31,30,31]

def isleap(year):
	return year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)

n = input()
for i in range(n):
	year = input()
	yyyy = str(year)
	yy = yyyy[-2:]
	result = 0
	for month in range(1,13):
		M = str(month)
		if (len(M) == 1):
			MM = '0' + M
		else:
			MM = M
		for day in range(1,days_in_month[month]+1):
			if not isleap(year):
				if (month == 2 and day == 29):
					break;
			d = str(day)
			if (len(d) == 1):
				dd = '0' + d
			else:
				dd = d
			prefix = [M+d+yy,MM+d+yy,M+dd+yy,MM+dd+yy,M+d+yyyy,MM+d+yyyy,M+dd+yyyy,MM+dd+yyyy,
						d+M+yy,d+MM+yy,dd+M+yy,dd+MM+yy,d+M+yyyy,d+MM+yyyy,dd+M+yyyy,dd+MM+yyyy]
			time = set()
			for pre in prefix:
				for hour in range(1,25):
					h = str(hour % 13 + hour / 13)
					if (len(h) == 1):
						hh = '0'+h
					else:
						hh = h
					H = str(hour%24)
					if (len(H)) == 1:
						HH = '0'+ H
					else:
						HH = H
					tmp = pre[0:4]
					inv = tmp[::-1]
					mm = inv[:2]
					ss = inv[2:]
					if (int(mm)<60 and int(ss)<60):
						if HH+'.'+mm+'.'+ss in time:
							continue
						else:
							midh = pre[4:] + h
							midhh = pre[4:] + hh
							midH = pre[4:] + H
							midHH = pre[4:] + HH
							if (midh == midh[::-1] or midhh == midhh[::-1] or midH == midH[::-1] or midHH == midHH[::-1]):
								time.add(HH+'.'+mm+'.'+ss)
								result += 1

	print result