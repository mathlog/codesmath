#include <conio.h>
#include <stdio.h>
#include <iostream.h>

 float X[50], Y[50];
 float  x1,x2,y1,y2;
 float num1,num2,num3,num4;
 int i,j,a,b,c,d;
 float  aux1,aux2;
 
void main()
{
	  clrscr();
	  gotoxy(25,3);cout<<"METODO DE REGULA-FALSI";
	  gotoxy(22,10);cout<<"DE EL PRIMER NUMERO DE LA ECUACION";
	  gotoxy(57,10);cin>>num1;
	  gotoxy(22,12);cout<<"DE ELSEGUNDO NUMERO DE LA ECUACION";
	  gotoxy(57,12);cin>>num2;
	  gotoxy(22,14);cout<<"DE EL TERCER NUMERO DE LA ECUACION";
	  gotoxy(57,14);cin>>num3;
	  gotoxy(22,16);cout<<"DE EL CUARTO NUMERO DE LA ECUACION";
	  gotoxy(57,16);cin>>num4;
	  clrscr();
		 gotoxy(30,10);cout<<"Fx="<<num1<<"xy"<<num2<<"xy'"<<num3<<"x"<<num4;
		 gotoxy(30,12);cout<<"X1=";gotoxy(35,12);cin>>x1;
		 gotoxy(30,14);cout<<"X2=";gotoxy(35,14);cin>>x2;
			y1=(num1*(x1*x1*x1))+(num2*(x1*x1))+(num3*x1)+(num4);
			y2=(num1*(x2*x2*x2))+(num2*(x2*x2))+(num3*x2)+(num4);
			gotoxy(30,16);cout<<"Y1= "<<y1;
			gotoxy(30,18);cout<<"Y2= "<<y2;
			getch();
			a=2;c=3;
			b=2;d=3;
			aux1=0;
			aux2=0;
			clrscr();
			for (i=1;i<=70;i++)
			{
			  if (i==1)
			  {
				  X[i]=(y2/(y2-(y1)))*(x1);
				  Y[i]=(num1*(X[i]*X[i]*X[i]))+(num2*(X[i]*X[i]))+(num3*X[i])+(num4);
				  cout<<"\nAPROXIMACION "<<i<<" X"<<a++<<" = "<<X[i]<<" Y"<<b++<<" = "<<Y[i];
				  aux1=X[i];
				  aux2=Y[i];
			  }
			  else
			  {
				  X[i]=(y2/(y2-(aux2)))*(aux1);
				  Y[i]=(num1*(X[i]*X[i]*X[i]))+(num2*(X[i]*X[i]))+(num3*X[i])+(num4);
				  cout<<"\n\nAPROXIMACION "<<i<<" X"<<c++<<" = "<<X[i]<<" Y"<<d++<<" = "<<Y[i];
				  getch();
				  if (X[i]==aux1)
				  {
						clrscr();
						cout<<"SE APROXIMA EN: X "<<i<<" CON:  "<<aux1<<" Y "<<i<<" CON "<<aux2;
						j=i;
						i=50;
						getch();
					}
					else
					{
						aux1=X[i];
						aux2=Y[i];
					}
		}
	}
}


