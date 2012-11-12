import itertools

answers = {}
for perm in itertools.permutations( map( str, range(1,10) ) ):
	for first in xrange( 1, len(perm) ):
		for second in xrange( first+1, len(perm) ):
			multiplicand = int( "".join( perm[:first] ) )
			multiplier = int( "".join( perm[first:second] ) )
			product = int( "".join( perm[second:] ) )
			# print multiplicand, multiplier, product
			if multiplicand * multiplier == product:
				print multiplicand, multiplier, product
				answers[ product ] = True

print sum( answers.keys() )
	

"""
Result:
12 483 5796
138 42 5796
157 28 4396
159 48 7632
1738 4 6952
18 297 5346
186 39 7254
1963 4 7852
198 27 5346
27 198 5346
28 157 4396
297 18 5346
39 186 7254
4 1738 6952
4 1963 7852
42 138 5796
48 159 7632
483 12 5796
45228
"""
