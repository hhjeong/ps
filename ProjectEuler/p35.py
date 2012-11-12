import sys, math

def sieve( n ):
	ret = [ True ] * (n+1)
	ret[0] = ret[1] = False
	ret[4::2] = [False] * len( ret[4::2] )

	root_n = int( math.sqrt(n) )
	for i in xrange(3,root_n+1,2):
		if ret[i]:
			ret[2*i::i] = [False] * len( ret[2*i::i] ) 

	return ret

def is_prime( n ):
	if n < 2:
		return False
	if n == 2:
		return True
	if n % 2 == 0:
		return False
	root_n = int( math.sqrt(n) )
	return [ True for i in xrange(3,root_n+1,2) if n % i == 0 ].count(True) == 0 
def is_circular_prime( n ):
	d = str( n )
	return [ is_prime( int( d[i:] + d[:i] ) ) for i in xrange(len(d)) ].count(False) == 0

primes = sieve(10**6)

print len([ i for i in xrange(10**6) if primes[i] and is_circular_prime(i) ])

