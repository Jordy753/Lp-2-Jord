#include<iostream>

// h
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

//inl


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


using namespace std;

//main
int main(){
	Matrix<int> a(2,2);
	Matrix<int> b(2,2);
	cin>>a;
	b=a;
	Matrix<int> c=a+b;
	cout<<c;
	cout<<c(0,1)<<"\n";
	a=a*b;
	cout<<a;
	
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
		//friend ostream& operator <<(ostream& os,const matrix<T>6 m);
			
};



*/
