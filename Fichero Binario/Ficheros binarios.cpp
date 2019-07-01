#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
struct A{
int x; 	//entero de la clase
string str; 
friend ostream & operator <<(ostream& os , A&a){
	os<<a.x<<" "<<a.str;
	return os;
}
friend istream & operator >>(istream & is, A& a){
		is>>a.x>>a.str;
	return is;
}
};

void save_array(vector<A> data, int m){
	ofstream fs ("prueba3.txt",ios::app|ios::binary);
	for(int i=m;i<data.size();i++){
			int _y=data[i].str.size();
        	fs.write( (char *) &data[i].x, sizeof( int ));
			fs.write( (char *) &_y, sizeof( int ) );
			fs.write(data[i].str.c_str(),_y);
	}
    fs.close();
}

void read(vector<A> &va){
	A b;
	ifstream fs("prueba3.txt",ios::binary);
		while(fs.read( (char *) &b.x, sizeof( int ))) {
			int _y;
			fs.read( (char *) & _y, sizeof( int ));
			char* f=new char[_y+2];
			fs.read( f, _y );
			f[_y]=0;
			b.str=f;
			delete []f;
			va.push_back(b);
		}
}

int main(){
A a;
vector<A> va;
read(va);
for(int i=0;i<va.size();i++){
	cout<<va[i]<<"\n";
}
int m=va.size();
cout<<"hola"<<endl;
	while(cin>>a){
		va.push_back(a);}
cout<<"salio"<<endl;
save_array(va,m);
return 0;
}
