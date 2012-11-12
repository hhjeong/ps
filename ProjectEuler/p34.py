# answer : 40730
def factorial( n ):
	if n == 0:
		return 1
	return n * factorial(n-1)

def factsum( n ):
	return sum( [ factorial(int(digit)) for digit in str(n)] )


n = 9999999
print n > factsum( n )

ret = 0
for i in xrange(10,n+1):
	if i == factsum( i ):
		print i
		ret += i

