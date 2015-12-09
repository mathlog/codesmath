#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define n 10

char*cadena;
char*cadena2;
double divi;
int punto_d,signo,numero;
double r,s,d;
double valor,valor2,valor3,valor4,resta;

float conversion(float w)
{
		int punto_d,signo;
		char*cadena;
		float r,s;
		cadena=fcvt(w,4,&punto_d,&signo);
		r=atof(cadena);
		w=r/10000;
		if (signo==1)
		    w = w * (-1);
		return(w);
}

void main()
{
		clrscr();
		int a,b,c,d,A,B,C,i,cont;
		float q,r,s,m,o,h;
		float fx[n],fy[n],x[n],ea[n],er[n],X;
		gotoxy(25,1);cout<<"axü-bxý+cx-d";
		gotoxy(25,2);cout<<"_xü-__xý+_x-_";
		gotoxy(55,1);cout<<"Xo = ";
		gotoxy(55,2);cout<<"X  = ";
		gotoxy(25,2);cin>>a;
		gotoxy(29,2);cin>>b;
		gotoxy(34,2);cin>>c;
		gotoxy(37,2);cin>>d;
		gotoxy(60,1);cin>>x[0];
		gotoxy(60,2);cin>>X;
		fx[0]=(a*(pow (x[0],3)))-(b*(pow (x[0],2)))+(c* x[0])-d;
		fx[0]=conversion(fx[0]);
		fy[0]=((a*3)*(pow (x[0],2)))-((b*2)*x[0])+c;
		fy[0]=conversion(fy[0]);
		cont=0;
		for (i=2; i<=n; i++)
		{
			x[i-1]  = x[i-2]-(fx[i-2]/fy[i-2]);
			x[i-1]  = conversion(x[i-1]);
			fx[i-1]=(a*(pow (x[i-1],3)))-(b*(pow (x[i-1],2)))+(c* x[i-1])-d;
			fx[i-1] = conversion(fx[i-1]);
			fy[i-1]=((a*3)*(pow (x[i-1],2)))-((b*2)*x[i-1])+c;
			fy[i-1] = conversion(fy[i-1]);
			ea[i-1] = X - x[i-1];
			ea[i-1] = conversion(ea[i-1]);
			er[i-1] = (ea[i-1]/X)*100;
			er[i-1] = conversion(er[i-1]);
			cont++;
			if  ((ea[i-1]==0) && (er[i-1]==0))
				i=n;
		}
		for (i=0; i<=cont; i++)
		{
	       ea[0]=0;er[0]=0;
	       gotoxy(45,5);cout<<"Error Absoluto";
	       gotoxy(65,5);cout<<"Error Relativo";
	       gotoxy(10,5);cout<<"fx";
	       gotoxy(18,5);cout<<"fy'";
	       gotoxy(30,5);cout<<"x";
	       gotoxy(2,5);cout<<"Aprox.";
	       gotoxy(2,7+i);cout<<    i;
	       gotoxy(8,7+i);cout<<    fx[i];
	       gotoxy(18,7+i);cout<<   fy[i];
	       gotoxy(30,7+i);cout<<   x[i];
	       gotoxy(45,7+i);cout<<   ea[i];
	       gotoxy(65,7+i);cout<<   er[i];
		}
		getch();
}
