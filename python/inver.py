from random import random
from math import log

def demanda(la):
    t=0
    j=0
    while t<1:
        j=j+1
        t=t-(1/la)*log(random())

    return j
n=100
la=90
S=100
sm=20
IO=S
i=0
I=IO

while i<n:
    i=i+1
    if I<sm:
        o=S-I
    else:
        o=0
    d=demanda(la)
    print(i,"%8.2f"%I,"%8.2f"%o,"%8.2f"%d)

    I=I+o-d
