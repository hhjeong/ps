sq = ['GO','A1','CC1','A2','T1','R1','B1','CH1','B2','B3','JAIL','C1','U1','C2','C3','R2','D1','CC2','D2','D3','FP','E1','CH2','E2','E3','R3','F1','F2','U2','F3','G2J','G1','G2','CC3','G3','R4','CH3','H1','T2','H2']

def next_x( s, p ):
	for i in xrange(p+1,40):
		if sq[i][0] == s:
			return i
		return -1

sym = {}

for i in xrange( len(sq) ): sym[ sq[i] ] = i

c = [ 0 ] * 40
nd = 6

def roll( ntries, where ):
	if ntries == 3:
		c[sym['JAIL']] += 1
	else:
		for f in xrange(1,nd+1):
			for s in xrange(2,nd+1):
				if f == s:
					roll( ntries+1, ( where + f + s ) % 40 )
				else:
					p = ( where + f + s ) % 40
					if "CC" in sq[p]:
						c[sym['GO']] += 1 / 16.0 
						c[sym['JAIL']] += 1 / 16.0
						c[p] += 14 / 16.0
					elif "CH" in sq[p]:
						c[sym['GO']] += 1 / 16.0 
						c[sym['JAIL']] += 1 / 16.0 
						c[sym['C1']] += 1 / 16.0
						c[sym['E3']] += 1 / 16.0
						c[sym['H2']] += 1 / 16.0 
						c[sym['R1']] += 1 / 16.0
						c[next_x("R",p)] += 2 / 16.0 
						c[next_x("U",p)] += 1 / 16.0
						c[(p-3+40)%40] += 1 / 16.0
						c[p] += 6 / 16.0
					else:
						c[p] += 1
roll( 0, 0 )
tot = sum( c )

print tot

for i in xrange( 40 ):
	print sq[i], 100.0 * c[i] / tot
