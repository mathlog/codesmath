// FUNDAMENTOS DE ANALISIS NUMERICOS  5-dic-2003
// Programa de Interpolacion por el metodo de
// Lagrange

#include <conio.h>
#include <stdio.h>
//#include <math.h>

void main(void)
{
double x[10]={0},y[10]={0};
double xi,yi,z;
int i,j,orden;

clrscr();
printf("Orden de la interpolacion \n");
printf("O sea, Cuantos valores de x ? :");
scanf("%d",&orden);
for(i=0; i<orden; i++)
   {
    gotoxy(5,i+5);printf("x(%d) = ",i+1);
    scanf("%lf",&x[i]);
    gotoxy(20,i+5);printf("y(%d) = ",i+1);
    scanf("%lf",&y[i]);
   }
printf("Deme el valor de x para la interpolacion: ");
scanf("%lf",&xi);
yi=0;
for(i=0;i<orden;i++)
   {
    z=1;
    for(j=0;j<orden;j++)
	if(j!=i)
	   z=z*(xi-x[j])/(x[i]-x[j]);
    yi=yi+z*y[i];
   }
printf("PARA X =%10.4f   Y =%10.4f\n",xi,yi);
printf("\nPresione una tecla para continuar...");
getch();
}

