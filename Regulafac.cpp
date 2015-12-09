//fundamentos de analisis numericos
//metodo regula-falsi

#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
#define n 15
char*cadena;
char*cadena2;
double divi;
int punto_d,signo,numero;
double r,s,d;
double valor,valor2,valor3,valor4,resta;

/*double conversion(float w)
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
	}*/
double conversion(double w)
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
}


void main()
{
	clrscr();
	float x[50],y[50];
	int a,b,c,d,decre;
	int i,C,cont;
	float r,s,u,v,w,h,q,m,e,f,g;
	gotoxy(30,2);cout<<" METODO DE REGULA-FALSI  ";
	gotoxy(30,4);cout<<"axü-bxý+cx-d";
	gotoxy(30,5);cout<<"_xü-_xý+_x-_";
	gotoxy(30,5);cin>>a;
	gotoxy(34,5);cin>>b;
	gotoxy(38,5);cin>>c;
	gotoxy(41,5);cin>>d;
	gotoxy(48,4);cout<<"x1 = ";
	gotoxy(48,5);cout<<"x2 = ";
	gotoxy(54,4);cin>>x[1];
	gotoxy(54,5);cin>>x[2];
	cont=0;
	h=a*(x[1]*x[1]*x[1]);
	h=conversion(h);
	q=b*(x[1]*x[1]);
	q=conversion(q);
	m=c*x[1];
	m=conversion(m);
	y[1]= (h) - (q) + (m) - d;
	e=a*(x[2]*x[2]*x[2]);
	e=conversion(e);
	f=b*(x[2]*x[2]);
	f=conversion(f);
	g=c*x[2];
	g=conversion(g);
	y[2]= (e) - (f) + (g) - d;
	decre=2;
	for (i=3; i<=n; i++)
	{
			r=(((y[i-1])/((y[i-1])-(y[i-decre])))*(x[i-decre]));
			r=conversion(r);
			s=(((y[i-decre])/((y[i-decre])-(y[i-1])))*(x[i-1]));
			s=conversion(s);
			x[i]=r+s;
			u=(a*(x[i]*x[i]*x[i]));
			u=conversion(u);
			v=(b*(x[i]*x[i]));
			v=conversion(v);
			w=(c*x[i]);
			w=conversion(w);
			y[i]= u-v+w-d;
			cont=i;
		if (i>=4)
		{
			decre=decre+1;
		}

		if (((x[i]==x[i-1]) && (y[i]==y[i-1])))
		{
			C=i;
			i=n;
		}
	}
	for (i=1; i<=cont; i++)
	{
	       gotoxy(15,6+i);cout<<i<< " aprox.";
	       gotoxy(25,6+i);cout<<"   X"<<i<<  " = " <<   x[i];
	       gotoxy(40,6+i);cout<<"   Y"<<i<<  " = " <<   y[i];
	}
	gotoxy(30,22);cout<<" convergen en X"<<C-1<< " y X"<<C;
getch();
}
