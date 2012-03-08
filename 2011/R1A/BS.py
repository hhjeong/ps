import sys, re

rl = lambda : sys.stdin.readline().strip()

def cmp( bucket, target ):
    for i in xrange( len( bucket ) ):
        if bucket[i] == '_':
            continue
        if bucket[i] != target[i]:
            return False
    return True

def get_index( target, letter ):
    return [ i for i, l in enumerate(target) if l == letter ] 

def get_losing_point( ans, words, strategy ):
    words = [ w for w in words if len(ans) == len(w) ]
    lose_point = 0
 
    bucket = [ '_' for i in xrange( len(ans) ) ]
    for s in strategy:
        guess = None
        for w in words:
            if w.count(s) > 0 and cmp( bucket, w ):
                guess = w
                break

        # print s, guess
        if guess is None:
            continue
        elif ans.count(s) > 0:
            for i in xrange( len(ans) ):
                if ans[i] == s:
                    bucket[i] = s
            words = [ w for w in words if cmp( bucket, w ) ]
            words = [ w for w in words if w.count(s) == 0 or ( get_index( w, s ) == get_index( ans, s )  ) ]
        else:
            words = [ w for w in words if w.count(s) == 0 ]
            lose_point += 1

        if ans == "".join(bucket):
            break

    return lose_point

def solve( words, strategy ):
    ans = sorted( [ [ -get_losing_point( w, words, strategy ), i, w ] for i, w in enumerate(words) ] )
    return ans[0][2]

ncase = int( rl() )

for caseno in xrange(1,ncase+1):
    N, M = map( int, rl().split() )
    words = [ rl() for i in xrange(N) ]
    ans = [ solve( words, rl() ) for i in xrange(M) ]
    print "Case #%d:"%caseno, " ".join(ans)
