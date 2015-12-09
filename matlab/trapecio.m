function integral=trapecio(f,a,b)
f=inline(f);
integral=((b-a)/2)*(f(a)+f(b));
