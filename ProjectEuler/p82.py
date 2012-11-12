import sys, heapq

matrix = [ map( int, line.rstrip().split(',') ) for line in open('matrix.txt','r').read().rstrip().split('\n') ]

def solve( si, sj ):
	cache = {}
	bound = 80
	heap = [ (matrix[si][sj],si,sj) ]
	best = {}
	best[(si,sj)] = matrix[si][sj]
	ret = 10 ** 100
	di = [ -1, 1, 0 ]
	dj = [ 0, 0, 1 ]
	while len( heap ) > 0:
		cost, i, j = heapq.heappop( heap )
		if j == bound-1:
			ret = min( ret, cost )
			continue
		if best[(i,j)] < cost:
			continue
		for disp in zip( di, dj ):
			ni, nj = i + disp[0], j + disp[1]
			if ni < 0 or ni >= bound: continue
			if nj < 0 or nj >= bound: continue
			new_cost = cost + matrix[ni][nj]
			if not best.has_key((ni,nj)) or best[(ni,nj)] > new_cost:
				best[(ni,nj)] = new_cost
				heapq.heappush( heap, (new_cost, ni, nj) )     
	return ret


best = 10 ** 100
for i in xrange(80):
	print i
	best = min( best, solve(i,0) )
print best
