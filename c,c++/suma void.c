//dados dos números enteros determine la suma y cual de ellos es mayor, usando dos funciones diferentes.//

#include <stdio.h>
#include <conio.h>
void suma (int a, int b); /*Declaraci¢n de la funci¢n*/
void mayor (int a, int b); /*Tipo de dato, nombre de la funci¢n y el tipo y nombre de los argumentos*/
main()
{
int a, b;
printf("Ingrese el valor de a:\n");
scanf("%d", &a);
printf("Ingrese el valor de b:\n");
scanf("%d", &b);
suma(a,b); /*Llamado de la funci¢n*/
mayor(a,b); /*Unicamente el nombre de la funci¢n y de los par metros*/
getch();
return 0;
}
void suma(int a, int b) /*Definici¢n de la funci¢n*/
{ /*Abrimos llaves al inicio de la definici¢n*/
int sum; /*Declaraci¢n de las variables locales*/
sum=a+b;
printf("El valor de la suma es %d:\n\n", sum);
} /*Fin de la funci¢n suma*/
void mayor(int a, int b)
{
if(a==b)
printf("Son iguales\n\n");
else
{
if(a>b)
printf("El valor de a es mayor que el de b\n\n");
else
printf("El valor de b es mayor que el de a\n\n");
}
}


