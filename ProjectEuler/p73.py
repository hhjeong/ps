import fractions

lo = fractions.Fraction( 1, 3 )
hi = fractions.Fraction( 1, 2 )

ret = 0
for de in xrange(2,12001):
	for nu in xrange( de/3, de/2+1 ):
		if fractions.Fraction( nu, de ) >= hi: break
		if lo < fractions.Fraction( nu, de ) and fractions.gcd( nu, de ) == 1:
			ret += 1
	if de % 100 == 0:
		print de, ret	

print ret
