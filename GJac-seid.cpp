/*Jacobi y Gauss-Seidel

*/
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <math.h>

#define ITERA 50   //despues de ITERA, el proceso es cancelado
#define Maxec 6  //numero maximo de ecuaciones

enum Boolean{False,True};

void lectura(double a[Maxec][Maxec+1],double x0[Maxec],double b[Maxec],int n)
{
int i,j;
clrscr();
cout<<"Por favor introduzca la matriz de coeficientes del sistema";
gotoxy(3+n*5,5);cout<<"= b";
gotoxy(3+(n/2)*5,5);cout<<"Ax";
for(i=0;i<n;i++)
   {
    for(j=0; j<n; j++)
	{
	 gotoxy(3+j*5,7+i);
	 scanf("%lf",&a[i][j]);
	}
    gotoxy(3+j*5,7+i);cout<<"= ";
    scanf("%lf",&b[i]);
   }
for(i=1; i<=n; i++)
   {
    printf("x0(%d) = ",i);
    scanf("%lf",&x0[i]);
   }
}
//---------------------------------------------------------------------------
int jacobi(double a[Maxec][Maxec+1],double x[Maxec],double b[Maxec],double x0[Maxec],int n)
{
int i,j,k,y;
double eps,s;
Boolean valver=False;
char c,cad[25]={0};
k=0;
y=4;
eps=1e-5;
clrscr();
textcolor(10);
gotoxy(30,1);cout<<"M‚todo de Jacobi";
textcolor(14);
gotoxy(45,24);cprintf("Presione una tecla para continuar...");
textcolor(15);
gotoxy(4,2);printf("k       x1        x2        x3         x4         x5       x6");
do{
   for(i=0; i<n; i++)
     {
      s=0;
      for(j=0; j<n; j++)
	 if((i-j)!=0)
	   s=s+a[i][j]*x0[j];
      x[i]=(b[i]-s)/a[i][i];
     }
   for(i=0; i<n; i++)
      {
       sprintf(cad,"%.4f",x[i]);
       x[i]=atof(cad);
       sprintf(cad,"%.4f",x0[i]);
       x0[i]=atof(cad);
      }

   for(i=0; i<n; i++)
      {
       if(fabs(x0[i]-x[i]) > eps)
	  valver=False;
       else
	  valver=True;
       x0[i]=x[i];
      }
   k++;
   gotoxy(2,y);cout<<k;
   for(i=0; i<n; i++)
      {
       gotoxy(8+i*11,y);printf("%5.4f",x[i]);
      }
   y++;
   c=getch();
   if(y>22)
     {
      y=4;
      clrscr();
      textcolor(10);
      gotoxy(30,1);cout<<"M‚todo de Jacobi";
      textcolor(14);
      gotoxy(45,24);cprintf("Presione una tecla para continuar...");
      textcolor(15);
      gotoxy(4,2);printf("k       x1        x2        x3         x4         x5       x6");
     }
   if (k>ITERA)
     c=27;
  }while(!(valver==True||c==27));
return k;
}
//---------------------------------------------------------------------------
int Gauss_Seidel(double a[Maxec][Maxec+1],double x[Maxec],double b[Maxec],double x0[Maxec],int n)
{
double s,eps;
Boolean valver=False;
char c,cad[25]={0};
int i,j,k,y;
k=0;
y=4;
eps=1e-5;
clrscr();
textcolor(10);
gotoxy(30,1);cout<<"M‚todo de Gauss Seidel";
textcolor(14);
gotoxy(45,24);cprintf("Presione una tecla para continuar...");
textcolor(15);
gotoxy(4,2);printf("k       x1        x2        x3         x4         x5       x6");
do{
   for(i=0;i<n;i++)
     x[i]=x0[i];
   for(i=0; i<n; i++)
     {
      s=0;
      for(j=0; j<n; j++)
	 if((i-j)!=0)
	   s=s+a[i][j]*x0[j];
      x0[i]=(b[i]-s)/a[i][i];
     }
   for(i=0; i<n; i++)
      {
       sprintf(cad,"%.4f",x[i]);
       x[i]=atof(cad);
       sprintf(cad,"%.4f",x0[i]);
       x0[i]=atof(cad);
      }
   for(i=0; i<n; i++)
      {
       if(fabs(x0[i]-x[i]) > eps)
	  valver=False;
       else
	  valver=True;
      }
   k++;
   if (k>ITERA)
     c=27;
   gotoxy(2,y);cout<<k;
   for(i=0; i<n; i++)
      {
       gotoxy(8+i*11,y);printf("%5.4f",x0[i]);
      }
   y++;
   c=getch();
   if(y>22)
     {
      y=4;
      clrscr();
      textcolor(10);
      gotoxy(30,1);cout<<"M‚todo de Gauss Seidel";
      textcolor(14);
      gotoxy(45,24);cprintf("Presione una tecla para continuar...");
      textcolor(15);
      gotoxy(4,2);printf("k       x1        x2        x3         x4         x5       x6");
     }
   if (k>ITERA)
     c=27;
  }while(!(valver==True||c==27));
return k;
}
//---------------------------------------------------------------------------
void enter(void)
{
int c;
do{
   if (kbhit())
     c=getch();
  }while(c!=13);
}
//---------------------------------------------------------------------------
void main(void)
{
double  x[Maxec]={0},x0[Maxec]={0},b[Maxec]={0};
double a[Maxec][Maxec+1]={0};
int op,n,k;

clrscr();
cout<<"             1 -   M‚todo de Jacobi\n";
cout<<"Otro numero    -   M‚todo de Gauss-Seidel\n\n";
cout<<"Su opcion es: ";

cin>>op;

gotoxy(1,5);cout<<"N£mero de ecuaciones ";
do{
  cin>>n;
  if (n>6)
    cout<<"El sistema debe tener menos de 6 ecuaciones por cuestiones \nde impresion en pantalla\nGracias";
    cout<<"\n\nN£mero de ecuaciones ";
  }while(n>6);
lectura(a,x,b,n);
clrscr();
textcolor(14);
gotoxy(10,12);cprintf("Si la solucion no converge, presione ESC para terminar");
textcolor(10);
gotoxy(1,24);cprintf("Presione ENTER para continuar...");
textcolor(7);
enter();
if (op==1)
   k=jacobi(a,x,b,x0,n);
else
   k=Gauss_Seidel(a,x,b,x0,n);

textcolor(15);
cout<<"\n";
cprintf("DESPUES DE %d ITERACIONES",k);
cout<<"\n";
cprintf("LA SOLUCION DEL SISTEMA ES : \n");   printf("\n");
for(k=0; k<n; k++)
   cprintf(" x(%d) = %10.4f",k+1,x0[k]),cout<<"\n";
getch();
}