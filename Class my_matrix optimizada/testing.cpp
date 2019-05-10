#include<iostream>
#include "my_matrix.h"

using namespace std;

int main(){
	Matrix<int> a(2,2);
	Matrix<int> b(2,2);
	a<<5<<4<<3<<1;
	cout<<a(0,0)<<a(0,1)<<a(1,0)<<a(1,1)<<"\n";
	cin>>a;
	b=a;
	Matrix<int> c(a+b);
	cout<<c;
	cout<<c(0,1)<<"\n";
	Matrix<int> d(a*b);
	cout<<d;
	cout<<d(0,0)<<"\n";
	cout<<"\n";
	cout<<b;
	
	return 0;
}

