# Tn+2 = (Tn+1)2 + Tn
x=(input())
x=x.split()
a=int(x[0])
b=int(x[1])
n=int(x[2])
for i in range(2,n):
    c=b*b+a
    a=b
    b=c
        
print (c)
