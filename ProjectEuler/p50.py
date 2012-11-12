import PrimeNumber

limit = 10**6

primes = PrimeNumber.get_primes( limit )
sieves = PrimeNumber.sieve( limit )


best_length = 0
best_prime = 0

for i in xrange( len(primes) ):
	cand = 0
	for j in xrange( i, len(primes) ):
		cand += primes[j]
		if cand >= limit:
			break
		if sieves[ cand ]:
			length = j - i + 1
			if best_prime == 0 or best_length < length:
				best_length = length
				best_prime = cand

print best_prime, 'length is', best_length
	
