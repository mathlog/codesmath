//=================== Fundamentos de Analisis numericos ==== I.T. del Istmo
//--------------------------------------------------------------------------
//Metodo de Bairstow (segun el libro)                //alimentate sanamente//

#include <conio.h>                                   //Ingenieria en Sistemas
#include <stdio.h>                                   // Computacionales
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <iostream.h>
#include <graphics.h>

#define MIDX getmaxx()/2
#define MIDY getmaxy()/2
#define TX getmaxx()
#define TY getmaxy()

#define Orden 5

float det(float a1,float a2,float b1,float b2)
{
      return a1*b2-b1*a2;
}
//----------------------------------------------------------------------------
void leerecuacion(float ec[Orden],float *r,float *s)
{
      int i;
      cout<<"f(x)=ax^4+bx^3+cx^3+dx^2+ex+f\n";
      cout<<"Introduce los valores de a,b,c,d,e,f\n";
      for (i=0;i<Orden;i++)
      {
	   printf("Valor de %c :",97+i);
	   cin>>ec[i];
      }
      cout<<"Deme el valor para r:";
      cin>>*r;
      cout<<"Deme el valor para s:";
      cin>>*s;

      cout<<"Gracias...\nPresione una tecla para continuar...\n";
      getch();
}
//----------------------------------------------------------------------------
void imprime(float arr[Orden])
{
      int i;
      for (i=0;i<Orden;i++)
	 printf("%.5f,",arr[i]);
      printf("\n");
}
//----------------------------------------------------------------------------
void bairtow(float fx[Orden],float c[Orden],float r,float s,int orden)
{
      float a[Orden]={0},b[Orden]={0};
      int i;
      a[1]=r;
      b[2]=s;
      for(i=0;i<orden;i++)
      {
	 if(i>1)
	 a[i]=c[i-1]*r;
	 if(i>2)
	    b[i]=c[i-2]*s;
	 c[i]=fx[i]+a[i]+b[i];
      }
      imprime(a);
      imprime(b);
}
//----------------------------------------------------------------------------
float truncar(float x,int t)
{
      char msg[20]={0};
      sprintf(msg,"%f",x);
      int k=0;
      for(int i=0;msg[i]!='\x0';i++)
	 if(msg[i]=='.'||k>0)
	    if(k==t+1)
	    {
		msg[i]='\x0';
		break;
	    }
	 else
	    k++;
      x=atof(msg);
      return x;
}
//----------------------------------------------------------------------------
void main()
{
      float fx[Orden]={0};
      float fa[Orden]={0};
      float fb[Orden]={0};
      float fc[Orden]={0};
      int i;
      float b[Orden]={0},p[Orden]={0};
      float r,s,ra,sa,k,dr,ds;

      clrscr();
      leerecuacion(fx,&r,&s);
      do{
	 ra=r;
	 sa=s;
	 imprime(fx);
	 bairtow(fx,b,r,s,Orden);
	 imprime(b);
	 bairtow(b,p,r,s,Orden-1);
	 imprime(p);
	 k=det(p[2],p[1],p[3],p[2]);
	 dr=det(-b[3],p[1],-b[4],p[2])/k;
	 ds=det(p[2],-b[3],p[3],-b[4])/k;
	 r+=dr;
	 s+=ds;
	 r=truncar(r,4);
	 s=truncar(s,4);
	 printf("\n dr= %.4f  ;   ds= %.4f",dr,ds);
	 printf("\n r= %.4f  ;   s= %.4f\n",r,s);
	 getch();
      }while(!(r==ra&&s==sa));
      cout<<"\nTerminado...";
      getch();
}