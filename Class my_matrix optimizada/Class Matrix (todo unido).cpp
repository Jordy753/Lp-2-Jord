#include<iostream>

// h
template<class T>
class Matrix{
	private:
		T* A;
		size_t columns;
		size_t rows;
		size_t k;
	public:
		Matrix(size_t _rows=0,size_t _columns=0);
		Matrix(const Matrix& a);		
		~Matrix();
		
		size_t n_columns()const{return columns;}
		size_t n_rows()const{return rows;}
		
		T& operator()(size_t i,size_t j);
		Matrix<T>& operator <<(const T v);
    	Matrix<T> operator +(const Matrix<T>& a);
    	Matrix<T> operator *(const Matrix<T>& a);
	
	
    	friend std::istream& operator>>(std::istream& is,Matrix<T>& a){
    		for (int i=0;i<a.columns; i++){
        		for (int j=0;j<a.rows; j++){
            		is>>a(i,j);
        		}
    		}
    		return is;
		}
	
    	friend std::ostream& operator <<(std::ostream& os,Matrix& a){
    		for(int i=0;i<a.columns;i++){
    			for(int j=0;j<a.rows;j++){
    				os<<a(i,j)<<"\t";
				}
				std::cout<<"\n";
			}
		}
    	
};

//inl


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
            	A[i*rows+j]=a.A[i*rows+j]; //xk?? error cuando es: a(i,j)
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
					//std::cout<<d.A[i*rows+k]<<"\t"<<A[i*rows+j]<<"\t"<<a.A[j*rows+k]<<"\n";
				}			  
			}	
		}
		//Hacer tambien los detalles minuciosos de if y subir al repo hacer el >> el extra
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

using namespace std;

//main
int main(){
	Matrix<int> a(2,2);
	Matrix<int> b(2,2);
	a<<5<<4<<3<<1;
	cout<<a(0,0)<<a(0,1)<<a(1,0)<<a(1,1)<<"\n";
	cin>>a;
	b=a;
	Matrix<int> c(a+b);
	cout<<c;
	cout<<c(0,1)<<"\n";
	Matrix<int> d(a*b);
	cout<<d;
	cout<<d(0,0)<<"\n";
	cout<<"\n";
	cout<<b;
	
	return 0;
}

/*
template<class T>
class matrix{
	private:						memcpy
		T** p_data;					memset(p_data,0,size...)
		size_t n_rows;
		size_t n_cols;
	public:
		matrix(size_t nr=0,size_t nc=0);
		matrix(const matrix<T>&m);
		~matrix()
		T& operator()(size_t i,size_t j);
		matrix<T> operator +(const matrix<T> &m);
		matrix<T> operator *(const matrix<T> &m);
		matrix<T> operator <<(T& v);
		//friend ostream& operator <<(ostream& os,const matrix<T>& m);
			
};



*/
