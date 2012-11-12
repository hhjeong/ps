import math

for n in xrange(1,10):
	for num in xrange( 1, 10 ):
		print n, num, math.log( num, 10 ) * n
