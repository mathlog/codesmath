/*FUNDAMENTOS DE ANALISIS NUMERICOS.
  ING. JORGE ELOY TOLEDO CORONEL.
  ING. SISTEMAS COMPUTACIONALES.
*/

#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <math.h>
#define aprox 50   // 50 aproximaciones
#define noecu 6  //numero maximo de ecuaciones
enum Boolean{False,True};

void leer(double a[noecu][noecu+1],double x0[noecu],double b[noecu],int n)
{
int i,j;
clrscr();
gotoxy(20,2);cout<<" introduzca la matriz de coeficientes del sistema";
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

void prestecla(void)
{
int c;
do{
   if (kbhit())
   {
     c=getch();
   }
   }while(c!=13);
}

void main(void)
{
double  x[noecu]={0},x0[noecu]={0},b[noecu]={0};
double a[noecu][noecu+1]={0},s,eps;
int y,i,j,k,n;
Boolean volver=False;
char c,cad[25]={0};
clrscr();
gotoxy(30,1);cout<<"M‚todo de Gauss Seidel";
gotoxy(1,5);cout<<"N£mero de ecuaciones ";
do{
  cin>>n;
  if (n>6)
    cout<<"\aEl sistema debe tener menos de 6 ecuaciones  ";
    cout<<"\n\nN£mero de ecuaciones ";
  }while(n>6);
leer(a,x,b,n);
clrscr();
gotoxy(10,12);cout<<"Si la solucion no converge, presione ESC para terminar";
gotoxy(50,24);cout<<"P/ enter para continuar";
prestecla();
k=0;
y=5;
eps=1e-5;
clrscr();
gotoxy(20,1);cout<<"** M‚todo de Gauss Seidel **";
gotoxy(45,24);cout<<"Presione una tecla para continuar";
gotoxy(4,3);cout<<"k       x1        x2        x3         x4         x5       x6";
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
	  volver=False;
       else
	  volver=True;
      }
   k++;
   if (k>aprox)
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
      y=5;
      clrscr();
      gotoxy(20,1);cout<<"** M‚todo de Gauss Seidel **";
      gotoxy(45,24);cout<<"Presione una tecla para continuar";
      gotoxy(4,3);cout<<"k       x1        x2        x3         x4         x5       x6";
     }
   if (k>aprox)
     c=27;
  }while(!(volver==True||c==27));
cout<<"\n";
cout<<"despues de "<<k <<" aproximaciones ";
cout<<"\n";
cout<<"la solucion del sistema es : \n";
for(i=0; i<n; i++)
   cprintf(" x(%d) = %10.4f",i+1,x0[i]),cout<<"\n";
getch();
}

