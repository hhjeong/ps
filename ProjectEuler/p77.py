import PrimeNumber

def solve( where, remain, primes, cache ):
    if where >= len( primes ):
        if remain == 0:
            return 1
        else:
            return 0
    state = ( where, remain )
    if cache.has_key( state ):
        return cache[ state ]
    cache[ state ] = 0
    if remain - primes[where] >= 0:
        cache[ state ] += solve( where, remain - primes[where], primes, cache )
    cache[ state ] += solve( where+1, remain, primes, cache )
    return cache[ state ] 

def get_numways( n ):
    primes = PrimeNumber.get_primes( n )[::-1]
    cache = {}
    ret = solve( 0, n, primes, cache )
    return ret

for i in xrange(1,101):
    if get_numways( i ) > 5000:
        print i, get_numways( i )
        break

