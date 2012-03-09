# http://code.activestate.com/recipes/577821-integer-square-root-function/
def isqrt( x ):
    n = x
    if n == 0:
        return 0
    a, b = divmod( n.bit_length(), 2 )
    x = 2**(a+b)
    while True:
        y = ( x + n/x ) / 2
        if y >= x:
            return x
        x = y

def solve( inp ):
    lower = int( inp.replace('?','0'), 2 )

    n = isqrt( int( inp.replace('?','0'), 2 ) )
    while True:
        cand =  bin(n * n).replace('0b','')
        if len(cand) > len(inp):
            break
        if [ b == '?' or a == b for a, b in zip(cand,inp) ].count( True )  == len( inp ):
            return str( cand )
        n += 1
    return "NONE"

import sys
for caseno, inp in enumerate( [ line.strip() for line in sys.stdin.read().strip().split('\n') ] ):
    if caseno == 0:
        continue
    print "Case %d: %s" % ( caseno, solve( inp ) )

