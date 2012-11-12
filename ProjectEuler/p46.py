def is_square( n ):
    sqrt_n = int( math.sqrt(n) )
    return sqrt_n ** 2 == n

import math, sys

limit = 100000
sieve = [ True ] * (limit+1)
primes = [2]
sieve[0] = sieve[1] = False
sieve[4::2] = [False] * len(sieve[4::2])

for i in xrange(3,limit+1,2):
    if sieve[i]:
        primes.append( i )
        sieve[2*i::i] = [False] * len(sieve[2*i::i])

for i in xrange(9,limit,2):
    ok = False
    for p in primes:
        if i < p: break
        remain = i - p
        if remain % 2 == 0:
            if is_square( remain / 2 ):
                ok = True
                break
    if not ok:
        print i
        break
