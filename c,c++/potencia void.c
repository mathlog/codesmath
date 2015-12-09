#include <stdio.h>
#include <conio.h>
long int potencia (int base, int exponente);
main()
{
int base, exponente;
printf("La Base es:\n");
scanf("%d", &base);
while (base<0)
{
printf("ERROR, el dato debe ser mayor que cero:\n");
scanf("%d", &base);
}
printf("El Exponente es:\n");
scanf("%d", &exponente);
printf("%d ^ %d es %ld\n\n", base, exponente, potencia(base,exponente));
getch();
return 0;
}
long int potencia (int base, int exponente)
{
long int sum=0, i,x;
for(i=1; i<exponente; i++)
{
x=base*base;
sum=sum+x;
}
return (sum);
}



