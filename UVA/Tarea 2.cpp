#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

int main(){
	
	int N,M,i,j,aux1=1000,aux2;
	vector<int> N_;
	
	while(cin>>N){	
		while(N<2 || N>1000){
			cin>>N;
		}
		for(int k=0;k<N;k++){
			cin>>M;	//por mientras
			N_.push_back(M);
		}
		cin>>M;
		for(int k=0;k<N;k++){
			for(int a=k+1;a<N;a++){
				if(N_[k]+N_[a]==M){
					aux2=abs(N_[k]-N_[a]); //valor absoluto
					if(aux2<=aux1){
						aux1=aux2;
						if(N_[k]<N_[a]){ i=N_[k];j=N_[a];}
						else {i=N_[a];j=N_[k]; }
					}
				}
			}
		}
		cout<<"Peter should buy books whose prices are "<<i<<" and "<<j<<".\n";
	}
	return 0;
}
