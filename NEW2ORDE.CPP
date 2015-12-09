//Metodo Newton Rapson Segundo Orden
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <iostream.h>
#include <graphics.h>

#define MIDX getmaxx()/2
#define MIDY getmaxy()/2
#define TX getmaxx()
#define TY getmaxy()

#define ORDMAX 10
void derivar(int Dfx[2][ORDMAX],int fx[2][ORDMAX],int orden)
{
int i;
for(i=0;i<orden;i++)
  {
  Dfx[0][i]=fx[0][i]*fx[1][i];
  if(fx[1][i]>0)
     Dfx[1][i]=fx[1][i]-1;
  }
for (;i<ORDMAX;i++)
    Dfx[0][i]=0,Dfx[1][i]=0;
}


void ponerpunto(int x,int y,int color)
{
if(x>0&&x<400&&y>0&&y<400)
  putpixel(x,y,color);
}
float elevar(float x,int y)
{
float val=1;
for (int i=0;i<y;i++)
    val=val*x;
return val;
}
float eval(int funcion[2][ORDMAX],int orden,int numderiv,float xi)
{
int i;
float sum=0;
float z;

for (i=0;i<orden-numderiv;i++)
  {
    z=elevar(xi,funcion[1][i]);
    sum=sum+funcion[0][i]*z;
   }
return sum;
}

void tablero(int x,int y);
void initgra(void);


void main()
{
int fx[2][ORDMAX]={0};
int f1x[2][ORDMAX]={0};
int f2x[2][ORDMAX]={0};

float x1,x2,xi,xi1,x;
float y1,y2,yi,yi1,ya;
float a,b,c,d;
int i,z,orden;
char cad[80]={0};
int jy=0;
clrscr();

xi=0;

clrscr();
printf("orden de la ecuacion:");
scanf("%d",&orden);

orden++;
for(i=0;i<orden;i++)
  {
  printf("X%d ",orden-i-1);
  scanf("%d",&fx[0][i]);
  fx[1][i]=orden-i-1;
  }

derivar(f1x,fx,orden);
derivar(f2x,f1x,orden);


initgra();setfillstyle(1,1);
bar(0,0,TX,TY);tablero(0,0);
xi=0;


yi1=eval(fx,orden,0,xi);
sprintf(cad,"%.4f",yi1);yi1=atof(cad);
i=0;
settextstyle(2,0,4);
outtextxy(420,40,"Newton Rapson 2§ Orden");
outtextxy(420,60,"X      f(x)         f'(x)        f''(x)");
setcolor(10);
outtextxy(10,460,"linea color verde es fx");
setcolor(14);
outtextxy(200,460,"linea color amarillo es f'x");
setcolor(12);
outtextxy(400,460,"linea color rojo es f''x");
setcolor(15);
outtextxy(40,420,"Presione una tecla para continuar");
outtextxy(40,430,"en caso que el proceso este en un ciclo infinito, presione ESC");
do{
   ya=yi1;
   a=eval(fx,orden,0,xi);
   b=eval(f1x,orden,1,xi);
   c=eval(f2x,orden,2,xi);
   xi1=xi-(a/(b-(a*c/(2*b))));
   sprintf(cad,"%.4f",xi); outtextxy(420,70+jy,cad);
   sprintf(cad,"%.4f",a); outtextxy(465,70+jy,cad);
   sprintf(cad,"%.4f",b); outtextxy(520,70+jy,cad);
   sprintf(cad,"%.4f",c); outtextxy(590,70+jy,cad);


   sprintf(cad,"%.4f",xi1);xi1=atof(cad);
   yi1=eval(fx,orden,0,xi1);
   ponerpunto(200+xi1*40,200-yi1*40,10);

   y2=eval(f1x,orden,1,xi1);
   ponerpunto(200+xi1*40,200-y2*40,14);

   y2=eval(f2x,orden,2,xi1);
   ponerpunto(200+xi1*40,200-y2*40,12);


   jy+=10;
   if(jy>320)
     {
     setfillstyle(1,1);
     bar(420,70,680,400);
     jy=0;

     }
   z=getch();
   xi=xi1;
   i=i+1;
  }while(ya!=yi1&&z!=27);

printf("%.4f %.4f",xi,yi1);


float xx,yy;
getch();
for(xx=-5;xx<5;xx=xx+.001)
  {
   yy=eval(fx,orden,0,xx);
   ponerpunto(200+xx*40,200-yy*40,10);
   yy=eval(f1x,orden,1,xx);
   ponerpunto(200+xx*40,200-yy*40,14);
   yy=eval(f2x,orden,2,xx);
   ponerpunto(200+xx*40,200-yy*40,12);

  }
  getch();


getch();
}


void tablero(int x,int y)
{
float k,i,xf,yf;
int l;
k=40;
xf=k*10+x;
yf=k*10+y;
setfillstyle(1,0);
bar(x,y,xf,yf);


setcolor(7);
for (i=0;i<=10;i++)//verticales
   line(x+i*k,y,x+i*k,yf);
for (i=0;i<=10;i++)//horizontales
   line(x,yf-k*i,xf,yf-k*i);

setcolor(15);
line(0,200,400,200);
line(200,0,200,400);


char cad[10]={0};

l=-5;
for (i=0;i<=10;i++)
   {
    sprintf(cad,"%d",l);
    outtextxy(x+i*k,yf+5,cad);
    outtextxy(x-30,yf-i*k,cad);
    l++;
   }
getch();
}
void initgra(void)
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "");
errorcode = graphresult();
if (errorcode != grOk)
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);
}
}