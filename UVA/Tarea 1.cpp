#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double p, q, r, s, t,u, resultado,mn,mx,x;

	bool sol;
	while(cin>>p>>q>>r>>s>>t>>u){
		mn=0.0;
		mx=1.0;
		sol=true;
		while(mn!=mx){
            x=(mn+mx)/2;
			resultado=p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x,2) + u;
			if (abs(resultado)<=0.0000001 ) {
			cout << fixed << setprecision(4) << x << endl;
			sol=false;
			break;}
			if(resultado>0.0)mn=x;
            else mx=x;}

			if(sol) cout<<"No solution"<<endl;
	}
return 0;}
