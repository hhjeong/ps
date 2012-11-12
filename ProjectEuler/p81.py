cache = {}
matrix = [ map( int, line.split(',') ) for line in open('matrix.txt','r').read().rstrip().split('\n') ]

def solve( i, j ):
	if i == 79 and j == 79:
		return matrix[i][j]
	pos = (i,j)
	if cache.has_key( pos ):
		return cache[ pos ]
	cache[ pos ] = 10 ** 100
	if i + 1 <= 79:
		cache[ pos ] = min( cache[pos], solve( i+1,j ) + matrix[i][j] )
	if j + 1 <= 79:
		cache[ pos ] = min( cache[pos], solve( i,j+1 ) + matrix[i][j] )
	return cache[ pos ] 
		
print solve( 0, 0 )
