#include<iostream>

using namespace std;

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

