#include <stdio.h>
#include <conio.h>
void primo (int numero);
main()
{
int numero, ban=1;
clrscr();
while(ban==1)
{
printf("Introduzca el n£mero por favor:\n");
scanf("%d", &numero);
while(numero<0)
{
printf("ERROR, el valor del n£mero debe ser mayor que cero\n");
scanf("%d", &numero);
}
primo(numero);
printf("&uml;Otro n£mero (si=1 y No=0)?\n");
scanf("%d", &ban);
}
getch();
return 0;
}
void primo (int numero)
{
int div, primo=1;
for(div=2; div<numero; div++)
{
if(numero%div==0)
{
primo=0;
printf("%d NO es primo\n\n\n", numero);
return 0;
}
else
primo=1;
}
if(primo!=0)
printf("%d es primo\n\n\n", numero);
}


