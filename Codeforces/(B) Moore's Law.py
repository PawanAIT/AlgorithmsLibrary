from decimal import *
getcontext().prec = 28
a = map(float,raw_input().split(' '))
print "%.28f"%((a[0])*(1.000000011)**a[1])
