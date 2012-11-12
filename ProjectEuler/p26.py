import sys

def cycle( n ):
	up = 1
	dn = n

	mod = {}
	i = 0
	while True:
		if up < dn:
			up *= 10
			continue
		up %= dn
		if mod.has_key( up ):
			return i - mod[ up ] 
		mod[ up ] = i
		up *= 10
		if up == 0:
			break
		i += 1
	return 0

best = 0
for n in xrange(2,1000):
	now_cycle = cycle( n )
	if best < now_cycle:
		best = now_cycle
		print "update", n, best
	

