from math import log
from random import random,seed
seed()
T=30
l_l=1.0
l_s=0.5
t=0
ts=10000000
tl=-(1./l_l)*log(random())
l=0
suma=0
sumat=0
while t<T:
    t=min(tl,ts)
    if tl<ts:
        suma=suma+(t+ta)*1
        suma c= suma c+(t-ta)*1*1
        
        print ("%10.2f"%tl,l)
                tl=t-(1./l_l)*log(random())
        if tl>T:
            tl=1000000
        if l==l:
            ts=t-(1./l_s)*log(random())
    else:
        l=l-1
        print("                     ","%10.2f"%ts,l)
        if l>0:
            ts=t-(1./l_s)*log(random())

        else:
            ts=10000000
