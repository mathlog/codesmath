#include <stdio.h>
#include <conio.h>
#include <math.h>
void seno (float angulo);
void coseno (float angulo);
void tangente (float angulo);
main()
{
float angulo;
int opcion, ban=1;
while(ban==1)
{
printf("\t\tBIENVENIDO/A\n\n");
printf("Introduzca el valor del angulo, por favor:\n");
scanf("%f", &angulo);
printf("¨Que desea hacer?:\n\n");
printf("********************************************\n");
printf("**** 1. seno del angulo ****\n");
printf("**** 2. coseno del angulo ****\n");
printf("**** 3. tangente del angulo ****\n");
printf("********************************************\n");
scanf("%d", &opcion);
while(opcion<0 || opcion>3)
{
printf("ERROR, la opcion debe estar entre 0 y 3:\n");
scanf("%d", &opcion);
}
clrscr();
switch(opcion)
{
case 1: seno (angulo);
break;
case 2: coseno (angulo);
break;
case 3: tangente (angulo);
break;
}
printf("¨Hay mas datos? (si=1 y no=0)\n");
scanf("%d",&ban);
}
getch();
return 0;
}
void seno (float angulo)
{
float y;
y=sin (angulo);
printf("El seno de %f es %f\n\n", angulo, y);
}
void coseno (float angulo)
{
float y;
y=cos(angulo);
printf("El coseno de %f es %f\n\n", angulo, y);
}
void tangente (float angulo)
{
float y;
y=tan(angulo);
printf("La tangente de %f es %f\n\n", angulo, y);
getch();
}
