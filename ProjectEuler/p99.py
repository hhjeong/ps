import math

best = -1
base, exp = 0, 0

i = 0
for line in open('base_exp.txt','r'):
    now_base, now_exp = map( int, line.rstrip().split(',') )
    i += 1
    if best == -1:
        best = i
        base, exp = now_base, now_exp
    else:
        if math.log(base) * exp < math.log(now_base) * now_exp:
            best = i
            base, exp = now_base, now_exp
print best        
