import fractions

target = fractions.Fraction( 3, 7 )

print target
diff = None
best = None
for de in xrange( 2, 10**6+1 ):
	if de == 7:
		continue
	nu = 3 * de / 7
	while 1 <= nu:
		if fractions.gcd( nu, de ) == 1:
			now = fractions.Fraction( nu, de )
			if best is None or diff > target - now:
				diff = target - now
				best = now
				print "update", best, diff
			break
		nu -= 1
	# print de
print best
