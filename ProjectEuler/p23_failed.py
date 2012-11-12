limit = 28123

def is_abundant( n ):

	sum_div = 0

	i = 1
	while i * i <= n:
		if n % i == 0:
			sum_div += i
			if n / i != i:
				sum_div += n / i
		i += 1

	return sum_div > 2 * n

abundant = [ i for i in xrange(limit+1) if is_abundant(i) ]

ret = 0

abundant_dict = dict( zip( abundant, [True]*len(abundant) )  )

print ret
		
