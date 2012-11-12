import itertools, string


def chk( n ):
    hidden = "1_2_3_4_5_6_7_8_9_0"
    for x, y in zip( hidden, str( n ) ):
        if x == '_': continue
        if x != y:
            return int(x)-int(y)
    return 0

num = 10 ** 9

print ( 2 * 10 ** 9 - 10 ** 9 ) / 10
while num < 2 * 10 ** 9:
    if chk( num*num ) == 0:
        print num, num * num
        break
    num += 10
print "finish!"
        
    
