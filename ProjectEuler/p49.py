import itertools, string, PrimeNumber
# combinations_with_replacement is in ver 2.7 not 2.6
for c in itertools.combinations_with_replacement( string.digits, 4 ):
	if c[0] == '0': continue
	primes = [ int("".join(p)) for p in itertools.permutations( c ) if PrimeNumber.isprime( int("".join(p)) ) ]
	for three in itertools.combinations( primes, 3 ):
		three = map( int, three )
		if three[2] - three[1] == three[1] - three[0] and three[2] - three[1] > 0:
			print three, "".join( map(str,three) )
