function integral=simpsontresoctavos(f,a,b)
f=inline(f);
integral=((b-a)/8)*(f(a)+3*f(a+(b-a)/3)+3*f(a+2*(b-a)/3)+f(b));
