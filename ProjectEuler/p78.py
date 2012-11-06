cache = {}

def solve( n, m ):
	if n == 0:
		return 1
	state = (n,m)

	if cache.has_key(state):
		return cache[state]
	cache[state] = 0
	for i in xrange(m,-1,-1):
		remain = n - i
		if remain < 0:
			break
		cache[state] += solve( remain, i )
	return cache[state]

def A000041(n):
	if n == 0:
		return 1
	if cache.has_key(n):
		return cache[n]
	S = 0
	J = n-1
	k = 2
	while 0 <= J:
		T = A000041(J)
		if k/2 % 2 == 1:
			S = S + T
		else:
			S = S - T
		if k % 2 == 1:
			J -= k
		else:
			J -= k / 2
		k += 1
	cache[n] = S
	return cache[n]


for i in xrange(1,100001):
	# ret = solve(i,i)
	ret = A000041(i)
	print i, ret
	if ret % 10**6 == 0:
		print i, ret
		break
