
def fact( n ):
	if n <= 1: return 1
	return fact( n-1 ) * n

def next( n ):
	return sum([fact(d) for d in map(int,list(str(n)))]) 

def length( n ):

	visited = {}
	ret = 1
	s = n
	visited[s] = True
	while True:
		t = next( s )
		if n == t:
			break
		if visited.has_key(t):
			break
		ret += 1
		s = t
		visited[s] = True
	return ret

ret = 0
for i in xrange(1,10**6):
	if i % 10000 == 0:
		print i
	if length(i) == 60:
		print "found", i
		ret += 1
print ret
