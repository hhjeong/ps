cache = {}

def solve( last, n ):
	if n == 0:
		return 1
	state = ( last, n )

	if cache.has_key( state ):
		return cache[ state ]
	cache[ state ] = 0
	for num in xrange( min(last,n) ,0,-1):
		cache[ state ] += solve( num, n - num )
	return cache[ state ]

print solve( 100, 100 )


