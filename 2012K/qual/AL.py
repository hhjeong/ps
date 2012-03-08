import sys, math, time

inp = open('AL.in','r')
oup = sys.stdout

rl = lambda : inp.readline().strip()
def main():
    start_time = time.time()

    ncase = int( rl() )
    for caseno in xrange( 1, ncase+1 ):
        N, D, W = map( int, rl().split() )

        NN = N
        nmod = 0
        
        visited = {}
        ans = []
        while NN > 0:
            if visited.has_key( nmod ):
                break

            nlines = ( nmod + D ) / W 
            if ( nmod + D ) % W > 0:
                nlines += 1
            ans.append( ( nmod, nlines ) )
            visited[ nmod ] = True
            nmod = ( nmod + D ) % W
            NN -= 1
        
        # print ans, N/W, N%W
        ret = sum([ v for m, v in ans ]) * ( N/len(ans) ) + sum([ v for m, v in ans[:(N%len(ans))] ]) 
        
        print >> oup, "Case #%d:"%(caseno),
        print >> oup, ret
        # print >> sys.stderr, "%d/%d" % ( caseno, ncase )

    print >> sys.stderr, "Elapsed time : %.3fsec" % ( time.time() - start_time )   
if __name__ == "__main__":
    main()

