#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
struct A{
<<<<<<< HEAD
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
=======
	int y;
	char str[100];
	
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
	
>>>>>>> master
};

void save_array(vector<A> data, int m){
	ofstream fs ("prueba3.txt",ios::app|ios::binary);
	for(int i=m;i<data.size();i++){
			int _y=data[i].str.size();
        	fs.write( (char *) &data[i].x, sizeof( int ));
			fs.write( (char *) &_y, sizeof( int ) );
			fs.write(data[i].str.c_str(),_y);
	}
<<<<<<< HEAD
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
=======
	fclose(arch);
*/
	A b;
	ifstream f("prueba3.dat", ios::binary);
	f.read((char*) &b, sizeof(A));
	while(!f.eof()){
		va.push_back(b);
		f.read((char*) &b, sizeof(A));
	}	
	f.close();	

}


void save(vector<A>& va){
	ofstream m("prueba3.dat", ios::binary);	
	
	for(int i=0;i<va.size();i++){
		m.write((char *) &va[i], sizeof(A));
	}	
	m.close();
>>>>>>> master
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
