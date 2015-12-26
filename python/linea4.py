from math import log #clientes

from random import random,seed
l_s=1.5 
l_t=1.0
n=100
s=-(1./l_s)*log(random())
l=0
c=0
f=s
print("     Llegada    comienzo      terminacion")
print("%10.2f"%l,"%10.2f"%c,"%10.2f"%f)
for i in range(n):
    l=l-(1./l_t)*log(random())
    s=-(1./l_s)*log(random())
    c=max(l,f)
    f=c+s
    print("%10.2f"%l,"%10.2f"%c,"%10.2f"%f)
