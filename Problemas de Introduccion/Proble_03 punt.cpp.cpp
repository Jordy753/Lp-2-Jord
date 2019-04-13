
#include<iostream>
#include<string>

using namespace std;

string palind(char* _palabra){ //al final eliminar
  int i,j;
  i=j=0;
  while(_palabra[j]) j++; j--;
  while(i<j){
    if(_palabra[i]!=_palabra[j]){
      cout<<_palabra[i]<<"\t"<<_palabra[j]<<"\n";	
      delete _palabra;
      return "No";
    }
    i++; j--;
  }
  delete _palabra;
  return "Si";
}

int main(){	
  char* palabra="abcba";
   
  
  cout<<palind(palabra);
  

  delete palabra; //verificar
  return 0;
}
