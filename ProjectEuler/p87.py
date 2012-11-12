import PrimeNumber, math

bound = 50 * 10 ** 6
print bound
primes = PrimeNumber.get_primes( int( math.sqrt(bound) ) )

s = set( [ p**2 + q**3 + r**4 for p in primes for q in primes if p**2+q**3 <= bound for r in primes if p**2+q**3+r**4 <= bound ] )

"""
for sq in [ p**2 for p in primes ]:
	for cb in [ q**3 for q in primes if sq + q**3 <= bound ]:
		for qd in [ r**4 for r in primes if sq + cb + r**4 <= bound ]:
			s.add( sq + cb + qd )
"""
print len( s )  

