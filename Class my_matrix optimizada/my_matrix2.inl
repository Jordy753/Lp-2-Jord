#include<iostream>

using namespace std;

template<class T>
Matrix<T>::Matrix(size_t _rows,size_t _columns){	
	k=0;
	columns=_columns;
	rows=_rows;
	A=new T[rows*columns];
	
	for(int i=0;i<columns;i++){
		for(int j=0;j<rows;j++){
			A[i*rows+j]=0;
		}
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix& a){
	rows=a.n_rows();
	columns=a.n_columns();
	A=new T[rows*columns];
	
	for (int i=0;i<columns; i++){
        for (int j=0;j<rows; j++){
            	A[i*rows+j]=a.A[i*rows+j]; 
        }
    }
}

template<class T>
Matrix<T>::~Matrix(){
	delete[] A;
}

template<class T>
T& Matrix<T>::operator()(size_t i,size_t j){	
    if(i>=0 && j>=0)
        return A[i*rows+j];     
}

template<class T>
Matrix<T> Matrix<T>::operator +(const Matrix<T>& a){
	Matrix<T> d(rows,columns);
	if(columns==a.columns && rows==a.rows){
		for(int i=0;i<columns;i++){
			for(int j=0;j<rows;j++){
				d.A[i*rows+j]=a.A[i*rows+j]+A[i*rows+j];
			}
		}
		return d;	
	}
	else{
			throw;
	}
			    		
}

template<class T>
Matrix<T> Matrix<T>::operator *(const Matrix<T>& a){
	Matrix<T> d(rows,a.columns);
	if(columns==a.rows){
		for(int i=0;i<columns;i++){
			for(int k=0;k<a.columns;k++){
				for(int j=0;j<rows;j++){			  	
					d.A[i*rows+k]=A[i*rows+j]*a.A[j*rows+k]+d.A[i*rows+k];
				}			  
			}	
		}
		return d;
	}	
	else{
		throw;
	}
}

template<class T>
Matrix<T>& Matrix<T>::operator <<(const T v){
	int n=rows*columns;
	if(k==n){
		k=0;
	}	
	A[k]=v;	
	k=k+1;
	return *this;	
}

