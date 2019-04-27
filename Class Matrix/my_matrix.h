#include<iostream>

#ifndef MY_MATRIX.H
#define MY_MATRIX.H

template<class T>
class Matrix{
	private:
		T** A;
		size_t columns;
		size_t rows;
	public:
		Matrix(size_t _rows=0,size_t _columns=0);
		Matrix(const Matrix& a);
		
		~Matrix();
		
		size_t n_columns()const{return columns;}
		size_t n_rows()const{return rows;}
		
		T& operator()(size_t i,size_t j);	
	
    	friend std::istream& operator>>(std::istream& is,Matrix<T>& a){
    		for (int i=0;i<a.rows; i++){
        		for (int j=0;j<a.columns; j++){
            		is>>a(i,j);
        		}
    		}
    		return is;
		}
	
    	friend std::ostream& operator <<(std::ostream& os,Matrix& a){
    		for(int i=0;i<a.rows;i++){
    			for(int j=0;j<a.columns;j++){
    				os<<a(i,j)<<"\t";
				}
				std::cout<<"\n";
			}
		}
    	
    	Matrix<T> operator +(const Matrix<T>& a);
    	Matrix<T> operator *(const Matrix<T>& a);
    	
};

#include "my_matrix2.inl"

#endif
