function integral=simpsonterciocomp(f,a,b,n)
f=inline(f);
h=(b-a)/n;
integral=f(a)+f(b);
for i=1:n/2
x=a+(2*i+1)*h;
integral=integral+4*f(x);
end
for i=1:(n/2)-1
x=a+2*i*h;
integral=integral+2*f(x);
end
integral=(h/3)*integral;
