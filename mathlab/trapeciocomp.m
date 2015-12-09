function integral=trapcomp(f,a,b,n)
f=inline(f);
h=(b-a)/n;
integral=f(a)+f(b);
for i=1:n-1
x=a+i*h;
integral=integral+2*f(x);
end
integral=(h/2)*integral;
