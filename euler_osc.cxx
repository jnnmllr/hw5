#include <fstream>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int main (){

const double     pi = 3.14159265359;
const double      T = 20*pi;
const double     dt = pi/10;
const int         N = T/dt;
double         y[2];
y[0]=1;
y[1]=0;
double      ydot[2];
ydot[0]=0;
ydot[1]=-1;

cout << N << endl;

 ofstream out("Dataforward.txt");
 out << 0 << " " << y[0] << endl;
        for(int i=1;i<N;i++){
	  y[0]+=ydot[0]*dt;
    y[1]+=ydot[1]*dt;
    ydot[0] = y[1];
    ydot[1] = -y[0];
	  out << i*dt << " " << y[0] << endl;
	}
out.close();

y[0]=1;
y[1]=0;
ofstream out1("Databackward.txt");
out1 << 0 << " " << y[0] << endl;
        for(int i=1;i<N;i++){
	  y[0] = (y[0]+y[1]*dt)/(1+dt*dt);
    y[1] = y[1] - (y[0]*dt);
	  out1 << i*dt << " " << y[0] << endl;
	}
out1.close();

 ofstream out2("Datacos.txt");
        for(int i=0;i<N;i++){
y[0] = cos(i*dt);
	  out2 << i*dt << " " << y[0] << endl;
	}
out2.close();
return 0;
}
