#include<iostream>

using namespace std;

int opt_pot(int num,int pot){
  int a,i=1;
  if(pot==1){
    return num;
  }
  else if(pot==0){
    return 1;
  }
  else if(pot%2!=0){
    pot=pot-1;
    i=num;
  }
  a=opt_pot(num,pot/2);
  cout<<a<<"\n";

  return a*a*i; 
}

int main(){
  cout<<opt_pot(4,3);

  return 0;
}
