def is_pal( n ):
	return str( n ) == str( n )[::-1]

def is_lychrel_num( n ):
	for iter in xrange(49):
		n += int( str(n)[::-1] )
		if is_pal( n ):
			return False
	return True

print [ is_lychrel_num( i ) for i in xrange(1,10**4) ].count(True)
