#include "my_string2.h"
#include "testing.h"
#include<iostream>
	
my_string::my_string(const char* _str){ //Constructor
	if(_str){
		int i=0;
        while(_str[i]!='\0'){
          i++;
        }
        length=i;
        for(int a=0;a<i;a++){
          str[a]=_str[a]; //Probar igualmnt con su propio puntero
        }
    }  
    else{
        length=0;
    }
}

my_string::my_string(const my_string& a){
    delete [] str;
	length=a.leng();
	str=new char[length];
    for(int i=0;i<length;i++){
    	str[i]=a.str[i];	//probar entrando por el puntero
    }    	
}

char my_string::operator[](const int& k){
    if(k>=length) throw -1;
		return str[k];  //ver
}

my_string operator +(my_string& a,my_string& b){
	int m=a.length+b.length;
	int i=0,j=0;
	my_string c;
	c.str=new char(m);
	c.length=m;
	while(j!=m){
		if(j<a.length){
			c.str[j]=a[j];
		}
		else{
			c.str[j]=b[i++];
		}
		j++;
	}
		return c;
}		

my_string& my_string::operator=(const my_string& a){
	delete [] str;
	length=a.leng();
	str=new char[length];
    for(int i=0;i<length;i++){
        str[i]=a.str[i];	//probar entrando por el puntero
    }
}
	
bool my_string::operator ==(const my_string& a){
	if(length==a.leng()){
		for(int i=0;i<length;i++){
			if(str[i]!=a.str[i])
				return false;		
		}
		return true;	
	}
	return false;
}
	
bool my_string::operator >(const my_string& a){
	int n=0;
	if(length<=a.leng()) n=a.leng();
	else n=length; 
	for(int i=0;i<n;i++){
		if(str[i]<a.str[i]) return false;	//un caso adicional verificar int inter
		else if(str[i]>a.str[i]) return true;
		else if(str[i]=='\0') return false;
		else if(a.str[i]=='\0') return true;
	}	
} 
	
bool my_string::operator <(const my_string& a){
	int n=0;
	if(length<=a.leng()) n=a.leng();
	else n=length; 
	for(int i=0;i<n;i++){
		if(str[i]<a.str[i]) return true;	//un caso adicional verificar int inter
		else if(str[i]>a.str[i]) return false;
		else if(str[i]=='\0') return true;
		else if(a.str[i]=='\0') return false;
	}	
}	
	
istream& operator >>(istream& is,my_string& a){
	delete [] a.str;
	int j=0;
	char* ch=new char[100];
	is >>ch;
	while(ch[j]!='\0'){
		j++;
	}
	a.length=j;
	a.str=new char[j];
    for(int j=0;j<a.length;j++)
        a.str[j]=ch[j];	    
   	delete[] ch;
    return is;
}
	
ostream& operator <<(ostream& os,my_string& i){	
	for(int j=0;j<i.leng();j++){
		os<<i.str[j];	
	}
    return os;
}
		
int main(){	
	testing();
	return 0;
}	

