#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream.h>
#include <math.h>
#define n 10
char*cadena;
char*cadena2;
double divi;
int punto_d,signo,numero;
double r,s,d;
double valor,valor2,valor3,valor4,resta;
double conversion(float w)
	{
		int punto_d,signo;
		char*cadena;
		double r,s;
		cadena=fcvt(w,4,&punto_d,&signo);
		r=atof(cadena);
		w=r/10000;
		if (signo==1)
		    w = w * (-1);
		return(w);
	}
/*double conversion(double w)
{
       cadena=fcvt(valor,5,&punto_d,&signo);
       r=atof(cadena);
       valor2=r/100000;
       if (signo==1)
       valor2 = valor2 * (-1);
       divi=valor2/0.0001;
       cadena2=fcvt(valor,4,&punto_d,&signo);
       valor3=atoi(cadena2);
       resta= valor3 - divi;
       if (resta > 0 )
       {
	     w= (valor3 - 1)* 0.0001;
       }
       if (resta < 0)
       {
	     w = valor3 * 0.0001;
       }
       return(w);
}          */

void main()
{
	clrscr();
	int a,b,c,d,A,B,C,D,E,F,G,H,I,J,K,L,M,N,i,cont;
	float q,r,s,m,h,o;
	float fx[n],fx1[n],fx2[n],x[n],ea[n],er[n],X;
	gotoxy(25,1);cout<<"Metodo Newt¢n Raphson 2o. Orden";
	gotoxy(25,3);cout<<"axü-bxý+cx-d";
	gotoxy(25,4);cout<<"_xü-__xý+_x-_";
	gotoxy(55,3);cout<<"Xo = ";
	gotoxy(55,4);cout<<"X  = ";
	gotoxy(25,4);cin>>a;
	gotoxy(29,4);cin>>b;
	gotoxy(34,4);cin>>c;
	gotoxy(37,4);cin>>d;
	gotoxy(60,3);cin>>x[0];
	gotoxy(60,4);cin>>X;
	A =   (a*(pow (x[0],3)));
	B =   (b*(pow (x[0],2)));
	C =   (c* x[0]);
	fx[0]  = A-B+C-d;
	fx[0]  = conversion(fx[0]);
	D =    ((3*a)*(pow (x[0],2)));
	E =    ((2*b)*(x[0]));
	fx1[0] = A-B+c;
	fx1[0]  = conversion(fx1[0]);
	F =     (2*(3*a)*(x[0]));
	G =     (2*b);
	fx2[0] = A-B;
	fx2[0]  = conversion(fx2[0]);
	ea[0]  = (X - x[0]);
	er[0]  = (ea[i]/X)*100;
	for (i=1; i<=n; i++)
	{
		x[i]   = x[i-1] - ((fx[i-1])/((fx1[i-1]-(fx[i-1]*fx2[i-1]))/(2*fx1[i-1])));
		H =   (a*(pow (x[i],3)));
		I =   (b*(pow (x[i],2)));
		J =   (c* x[i]);
		fx[i]  = A-B+C-d;
		fx[i]  = conversion(fx[i]);
		K =    ((3*a)*(pow (x[0],2)));
		L =    ((2*b)*(x[0]));
		fx1[i] = A-B+c;
		fx1[i] = conversion(fx[i]);
		M =     (2*(3*a)*(x[0]));
		N =     (2*b);
		fx2[i] = A-B;
		fx2[i] = conversion(fx2[i]);
		ea[i]  = X-x[i] ;
		er[i]  = (ea[i]/X)*100;
		cont++;
		if  ((ea[i-1]==0) && (er[i-1]==0))
			i=n;
	}
		for (i=0; i<=n; i++)
		{

		       gotoxy(54,5);cout<<"Er Abs";
		       gotoxy(72,5);cout<<"Er Rel";
		       gotoxy(10,5);cout<<"fx";
		       gotoxy(15,5);cout<<"f'x";
		       gotoxy(25,5);cout<<"f''x'";
		       gotoxy(42,5);cout<<"x";
		       gotoxy(2,5);cout<<"Aprox.";
		       gotoxy(2,7+i);cout<<    i;
		       gotoxy(8,7+i);cout<<    fx[i];
		       gotoxy(15,7+i);cout<<   fx1[i];
		       gotoxy(25,7+i);cout<<   fx2[i];
		       gotoxy(40,7+i);cout<<   x[i];
		       gotoxy(52,7+i);cout<<   ea[i];
		       gotoxy(70,7+i);cout<<   er[i];
		}
	getch();
}
