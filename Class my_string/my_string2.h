#include<iostream>

#ifndef MY_STRING.H
#define MY_STRING.H

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
    friend my_string operator +(my_string& a,my_string& b);	//REVISAR
    
    bool operator ==(const my_string& a); //va &? revisar porque friend creo porq era aparte de la clase "antes" 
    bool operator <(const my_string& a); //Por enteros o orden lexicográfico (convertir en minusculas)
    bool operator >(const my_string& a);

    char operator[](const int& i);	//Observar fallas REVISAR
    
    friend std::istream& operator >>(std::istream& is,my_string& i);
    friend std::ostream& operator <<(std::ostream& os,my_string& i);
};

#endif
