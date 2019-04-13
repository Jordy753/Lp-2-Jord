
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int enesimo(vector<int> &_numers,int k){
   for(int i=0;i<_numers.size();i++){
    for(int a=i+1;a<_numers.size();a++){
      if(_numers[i]>_numers[a]){
         int aux;
         aux=_numers[i]; _numers[i]=_numers[a]; _numers[a]=aux; 
      }
    }
  }
  return _numers[k-1];
}

int enesimo_2(vector<int> _num,int k){
	for(int i=0;i<_num.size();i++){
		int kk=0;
		for(int a=0;a<_num.size();a++){
			if(_num[i]>=_num[a]){
				kk++;
				cout<<_num[i]<<kk<<"\n";
			}
		}
		if(kk-1==k-1){
			return _num[i];
		}
/*		else if(kk-1>=k-1){
			return _num[i];
		}
*/
	}
  return _num[k-1];	
}

int main(){
  int num;
  vector<int> numers;
  int k;

  for(int i=0;i<9;i++){
    cin>>num;
    numers.push_back(num);
  }
  cout<<"Termino enesimo que desea\n";
  cin>>k;

  cout<<"El termino enesimo "<<k<<" es: "<<enesimo_2(numers,k);

  return 0;
}
