import sys, heapq

matrix = [ map( int, line.rstrip().split(',') ) for line in open('matrix.txt','r').read().rstrip().split('\n') ]
cache = {}
bound = 80
heap = [ (matrix[0][0],0,0) ]
best = {}
best[(0,0)] = matrix[0][0]

di = [ -1, 1, 0, 0 ]
dj = [ 0, 0, -1, 1 ]
while len( heap ) > 0:
    cost, i, j = heapq.heappop( heap )
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

print best[(bound-1,bound-1)]
