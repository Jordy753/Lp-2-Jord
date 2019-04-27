#include<iostream>	

using namespace std;
	
void testing(){
	my_string a="hola";
	my_string b;
	b=a;
	cin>>b;
	if(b==a) cout<<"iguales\n";
	else cout<<"diferentes\n";
	cout<<b<<"\n";
	if(a<b) cout<<a<<" menor a "<<b<<"\n";
	else cout<<a<<" mayor a "<<b<<"\n";
	my_string c=a+b;
	cout<<c<<"\n";
}

