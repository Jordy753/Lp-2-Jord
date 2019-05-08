#include<iostream>

#ifndef MY_VECTOR.H
#define MY_VECTOR.H

template<class T>
class my_vector{
	private:
		T* P;
		int size;
	public:	
		my_vector(int _size=0);	//constructor
		my_vector(my_vector& a);	//constructor copia
		my_vector(const T* a);		//constructor copia *T
		~my_vector();	//
		
		int size1()const{return size;}
		void push_back(const T a);
		void pop_back();
		T& operator[](int i); 
};
#include "my_vector2.inl"

#endif
