#include<iostream>
#include<vector>

using namespace std;

int const N=10000000;
int a[N];		


class Sort{
	protected:
	
	public:	
		virtual void sortq(){} 
		virtual ~Sort(){}
};

template<class T>
class Bubble:public Sort{
	private:
		T* A;
		int a;	
	public:
		Bubble(T* &_P,int _n){
			A=_P;
			a=_n;		
		}
		~Bubble(){
			delete [] A;
		}
		
		void sortq(){
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
class Insertion:public Sort{
	private:
		T* A;
		int a;	
	public:
		Insertion(T* &_P,int _n){
			A=_P;
			a=_n;	
		}
		~Insertion(){
			delete [] A;
		}
		
		void sortq(){
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
class Selection:public Sort{
	private:
		T* A;
		int a;	
	public:
		Selection(T* &_P,int _n){
			A=_P;
			a=_n;		
		}
		~Selection(){
			delete [] A;
		}
		
		void sortq(){
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
class Merge:public Sort{
	private:
		T* A;
		int b;	
	public:
		Merge(T* &_P,int _n){
			A=_P;
			b=_n;
		}
		~Merge(){
			delete [] A;
		}
		void merge(int* A,int i,int m,int j){
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
			
		void merge_sort(int* A,int i,int j){
			if(i==j)return;
			int m=(i+j)/2;
			merge_sort(A,i,m);
			merge_sort(A,m+1,j);
			merge(A,i,m,j);
		}
		void merge_sort(int*A, int n){
			merge_sort(A,0,n-1);
		}
		void sortq(){
			merge_sort(A,b);
		}	
				
};

int main(){
	vector<Sort*> S;
	int n;
	cin>>n;
	int* A=new int[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	S.push_back(new Merge<int>(A,n));
	S[0]->sortq();
	for(int i=0;i<n;i++){
		cout<<A[i]<<",";
	}
	
	delete []A;
	return 0;
}
