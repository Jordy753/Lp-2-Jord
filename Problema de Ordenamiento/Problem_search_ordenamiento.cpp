#include <stdlib.h>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include <iostream>
int N=100000;
int *TA;
int *TB;
typedef void(fun_sort)(int*,int);

bool test_sort(fun_sort sort,const int *A, int n){
	memcpy(TA,A,sizeof(int)*n);
	memcpy(TB,A,sizeof(int)*n);
	clock_t t = clock();
	sort(TA,n);//el sort
	float time=float(clock()-t)/CLOCKS_PER_SEC;
	std::sort(TB,TB+n);//std sort
	for(int i =0;i<n;i++)
		if(TA[i]!=TB[i]) return false;
	std::cout<<time<<" ";
	return true;
}


void bubble_sort(int *A,int a){
	
	while(a){
		for(int i=0;i<a-1;i++){
			if(A[i]>A[i+1]){
				int aux;
				aux=A[i]; A[i]=A[i+1]; A[i+1]=aux;
			}		
		}
		a--;
	}
	
}

void insertion_sort(int *A,int n){
	for(int i=1;i<n;i++){
		int i_=0,a=i,aux;
		while(A[i]<A[a-1]){			//5 18 6 2 22
			//cout<<A[0]<<"\t"<<A[1]<<"\t"<<A[2]<<"\t"<<A[3]<<"\t"<<a<<i<<endl;
			a--;
			if(a==0 && A[i]<A[0]){
				aux=A[i];i_=i;
				for(int j=0;j<i_;i_--){
					A[i_]=A[i_-1];
					//hacer el recorrido desde el primero
				}
				A[0]=aux;
			}
				
			else if(A[i]>A[a-1]){
				aux=A[i];i_=i;
				for(int j=a;j<i_;i_--){
					A[i_]=A[i_-1];
					//hacer el recorrido desde donde se quedo	
				}				
				A[a]=aux;
			}
		}
	}
}


void selection_sort(int *A,int n){
	int menor;	
	for(int i=0;i<n;i++){
		menor=i;
		for(int a=i+1;a<n;a++){
			if(A[menor]>A[a]){
				menor=a;
			}
		}
		if(A[i]!=A[menor]){
			int aux;
			aux=A[i]; A[i]=A[menor]; A[menor]=aux;
		}
	}
}

using namespace std;
int main(){
	srand(time(NULL));
	int *A= new int[N];
	TA=new int [N];
	TB=new int [N];
	fun_sort sort[3]={bubble_sort,insertion_sort,selection_sort};
	for(int n=100;n<=N;n*=10){
		for(int i=0;i<n;i++)
			A[i]=rand()%n;
		cout<<n<<" ";
		for(int s=0;s<3;s++){
			if(!test_sort(sort[s],A,n)){
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
