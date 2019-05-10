#include<iostream>

using namespace std;

size_t P[1000000];
size_t k;

void fun(size_t n,int* &a){
	size_t B[n];
	for(int i=0;i<n;i++){
		B[i]=0;
	}
	B[0]=B[1]=1;
	size_t q=0;
	for(int i=3;i<n;i+=2){
		if(!B[i]){
			P[q++]=i;
			k++;
			for(int j=i*i;j<n;j+=2*i){
				B[j]=1;
			}	
		}
	}
	a=new int[k];
	for(int i=0;i<k;i++){
		a[i]=P[i];
	}
}

void primos(int j,int* &a){
	while(k!=-1){
		if(a[k-1]<j){
			int i=k-1;
			while(a[k-1]+a[i-1]>=j){
				if(a[k-1]+a[i-1]==j){
					cout<<j<<"="<<a[i-1]<<"+"<<a[k-1]<<"\n";						
				}
				i--;
			}	
		}
		k=k-1;
	}
}

int main(){
	int* p;
	size_t n;
	size_t j;
	cin>>n;
	fun(n,p);
	for(int i=0;i<k;i++){
		cout<<p[i]<<",";
	}
	cout<<"\n";
	cout<<k<<"\n";
	cin>>j;
	primos(j,p);
	delete [] p;
}
