# consider 200 as a coin wtf
cache = {}

coins = [ 200, 100, 50, 20, 10, 5, 2, 1 ]
def solve( need, where ):
        if need < 0:
                return 0
        if where == len( coins ):
                return need == 0
        if cache.has_key( (need,where) ):
                return cache[(need,where)]
        cache[(need,where)] = 0
        cache[(need,where)] += solve( need-coins[where], where )
        cache[(need,where)] += solve( need, where+1 )
        return cache[ (need,where) ]

print solve( 200, 0 )
        
	
