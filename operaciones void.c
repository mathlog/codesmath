#include <stdio.h>
#include <conio.h>
#include <math.h>
double raiz(float a, float b);
double valor_absoluto(float a, float b);
double exponente (float a, float b);
main()
{
float a, b;
printf("\t\tBIENVENIDO\n\n");
printf("Ingrese el valor de a, por favor:\n");
scanf("%f", &a);
printf("Ahora el valor de b:\n");
scanf("%f", &b);
printf("El resultado de la ra¡z cuadrada de %.2f + %.2f es %.2f\n\n", a,b,raiz(a,b));
printf("|%.2f-%.2f| es igual a %.2f\n\n", a,b,valor_absoluto(a,b));
printf("%.2f^%.2f es igual a %f\n\n", a,b,exponente(a,b));
getch();
return 0;
}
double raiz(float a, float b)
{
float x;
double y;
x=a+b;
y=sqrt(x);
return (y);
}
double valor_absoluto(float a, float b)
{
float x;
double y;
x=a-b;
y=fabs(x);
return (y);
}
double exponente (float a, float b)
{
double x;
x=pow(a,b);
return (x);
}

