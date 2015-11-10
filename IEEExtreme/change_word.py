save = open("new_words2.txt", "w")

def ChangeWord(word, pos = 0):
	if pos == len(word):
		save.write("IEEE%sXtreme\n" % word)
		for i in range(10):
			save.write("IEEE%s%dXtreme\n" % (word, i))
		# for i in range(10):
		# 	save.write("IEEE%s0%dXtreme\n" % (word, i))
	else:
		if word[pos] == 'a':
			ChangeWord(word[:pos] + '4' + word[pos+1:], pos+1)
		elif word[pos] == 'e':
			ChangeWord(word[:pos] + '3' + word[pos+1:], pos+1)
		elif word[pos] == 'o':
			ChangeWord(word[:pos] + '0' + word[pos+1:], pos+1)
		elif word[pos] == 'i':
			ChangeWord(word[:pos] + '1' + word[pos+1:], pos+1)
		elif word[pos] == 'z':
			ChangeWord(word[:pos] + '5' + word[pos+1:], pos+1)
		elif word[pos] == 's':
			ChangeWord(word[:pos] + '2' + word[pos+1:], pos+1)
		ChangeWord(word, pos+1)

fp = open("wordsEn.txt", "r")
for word in fp:
	ChangeWord(word.strip())
fp.close()

for i in range(10):
	save.write("IEEE%dXtreme\n" % i)