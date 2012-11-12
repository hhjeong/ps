import math

def isprime( n ):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    sqrt_n = int(math.sqrt(n))
    for i in xrange(3,sqrt_n+1,2):
        if n % i == 0:
            return False
    return True

print 23+37+53+73+313+317+373+797+3137+3797+739397
s = "123456"
print [ s[:i+1] for i in xrange( len(s) ) ]
print [ s[i:] for i in xrange( len(s) ) ]

"""
n = 10
while True:
    str_n = str( n )
    
    if isprime( n ) and [ isprime( int(str_n[:i+1]) ) for i in xrange(len(str_n)) ].count( False ) == 0 and [ isprime( int(str_n[i:]) ) for i in xrange(len(str_n)) ].count( False ) == 0:
        print n
    n += 1
"""
