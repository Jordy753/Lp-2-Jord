#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

struct A{
	int y;
	char str[3];
	
	A(int _x=0){
		y=_x;
		//str=_str; 	
	}
	
	friend istream& operator >>(istream& is, A& a){
		is>>a.y;
		is>>a.str;
		return is;
	}
	
	friend ostream& operator <<(ostream& os, A& a){
		os<<a.y<<" "<<a.str;
		
		return os;
	}
	
};


void load(vector<A>& va){
/*
	A b;
	FILE *arch;
	arch=fopen("prueba3.dat","rb");
	fread(&b,sizeof(b),1,arch);
	while(!feof(arch)){
		va.push_back(b);
		fread(&b,sizeof(b),1,arch);
	}
	fclose(arch);
*/
	A b;
	ifstream f("prueba3.dat", ios::binary);
	f.read((char*) &b, sizeof(b));
	while(!f.eof()){
		va.push_back(b);
		f.read((char*) &b, sizeof(b));
	}	
	f.close();	

}


void save(vector<A>& va){
	ofstream m("prueba3.dat", ios::binary);	
	
	for(int i=0;i<va.size();i++){
		m.write((char *) &va[i], sizeof(va[i]));
	}	
	m.close();
}

int main(){
	A a;
	vector<A> va;
	load(va);
	
	for(int i=0;i<va.size();i++){
		cout<<va[i]<<"\n";
	}
	
	//cout<<"hola\n";
	while(cin>>a){
		va.push_back(a);	
	}
 	save(va); 
 	
 	cout<<"\n";
	for(int i=0;i<va.size();i++){
		cout<<va[i]<<"\n";	
	}
	 	
	return 0;
}
