#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string s(int a){
	stringstream x;
	if(abs(a)==1){
	if(a==-1)
		x<<"-";
	else
		x<<" ";
	}
	else
		x<<a;
	return x.str();
}

string p(int a){
	stringstream x;
	if(abs(a)==1){
	if(a==1)
		x<<"+";
	else
		x<<"-";
	}
	else{
	if(a>0)
		x<<"+"<<a;
	else 
		x<<a;
	}
	return x.str();
}

class conic{
	int A,B,D,E,F;
	public:
	conic(int,int,int,int,int);
	int a(void) const{return A;};
	int b(void) const{return B;};
	int d(void) const{return D;};
	int e(void) const{return E;};
	int f(void) const{return F;};
	bool S(void) const;
};

conic::conic(int a,int b,int d,int e,int f){
	A=a; B=b; D=d; E=e; F=f;
}

ostream& operator << (ostream& os,const conic& C){
	os<<"$$";
	if(C.a()==0 && C.b()==0 && C.d()==0 && C.e()==0 && C.f()==0)
		os<<0;
	else{
	if(C.a()!=0){
		os<<s(C.a())<<"x^2 ";
	}
	if(C.b()!=0){
		if(C.a()!=0)
			os<<p(C.b());
		else
			os<<s(C.b());
		os<<"x ";
	}
	if(C.d()!=0){
		if(C.a()!=0 || C.b()!=0)
			os<<p(C.d());
		else
			os<<s(C.d());
		os<<"y^2 ";
	}
	if(C.e()!=0){
		if(C.a()!=0 || C.b()!=0 || C.d()!=0)
			os<<p(C.e());
		else
			os<<s(C.e());
		os<<"y ";
	}
	if(C.f()!=0){
		if(C.a()!=0 || C.b()!=0 || C.d()!=0 || C.e()!=0){
			os<<p(C.f());
			if(abs(C.f()==1))
				os<<1;
		}
		else
			os<<C.f();
	}
	}
	os<<"=0$$\n";
	return os;
}

bool conic::S(void) const{
	int t=max(abs(A),abs(B));
	t=max(t,abs(D)); t=max(t,abs(E)); t=max(t,abs(F));
	if(t<=250)
		return true;
	else
		return false;
}

class circulo{
	int h,k,r;
	public:
	circulo(int,int,int);
	int H(void) const{return h;};
	int K(void) const{return k;};
	int R(void) const{return r;};
	conic ecua(void) const;
};

circulo::circulo(int h1,int k1,int r1){
	h=h1; k=k1; r=r1;
}

conic circulo::ecua(void) const{
	int x[4];
	x[0]=1;
	x[1]=-2*H();
	x[2]=-2*K();
	x[3]=H()*H()+K()*K()-R()*R();
	conic C(x[0],x[1],x[0],x[2],x[3]);
	return C;
}

ostream& operator <<(ostream& os,const circulo& u){
	os<<"$$";
	if(u.H()!=0){
		os<<"(x";
		if(u.H()<0)
			os<<"+"<<-u.H();
		else
			os<<-u.H();
		os<<")";
		}
	else
		os<<"x";
	os<<"^2 +";
	if(u.K()!=0){
		os<<"(y";
		if(u.K()<0)
			os<<"+"<<-u.K();
		else
			os<<-u.K();
		os<<")";
		}
	else
		os<<"y";
	os<<"^2 ="<<u.R()*u.R()<<"$$\n";
	return os;
}

class elipse{
	int h,k,a,b;
	public:
	elipse(int,int,int,int);
	int H(void) const{return h;};
	int K(void) const{return k;};
	int A(void) const{return a;};
	int B(void) const{return b;};
	conic ecua(void) const;
};

elipse::elipse(int h1,int k1,int a1,int b1){
	h=h1; k=k1; a=a1; b=b1;
}

conic elipse::ecua(void) const{
	int x[5];
	x[0]=B()*B();
	x[1]=-2*H()*B()*B();
	x[2]=A()*A();
	x[3]=-2*K()*A()*A();
	x[4]=B()*B()*H()*H();
	x[4]+=A()*A()*K()*K();
	x[4]-=A()*A()*B()*B();
	conic C(x[0],x[1],x[2],x[3],x[4]);
	return C;
}

