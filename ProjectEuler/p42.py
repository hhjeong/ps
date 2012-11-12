trinum = [ i*(i+1)/2 for i in xrange(1,10001) ]

words = [ x.replace('"','') for x in open('words.txt','r').read().split(',') ]

ret = 0
for x in words:
	if sum([ ord(y)-ord('A')+1 for y in x ]) in trinum:
		ret += 1
print ret
