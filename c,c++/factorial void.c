//ddo un número entero y mayor que cero, muestre su factorial. (El factorial de 5 es 120; 5x4x3x2x1=120)

#include <stdio.h>
#include <conio.h>
int factorial (int num);
main()
{
int num, ban=1;
while(ban==1)
{
printf("Ingrese el valor del n£mero por favor:\n");
scanf("%d", &num);
while(num<0)
{
printf("ERROR, el valor del n£mero debe ser mayor que cero:\n");
scanf("%d", &num);
}
printf("El valor del factorial es %d\n\n", factorial (num));
printf("¨Desea Realizar otro calculo?Si=1 y No=0\n");
scanf("%d", &ban);
}
getch();
return 0;
}
int factorial (int num)
{
int sum=1, i;
for(i=2; i<=num; i++)
{
sum=sum*i;
}
return (sum);
}
