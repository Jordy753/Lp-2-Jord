#include <stdlib.h>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

template<class T>
class Sort{
	protected:
	
	public:	
		virtual void sortq(T* A=NULL,int a=0)=0; 
		virtual ~Sort(){}
};

template<class T>
class Bubble:public Sort<T>{
	private:

	public:
		Bubble(){}
		
		void sortq(T* A,int a){
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

template<class T>
class Insertion:public Sort<T>{
	private:
		
	public:
		Insertion(){}
		
		void sortq(T* A,int a){
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

template<class T>
class Selection:public Sort<T>{
	private:

	public:
		Selection(){}
		
		void sortq(T* A,int a){
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

template<class T>
class Merge:public Sort<T>{
	private:
		int a[10000000];
		void merge(T* A,int i,int m,int j){
			int b=i,d=m+1; int c=0;
			while(b<=m && d<=j ){
				if(A[b]>=A[d]){
					a[c]=A[d];
					d++; c++;
				}
				else{
					a[c]=A[b];
					b++; c++;
				}
			}	
			while(b<=m) a[c++]=A[b++];
			while(d<=j) a[c++]=A[d++];		
			for(int in=0;in<j-i+1;in++)
				A[in+i]=a[in];
			}
			
		void merge_sort(T* A,int i,int j){
			if(i==j)return;
			int m=(i+j)/2;
			merge_sort(A,i,m);
			merge_sort(A,m+1,j);
			merge(A,i,m,j);
		}
		void merge_sort(T*A, int n){
			merge_sort(A,0,n-1);}
	public:
		Merge(){}
		~Merge(){}
	
		void sortq(T* A,int b){
			merge_sort(A,b);
		}	
				
};



int main(){
	vector<Sort<char> *> S;	
	
	int n=0;
	cin>>n;
	char* A=new char[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}

	S.push_back(new Merge<char>);
	S[0]->sortq(A,n);
	for(int i=0;i<n;i++){
		cout<<A[i]<<",";
	}
	
	delete[] A;
	delete S[0];
	
	return 0;
}
