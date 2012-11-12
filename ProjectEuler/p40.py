i = 0
number = " "
while True:
	i += 1
	number += str( i )
	if len( number ) >= 10**6+1:
		break

ret = 1

for i in xrange(0,7):
	ret *= int( number[10**i] )

print ret
