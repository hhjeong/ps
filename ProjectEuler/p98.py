words = [ w.replace("\"","") for w in open('words.txt','r').read().rstrip().split(",") ]

fq = {} 
for w in words:
	w = int( "".join([ str(ord(x) - ord('A') + 1) for x in w ]) )
	if fq.has_key(fq):
		fq[w] = 0 
	fq[ w ] += 1

for k in fq:
	if fq[ k ] > 1:
		print fq[ k ] 
