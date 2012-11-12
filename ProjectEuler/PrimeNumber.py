import math

def sieve( n ):
	isprime = [ True ] * ( n+1 )
	isprime[0] = isprime[1] = False
	isprime[4::2] = [False] * len( isprime[4::2] )
	
	sqrt_n = int( math.sqrt( n ) )
	for i in xrange( 3, sqrt_n+1, 2 ):
		if isprime[i]:
			isprime[2*i::i] = [False] * len(isprime[2*i::i])
	return isprime

def get_primes( n ):
	isprime = sieve( n )
	return [ x for x in xrange( len(isprime) ) if isprime[x] ]

def isprime( n ):
	if n < 2:
		return False
	if n == 2:
		return True
	if n % 2 == 0:
		return False
	i = 3
	return [ n % i == 0 for i in xrange( 3, int( math.sqrt(n) )+1, 2 ) ].count(True) == 0
