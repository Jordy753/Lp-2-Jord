#ifndef SELECTION_H
#define SELECTION_H

#include <iostream>
#include"Sort.h"


template<class T>
class Selection:public Sort<T>{
	private:

	public:
		Selection(){}
		
		void sortq(T* &A,int a){
			int menor;
			for(int i=0;i<a;i++){
				menor=i;
				for(int n=i+1;n<a;n++){
					if(A[menor]>A[n]){
						menor=n;
					}
				}
				if(A[i]!=A[menor]){
					int aux;
					aux=A[i]; A[i]=A[menor]; A[menor]=aux;
				}
			}
		}

};

#endif
