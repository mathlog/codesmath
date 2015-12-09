/*FUNDAMENTOS DE ANALISIS NUMERICOS.
  ING. JORGE ELOY TOLEDO CORONEL.
  INGENIERIA EN SISTEMAS COMPUTACIONALES.
*/
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iostream.h>
void main()
{
double x[10]={0},y[10]={0};
double xi,yi,d;
int i,j,no;

clrscr();
gotoxy(20,2);cout<<"** METODO DE LAGRANGE **";
gotoxy(20,5);cout<<"No. de valores para X y Y";
gotoxy(30,6);cin>>no;
gotoxy(25,8);cout<<"X";gotoxy(35,8);cout<<"Y";
for(i=0; i<no; i++)
   {
      gotoxy(25,i+10);cin>>x[i];
      gotoxy(35,i+10);cin>>y[i];
   }
gotoxy(60,9);cout<<"x =  ";
gotoxy(66,9);cin>>xi;
yi=0;
for(i=0;i<no;i++)
   {
    d=1;
    for(j=0;j<no;j++)
	if(j!=i)
	   d=d*(xi-x[j])/(x[i]-x[j]);
    yi=yi+d*y[i];
   }
gotoxy(20,20);cout<<" X = "<<xi<<"          Y = "<<yi;
gotoxy(60,24);cout<<"P/enter";
getch();
}

