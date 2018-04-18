#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;


double deri_x(double t, double x, double v);
double deri_v(double t, double x, double v);
int main(){
	
	double xo=100; 
	double xf=0.01*xo;
	double m=10; 
	double dt=0.01;
	double h=0.01;
	int x, t, v;

	while(x>xf){
		cout<<t<<" "<<x<<" "<<v<<" "<<endl;
}
	return 0;
}


//se quiere conocer la trayectoria, entonces debe devolver 
double deriva(double h, double *x, double *t, double *v){
	
	double tt= *t;
	double xx=*x;
	double vv=*v;
	double kx1, kx2, kx3, kx4;
	double kv1, kv2, kv3, kv4;
	
	kx1=deri_x(tt, xx, vv);
	kv1=deri_v(tt, xx, vv);
	kx2=deri_x(tt+h/2, xx+(h/2)*kx1, vv+(h/2)*kv1);
	kv2=deri_v(tt+h/2, xx+(h/2)*kx1, vv+(h/2)*kv1);
	kx3=deri_x(tt+h/2, xx+(h/2)*kx2, vv+(h/2)*kx2);
	kv3=deri_v(tt+h/2, xx+(h/2)*kx2, vv+(h/2)*kx2);
	kx4=deri_x(tt+h, xx+h*kx3, vv+h*kv3);
	kv4=deri_v(tt+h, xx+h*kx3, vv+h*kv3);

	//aqui se modifica
	double factor=(kx1+2*kx2+2*kx3+kx4)/6.0;
	double fact=(kv1+2*kv2+2*kv3+kv4)/6.0;
	tt=tt+h;
	xx=xx+h*factor;
	vv=vv+h*fact;

	//se devuelve
	*x=xx;
	*t=tt;
	*v=vv;


}


double deri_x(double t, double x, double v){
	
	return v; 

}

double deri_v(double t, double x, double v){
	int G=10;
	int M=1000;
	return ((-G*M)/x*x); 

}

















