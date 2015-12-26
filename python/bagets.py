from random import random
c=0
k=0
y=random()
x=random()
z=0
p=0
print(x)
if (x<=0.35):
   c=8
elif (x>0.35 and x<=0.65):
   c=10
elif (x>0.65 and x<=0.90):
   c=12
elif (x>0.90 and x<=1):
   c=14
z=c

print(y)
if (y<=0.4):
   k=1
elif (y>0.4 and y<=0.7):
   k=2
elif (y>0.7 and y<=0.90):
   k=3
elif (y>0.90 and y<=1):
   k=3
p=k

print(z)
print(p)


           
