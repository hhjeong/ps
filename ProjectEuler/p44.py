import sys, itertools

penta = [ n * ( 3*n - 1 ) / 2 for n in xrange(1,3000) ]
penta_set = set( penta )


for p in itertools.combinations( penta, 2 ):
	if p[0] + p[1] in penta_set and p[1] - p[0] in penta_set:
		print p, p[1] - p[0]