ostream& operator <<(ostream& os,const elipse& u){
	os<<"$$\\frac{";
	if(u.H()!=0){
		os<<"(x";
		if(u.H()<0)
			os<<"+"<<-u.H();
		else
			os<<-u.H();
		os<<")";
		}
	else
		os<<"x";
	os<<"^2}{"<<u.A()*u.A()<<"}+\\frac{";
	if(u.K()!=0){
		os<<"(y";
		if(u.K()<0)
			os<<"+"<<-u.K();
		else
			os<<-u.K();
		os<<")";
		}
	else
		os<<"y";
	os<<"^2}{"<<u.B()*u.B()<<"}=1$$\n";
	return os;
}

class hiperbola{
	int h,k,a,b;
	bool v;
	public:
	hiperbola(int,int,int,int,bool);
	int H(void) const{return h;};
	int K(void) const{return k;};
	int A(void) const{return a;};
	int B(void) const{return b;};
	bool V(void) const{return v;};
	conic ecua(void) const;
};

hiperbola::hiperbola(int h1,int k1,int a1,int b1,bool v1){
	h=h1; k=k1; a=a1; b=b1; v=v1;
}

conic hiperbola::ecua(void) const{
	int x[5];
	if(V()){
		x[0]=-B()*B();
		x[1]=2*H()*B()*B();
		x[2]=A()*A();
		x[3]=-2*K()*A()*A();
		x[4]=-B()*B()*H()*H();
		x[4]+=A()*A()*K()*K();
		x[4]-=A()*A()*B()*B();}
	else{
		x[0]=B()*B();
		x[1]=-2*H()*B()*B();
		x[2]=-A()*A();
		x[3]=2*K()*A()*A();
		x[4]=B()*B()*H()*H();
		x[4]-=A()*A()*K()*K();
		x[4]-=A()*A()*B()*B();}
	conic C(x[0],x[1],x[2],x[3],x[4]);
	return C;
}

ostream& operator <<(ostream& os,const hiperbola& u){
	os<<"$$";
	if(u.V())
		os<<"-";
	os<<"\\frac{";
	if(u.H()!=0){
		os<<"(x";
		if(u.H()<0)
			os<<"+"<<-u.H();
		else
			os<<-u.H();
		os<<")";
		}
	else
		os<<"x";
	os<<"^2}{"<<u.A()*u.A()<<"}";
	if(u.V())
		os<<"+";
	else
		os<<"-";
	os<<"\\frac{";
	if(u.K()!=0){
		os<<"(y";
		if(u.K()<0)
			os<<"+"<<-u.K();
		else
			os<<-u.K();
		os<<")";
		}
	else
		os<<"y";
	os<<"^2}{"<<u.B()*u.B()<<"}=1$$\n";
	return os;
}

class parabola{
	int h,k,p;
	bool v;
	public:
	parabola(int,int,int,bool);
	int H(void) const{return h;};
	int K(void) const{return k;};
	int P(void) const{return p;};
	bool V(void) const{return v;};
	conic ecua(void) const;
};

parabola::parabola(int h1,int k1,int p1,bool v1){
	h=h1; k=k1; p=p1; v=v1;
}

conic parabola::ecua(void) const{
	int x[5];
	if(V()){
		x[0]=1;
		x[1]=-2*H();
		x[2]=0;
		x[3]=-4*P();
		x[4]=H()*H();
		x[4]+=4*P()*K();
	}
	else{
		x[0]=0;
		x[1]=-4*P();
		x[2]=1;
		x[3]=-2*K();
		x[4]=K()*K();
		x[4]+=4*P()*H();
	}
	conic C(x[0],x[1],x[2],x[3],x[4]);
	return C;
}

