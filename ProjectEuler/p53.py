cache = {}

def combination( n, r ):
	global cache
	if n == 0 or r == 0 or r == n:
		return 1
	if r == 1:
		return n
	if cache.has_key( (n,r) ):
		return cache[(n,r)]
	cache[(n,r)] = combination(n-1,r-1) + combination(n-1,r)
	return cache[(n,r)]

ret = 0
for i in xrange(0,101):
	for j in xrange(0,i+1):
		if combination(i,j) >= 10**6:
			ret += 1
print ret

