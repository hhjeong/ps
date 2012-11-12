import itertools, sys

# by ipkn
def partition(s, n):
	if n == 1:
		yield [s]
	else:
		for i in xrange(1,len(s)):
			l = s[:i]
			for x in partition(s[i:], n-1):
				yield [l] + x
 
best = ""
for pandigit in [ "".join(x) for x in itertools.permutations( "123456789" )][::-1]:
	for n in xrange(2,10):
		sumn = n * (n+1) / 2
		for part in partition( "".join( pandigit ), n ):
			sumpart = sum( map( int, part ) )
			if sumpart % sumn == 0:
				x = sumpart / sumn
				if [ x * i == int( part[i-1] ) for i in xrange(1,n+1) ].count(False) == 0:
					print "".join(pandigit), part, n
					sys.exit(0)

