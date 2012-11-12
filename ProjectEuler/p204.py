import PrimeNumber, collections

primes = PrimeNumber.get_primes( 100 )

queues = {}
for p in primes:
	queues[p] = collections.deque()
	queues[p].append( p )

howmany = 1
while True:
	howmany += 1
	mini = 0
	for p in primes:
		if len( queues[p] ) == 0: continue
		if mini == 0 or queues[p][0] < queues[mini][0]:
			mini = p
	top = queues[mini][0]

	if howmany % 100 == 0:
		print howmany, top
	queues[mini].popleft()
	if top >= 10 ** 9:
		break
	for p in primes:
		if mini <= p and top * p <= 10 ** 9:
			queues[p].append( top * p )

print howmany
	
	
