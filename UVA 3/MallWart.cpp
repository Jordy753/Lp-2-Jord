#include<iostream>
#include<set> 
#include<iterator>

using namespace std;


int main(){ 
  multiset<int> MallWart;
  int n_days;
  int n_ticket;
  int n_total;
  long long PM=0;
  int n,m;
  int aux;
  multiset<int>::iterator itr,n1,n2;
  while(cin>>n_days){
	while(n_days!=0 && 1<=n_days<=5000){
		cin>>n_ticket;
		if(0<=n_ticket<=100000){  		
			for(int i=0;i<n_ticket;i++){
				cin>>aux;
				MallWart.insert(aux);
			}
			n1=MallWart.begin(); n2=MallWart.end(); n2--;
			PM=(*n2-*n1)+PM;
			n=*n1; m=*n2;
			n1=MallWart.find(n);
	    	MallWart.erase(n1); 
			n1=MallWart.find(m);
	    	MallWart.erase(n1); 
			n_days--;
		}
		else break;			
	}
	MallWart.clear();
	if(PM!=0)
		cout<<PM<<endl;
	PM=0;	
  } 	 			
	return 0;
}