ostream& operator <<(ostream& os,const parabola& u){
	if(u.V()){
		os<<"$$";
		if(u.H()!=0){
		os<<"(x";
		if(u.H()<0)
			os<<"+"<<-u.H();
		else
			os<<-u.H();
		os<<")";
		}
		else
			os<<"x";
		os<<"^2 ="<<4*u.P();
		if(u.K()!=0){
		os<<"(y";
		if(u.K()<0)
			os<<"+"<<-u.K();
		else
			os<<-u.K();
		os<<")";
		}
		else
			os<<"y";
		os<<"$$\n";
	}
	else{
		os<<"$$";
		if(u.K()!=0){
		os<<"(y";
		if(u.K()<0)
			os<<"+"<<-u.K();
		else
			os<<-u.K();
		os<<")";
		}
		else
			os<<"y";
		os<<"^2 ="<<4*u.P();
		if(u.H()!=0){
		os<<"(x";
		if(u.H()<0)
			os<<"+"<<-u.H();
		else
			os<<-u.H();
		os<<")";
		}
		else
			os<<"x";
		os<<"$$\n";
	}
	return os;
}

int main(int argc, char **argv)
{
	ofstream C("circ.tex"),E("elip.tex"),H("hipe.tex"),P("para.tex"),
	SC("soluc.tex"),SE("solue.tex"),SH("soluh.tex"),SP("solup.tex");
	C<<"\\chapter*{Circunferencia}\n\\begin{enumerate}\n"; 
	E<<"\\chapter*{Elipse}\n\\begin{enumerate}"; 
	H<<"\\chapter*{Hip\\'erbola}\n\\begin{enumerate}"; 
	P<<"\\chapter*{Par\\'abola}\n\\begin{enumerate}";
	SC<<"\\chapter*{Soluci\\'on de circunferencia}\n\\begin{enumerate}";
	SE<<"\\chapter*{Soluci\\'on de elipse}\n\\begin{enumerate}";
	SH<<"\\chapter*{Soluci\\'on de hip\\'erbola}\n\\begin{enumerate}";
	SP<<"\\chapter*{Soluci\\'on de par\\'abola}\n\\begin{enumerate}";
	for(int i=0;i<200;i++){
		bool z=true;
		while(z){
			int t[3];
			for(int k=0;k<2;k++)
				t[k]=abs(rand())%19 - 9;
			t[2]=1+abs(random())%10;
			circulo u(t[0],t[1],t[2]);
			if(u.ecua().S()){
				z=false;
				C<<"\\item "; SC<<"\\item ";
				C<<u.ecua(); SC<<u;
			}
		}
	}
	for(int i=0;i<200;i++){
		bool z=true;
		while(z){
			int t[4];
			for(int k=0;k<2;k++)
				t[k]=abs(random())%19 - 9;
			for(int k=0;k<2;k++)
				t[k+2]=1+abs(random())%10;
			elipse u(t[0],t[1],t[2],t[3]);
			if(u.ecua().S()){
				z=false;
				E<<"\\item "; SE<<"\\item ";
				E<<u.ecua(); SE<<u;
			}
		}
	}
	for(int i=0;i<200;i++){
		bool z=true;
		while(z){
			int t[5];
			for(int k=0;k<2;k++)
				t[k]=abs(random())%19 - 9;
			for(int k=0;k<2;k++)
				t[k+2]=1+abs(random())%10;
			t[4]=abs(random())%2;
			bool B=(t[4]==0);
			hiperbola u(t[0],t[1],t[2],t[3],B);
			if(u.ecua().S()){
				z=false;
				H<<"\\item "; SH<<"\\item ";
				H<<u.ecua(); SH<<u;
			}
		}
	}
	for(int i=0;i<200;i++){
		bool z=true;
		while(z){
			int t[4];
			for(int k=0;k<2;k++)
				t[k]=abs(random())%19 - 9;
			if(random()%2==0)
				t[2]= random()%9 +1;
			else
				t[2]= -random()%9 -1;
			t[3]=abs(random())%2;
			bool B=(t[3]==0);
			parabola u(t[0],t[1],t[2],B);
			if(u.ecua().S()){
				z=false;
				P<<"\\item "; SP<<"\\item ";
				P<<u.ecua(); SP<<u;
			}
		}
	}
	C<<"\\end{enumerate}"; E<<"\\end{enumerate}";
	SC<<"\\end{enumerate}"; SE<<"\\end{enumerate}";
	H<<"\\end{enumerate}"; P<<"\\end{enumerate}";
	SH<<"\\end{enumerate}"; SP<<"\\end{enumerate}";
	C.close(); E.close(); H.close(); P.close();
	SC.close(); SE.close(); SH.close(); SP.close();
	return EXIT_SUCCESS;
}
