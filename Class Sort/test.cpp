#include<stdlib.h>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
#include"Sort.h"
#include"Bubble.h"
#include"Insertion.h"
#include"Selection.h"
#include"Merge.h"
int *TB;
int *TA;

using namespace std;

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
	int const N=10000000;
	vector<Sort<int> *> S;
	int n;
	//cin>>n;
	srand(time(NULL));
	int *A= new int[N];
	TA=new int [N];
	TB=new int [N];
	S.push_back(new Merge<int>);
	S.push_back(new Bubble<int>);
	S.push_back(new Insertion<int>);
	S.push_back(new Selection<int>);	
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
	for(int i=0;i<S.size();i++){
		delete [] S[i];
	}
		delete[]A;
		delete[]TA;
		delete[]TB;
	
	
	return 0;
}
