#include<iostream>
#include "my_vector.h"
using namespace std;

int main(){
	int i=2;
	my_vector<int> a;
	a.push_back(i);
	a.push_back(3);
	a.push_back(0);
	a.push_back(i);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);	//12
	my_vector<int> b=a;
	b.pop_back();
	for(int i=0;i<b.size1();i++){
		cout<<b[i]<<"\n";
	}
	cout<<"\n";
	cout<<b.size1();
	
	cout<<"\n";
	cin>>a[0];
	cout<<a[0]<<"\n";
	cout<<a.size1();
	return 0;	
}
