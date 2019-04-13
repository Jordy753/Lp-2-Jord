#include<iostream>

using namespace std;

void interc(int &_a,int &_b){

  _a=_a+_b;
  _b=_a-_b;
  _a=_a-_b;

}

int main(){
  int a,b;  
  cin>>a>>b;
  interc(a,b);
  cout<<a<<"\t"<<b;

  return 0;
}
