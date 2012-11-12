import itertools, string

def canmake( f, s, sq ):
	def in_dice( n, d ):
		if n == '6' or n == '9': # 이 부분에서 실수를 했음, '6'만 처리해줘서 답이 제대로 안나왔어요.
			if '6' in d or '9' in d: return True
			else: return False
		return n in d

	def where( n, d ):
		if n == '6':
			if '6' in d: return d.index('6')
			if '9' in d: return d.index('9')
		if n in d:
			return d.index(n)
		return None

	for x in sq:
		if in_dice(x[0],f) and in_dice(x[1],s) : continue
		if in_dice(x[0],s) and in_dice(x[1],f) : continue
		return False

	print f, s
	for x in sq:
		if in_dice(x[0],f) and in_dice(x[1],s) :
			print x, where( x[0], f ), where( x[1], s )
		if in_dice(x[0],s) and in_dice(x[1],f) :
			print x, where( x[1], f ), where( x[0], s )

	return True
d = [ c for c in itertools.combinations(string.digits,6) ]
sq = [ '%02d' % (i*i) for i in xrange(1,10) ]

ret = [ ''.join(d[i])+" "+''.join(d[j]) for i in xrange(len(d)) for j in xrange(i,len(d)) if canmake(d[i],d[j],sq) ]

print "\n".join(ret)
print len( ret )
		

