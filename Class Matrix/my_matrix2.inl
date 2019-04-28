#include<iostream>

using namespace std;

template<class T>
Matrix<T>::Matrix(size_t _rows,size_t _columns){	
	A=new T*[_rows];
	for(int i=0;i<_rows;i++){
		A[i]=new T[_columns];
	}
	columns=_columns;
	rows=_rows;
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			A[i][j]=0;
		}
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix& a){
	
	rows=a.n_rows();
	columns=a.n_columns();
	A=new T*[rows];
	for(int i=0;i<rows;i++){
		A[i]=new T[columns];
	}
	for (int i=0;i<a.rows; i++){
        for (int j=0;j<a.columns; j++){
            	A[i][j]=a.A[i][j];
        }
    }
}

template<class T>
Matrix<T>::~Matrix(){
	for(int i=0;i<rows;i++)
		delete[] A[i];
	delete[] A;
}


template<class T>
T& Matrix<T>::operator()(size_t i,size_t j){	
    if(i>=0 && j>=0)
        return A[i][j];     
}

template<class T>
Matrix<T> Matrix<T>::operator +(const Matrix<T>& a){
	Matrix<T> d(columns,rows);
	if(columns==a.columns && rows==a.rows){
		for(int i=0;i<a.rows;i++){
			for(int j=0;j<a.columns;j++){
				d.A[i][j]=a.A[i][j]+A[i][j];
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
		for(int i=0;i<rows;i++){
			for(int k=0;k<a.columns;k++){
				for(int j=0;j<columns;j++){
					d.A[i][k]=A[i][j]*a.A[j][k]+d.A[i][k];
				}
			}	
		}
		return d;
	}	
	else{
		throw;
	}
}

