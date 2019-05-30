#include<iostream>
#include<vector>

using namespace std;

int const N=10000000;
int a[N];

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
		}}
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


int main(){
	
	int* Lg;
	int* Lb;
	int battlefield=0;
	int nLg=0;
	int nLb=0;
	int auxn=0;
	
	cin>>battlefield>>nLg>>nLb;
	
	Lg=new int[nLg];
	for(int i=0;i<nLg;i++){
		cin>>auxn;
		Lg[i]=auxn;	
	}	
	merge_sort(Lg,nLg);
	
	Lb=new int[nLb];
	for(int i=0;i<nLb;i++){
		cin>>auxn;
		Lb[i]=auxn;	
	}	
	merge_sort(Lb,nLb);
	
	while(Lg[nLg-1]!=0 && Lb[nLb-1]!=0){
		int a=1;
		for(int i=0;i<battlefield;i++){
			while(Lg[nLg-a]!=0 && Lb[nLb-a]!=0){		
				if(Lg[nLg-a]>Lb[nLb-a]){
					Lg[nLg-a]=Lg[nLg-a]-Lb[nLb-a];
					Lb[nLb-a]=0;				
				}
				else if(Lg[nLg-a]<Lb[nLb-a]){
					Lb[nLb-a]=Lb[nLb-a]-Lg[nLg-a];
					Lg[nLg-a]=0;					
				}
				else{
					Lg[nLg-a]=0;Lb[nLb-a]=0;
				}	 		
			}
			a++;
			
		}
		merge_sort(Lg,nLg);
		merge_sort(Lb,nLb);		
	}
	for(int i=0;i<nLg;i++){
		cout<<Lg[i]<<",";
	}
	cout<<"\n";
	for(int i=0;i<nLb;i++){
		cout<<Lb[i]<<",";
	}
	
	delete [] Lg;
	delete [] Lb;
	return 0;
}
