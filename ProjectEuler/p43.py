"""
import string, itertools, time

start = time.clock()
primes = [ 2, 3, 5, 7, 11, 13, 17 ]

ans = 0
for pd in itertools.permutations( string.digits ):
	if pd[0] == '0': continue
	pd = "".join(pd)
	if [ int(pd[i+1:i+4]) % primes[i] == 0 for i in xrange(7) ].count(False) == 0:
		print pd
		ans += int( pd )
print ans
print "elapesed time", time.clock() - start 
"""

import string, itertools, time, PrimeNumber

def solve( num, primes, ret = 0 ):
	if len( primes ) == 0:
		print int( num )
		return int( num )
	if primes[0] == 0:
		for d in string.digits[1:]: ret += solve( num + d, primes[1:] )
	else:
		for d in [ x for x in string.digits if not x in num ]: 
			if int( num[-2:] + d ) % primes[0] == 0:
				ret += solve( num + d, primes[1:] )
	return ret

start = time.clock()

print "elapesed time", time.clock() - start
