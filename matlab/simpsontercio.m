function integral=simpsontercio(f,a,b)
f=inline(f);
integral=((b-a)/6)*(f(a)+4*f((a+b)/2)+f(b));
