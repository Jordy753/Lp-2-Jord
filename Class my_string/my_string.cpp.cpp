#include<iostream>

using namespace std;

class my_string{
  private:
    char* str;
    int length;
  public:
    my_string(const char* _str=NULL); //Constructor
    
    my_string(const my_string& a);  //Constructor copia

    ~my_string(){
      delete []str;
    }  

    int leng()const{return length;} 


    my_string& operator =(const my_string& str);
    my_string& operator +(const my_string& str);	//REVISAR
    
    bool operator ==(const my_string& a); //va &? revisar porque friend creo porq era aparte de la clase "antes" 
    bool operator <(const my_string& a); //Por enteros o orden lexicográfico (convertir en minusculas)
    bool operator >(const my_string& a);

    char operator[](const int& i);	//Observar fallas REVISAR
    
    friend istream& operator >>(istream& is,my_string& i);
    friend ostream& operator <<(ostream& os,my_string& i);
};

//h.

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

	my_string& my_string::operator +(const my_string& a){
		char* b=new char[length];
	 	for(int i=0;i<length;i++){
	 		b[i]=str[i];		
		}
		length=(length+a.leng());		 
		delete[] str; 
		str=new char[length];
		
	 	for(int i=0;i<a.leng();i++){
		 	str[i]=a.str[i]; 
		}
		int k=0;
		for(int i=a.leng();i<length;i++){
			str[i]=b[k];
			k++;
		}
		
		delete[] b;
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
	my_string a="hola";
	my_string b;
	b=a;
	cin>>b;
	if(b==a) cout<<"iguales\n";
	else cout<<"diferentes\n";
	cout<<b<<"\n";
	if(a<b) cout<<a<<" menor a "<<b<<"\n";
	else cout<<a<<" mayor a "<<b<<"\n";
	a+b;
	cout<<a<<"\n";


  return 0;
}

/*
	#include<iostream>

using namespace std;

int main(){
  int i=0;
  char* a=new char[8];
  cin>>a;
  cout<<a;
  while(a[i]!='\0'){
    i++;
  }
  cout<<i;

  delete[] a;

  return 0;
}


*/

