#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double lsq;
    double lpt;
    const double PI=4*atan(1.0);
    double ssq=sin(108.0*PI/180.0);
    double ssp=sin(63.0*PI/180.0);
    while(cin>>lpt){
        lsq=(lpt*ssq)/ssp;
        printf("%.10lf", lsq);
        cout<<endl;

    }
    return 0;
}

