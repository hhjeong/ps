import sys

cache = {} 

	
def calc_digit_square( n ):
	return sum([ int(d)**2 for d in str(n) ])

def solve( n ):
	# print n,
	if n == 89:
		return True
	if not cache.has_key( n ):
		cache[ n ] = False
		cache[ n ] = solve( calc_digit_square( n ) )
		return cache[ n ]
	else:
		return cache[ n ]

"""
ret = 0
for i in xrange(1,10**7):
	if solve( i ):
		ret += 1

print ret
"""

print [ solve(i) for i in xrange(1,10**7) ].count( True )
"""
Result: just iteration
real    2m20.895s
user    2m18.560s
sys     0m2.200s
"""

"""
Result: with list
real    2m19.569s
user    2m16.990s
sys     0m2.490s
"""
