#ifndef INSERTION_H
#define INSERTION_H

#include <iostream>
#include"Sort.h"


template<class T>
class Insertion:public Sort<T>{
	private:
		
	public:
		Insertion(){}
		
		void sortq(T* &A,int a){
    		int ext;
    		int j=1;
    		int aux;
    		while(j<a){
        		ext=A[j];
        		for(int i=j-1;i>=0;i--){
            		if(A[i]>ext){
                		A[i+1]=A[i];
            		}
            		else{
                		A[i+1]=ext;
                		i=-1;
            		}
            		aux=i;
        		}
        		if(aux==0){
            		A[0]=ext;
        		}
        		j++;
    		}
		}

};

#endif
