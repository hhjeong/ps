import PrimeNumber, time


start = time.time()
def num_cycle( a, b, n = 0 ):
	while True:
		if not PrimeNumber.isprime( n**2 + a*n + b ):
			break
		n += 1
	return n


max_n = 0

for a in xrange(-1000,1000):
	for b in xrange(-1000,1000):
		n = num_cycle( a, b )
		if max_n < n:
			max_n = n
			print "update:", a*b, max_n

print time.time() - start 
"""
Answer : -59231
sqrt version : 12sec
"""



