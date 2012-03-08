import sys, math, time

inp = open('C.in','r')
oup = sys.stdout

rl = lambda : inp.readline().strip()
def main():
    start_time = time.time()

    ncase = int( rl() )
    for caseno in xrange( 1, ncase+1 ):
        print >> oup, "Case #%d:"%(caseno),
        print >> oup
        print >> sys.stderr, "%d/%d" % ( caseno, ncase )

    print >> sys.stderr, "Elapsed time : %.3fsec" % ( time.time() - start_time )   
if __name__ == "__main__":
    main()

