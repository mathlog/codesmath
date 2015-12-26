from random import random  
from math import log 

def demanda():
    t=0 
    j=0
    while t<1:
        j=j+1
        t=t-(1/la)*log(random())
    return j
n=100
la=90  
S=100 
s=20
I0=S 
i=0
I=I0 

while i<n:
    i=i+1
    if I<s:
        o=S-I
    else:
        o=0
    d=demanda()
    print(i,"%10.2f"%I,"%10.2f"%o,"%10.2f"%d)
    I=I+o-d



