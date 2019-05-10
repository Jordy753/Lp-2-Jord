#include<iostream>
#include<string>
//h.
template<class T>
class my_vector{
	private:
		T* P;
		int size;
	public:	
		my_vector(int _size=0);	//constructor
		my_vector(my_vector& a);	//constructor copia
		~my_vector();	
		
		int size1()const{return size;}
		void push_back(const T a);
		void pop_back();
		T& operator[](int i); 
};
//inl

template<class T>
my_vector<T>::my_vector(int _size){
	size=_size;
	P=new T[size];
}

template<class T>
my_vector<T>::my_vector(my_vector& a){
	P=new T[a.size];
	size=a.size;
	for(int i=0;i<size;i++){
		P[i]=a.P[i];
	}
}

template<class T>
my_vector<T>::~my_vector(){
	delete [] P;
}

template<class T>
void my_vector<T>::push_back(const T a){		
	if(size%10==0){
		T* aux=new T[size+1];
		
		for(int i=0;i<size;i++){
			aux[i]=P[i];
		}
		aux[size]=a;
		delete[] P;
		P=new T[size+10];
		for(int i=0;i<size+1;i++){
			P[i]=aux[i];	
		}
		
		delete[] aux;
	}
	else{
		P[size]=a;
	}
	size=size+1;	
}

template<class T>
void  my_vector<T>::pop_back(){
	P[size-1]=NULL;
	size=size-1;	
}

template<class T>
T& my_vector<T>::operator[](int i){
	return P[i];
}

//main
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
