#ifndef BUBBLE_H
#define BUBBLE_H

#include <iostream>
#include"Sort.h"


template<class T>
class Bubble:public Sort<T>{
	private:

	public:
		Bubble(){}
		
		void sortq(T* &A,int a){
			while(a){
				for(int i=0;i<a-1;i++){
					if(A[i]>A[i+1]){
						T aux;
						aux=A[i]; A[i]=A[i+1]; A[i+1]=aux;
					}
				}
				a--;
			}
		}

};

#endif

