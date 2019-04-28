#include<iostream>
#include "my_matrix.h"

using namespace std;

int main(){
	Matrix<int> a(2,2);
	Matrix<int> b(2,2);
	cin>>a;
	b=a;
	Matrix<int> c=a+b;
	cout<<c;
	cout<<c(0,1)<<"\n";
	a=a*b;
	cout<<a;
	
	return 0;
}
