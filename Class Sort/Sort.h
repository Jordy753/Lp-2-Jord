#ifndef SORT_H
#define SORT_H

#include <iostream>


template<class T>
class Sort{
	protected:
	
	public:	
		virtual void sortq(T* &A=NULL,int a=0)=0; 
		virtual ~Sort(){}
};

#endif
