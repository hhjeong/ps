import fractions

for nu in xrange(11,99):
	for de in xrange(nu+1,100):
		str_nu = str( nu )
		str_de = str( de )
		for digit in "123456789":
			if digit in str_nu and digit in str_de:
				str_nu = str_nu.replace( digit, "" )
				str_de = str_de.replace( digit, "" )
				if str_nu == "" or str_de == "":
					continue
				if str_de == "0":
					continue
				org_frac = fractions.Fraction( nu, de )
				aft_frac = fractions.Fraction( str_nu + "/" + str_de )
				if org_frac == aft_frac:
					print org_frac, nu, de

"""
387296/38729600
"""
