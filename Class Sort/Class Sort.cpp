#include <stdlib.h>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include <iostream>
#include <vector>
int const N=10000000;
int *TB;
int *TA;
int a[N];

using namespace std;

template<class T>
class Sort{
	protected:
	
	public:	
		virtual void sortq(T* &A=NULL,int a=0)=0; 
		virtual ~Sort(){}
};

template<class T>
class Bubble:public Sort<T>{
	private:

	public:
		Bubble(){}
		
		void sortq(T* &A,int a){
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

template<class T>
class Merge:public Sort<T>{
	private:
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
			merge_sort(A,0,n-1);}
	public:
		Merge(){}
		~Merge(){}
		
		
		
		void sortq(T* &A,int b){
			merge_sort(A,b);
		}	
				
};

bool test_sort(Sort<int>* _S,const int *A, int n){
	memcpy(TA,A,sizeof(int)*n);
	memcpy(TB,A,sizeof(int)*n);
	clock_t t = clock();		
	_S->sortq(TA,n);		
	float time=float(clock()-t)/CLOCKS_PER_SEC;
	sort(TB,TB+n);//std sort
	for(int i =0;i<n;i++)
		if(TA[i]!=TB[i]) return false;
	cout<<time<<" ";
	return true;
}

int main(){
	
	vector<Sort<int> *> S;
	int n;
	cin>>n;
	/*
	int* B=new int[n];
	for(int i=0;i<n;i++){
		cin>>B[i];
	}
	S.push_back(new Merge<int>);
	S[0]->sortq(B,n);
	for(int i=0;i<n;i++){
		cout<<B[i]<<",";
	}
	
	delete []B;
	*/
	srand(time(NULL));
	int *A= new int[N];
	TA=new int [N];
	TB=new int [N];
	S.push_back(new Merge<int>);
	S.push_back(new Bubble<int>);
	S.push_back(new Insertion<int>);
	S.push_back(new Selection<int>);	
	//S[0]->sortq(B,n);
	//fun_sort sort[4]={merge_sort,bubble_sort,insertion_sort,selection_sort};
	for(int n=100;n<=N;n*=10){
		for(int i=0;i<n;i++)
			A[i]=rand()%n;
		cout<<n<<" ";
		for(int s=0;s<4;s++){
			if(!test_sort(S[s],A,n)){
				cout<<"Fail\n";
				return 0;
			}}
		cout<<endl;
			}
		delete[]A;
		delete[]TA;
		delete[]TB;
	
	
	return 0;
}
