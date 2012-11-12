import itertools, string

cubes = {}
for num in xrange(0,100000):
	c = list(str( num ** 3 ))
	c.sort()
	c = "".join(c)
	if not cubes.has_key(c):
		cubes[ c ] = []
	cubes[ c ].append( num )

mini = -1
for k in cubes:
	if len( cubes[k] ) == 5:
		if mini == -1 or mini > cubes[k][0]:
			mini = cubes[k][0]
print mini ** 3
