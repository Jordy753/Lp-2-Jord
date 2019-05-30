#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<iostream>
#include<QMainWindow>
#include<figures.h>
#include<QColor>
#include<QPainter>
#include<QPixmap>
#include<QPen>

using namespace std;

class triangle:public figure{

    private:
        int a,b,c,d,e,f;
    public:
        triangle(int _a=0,int _b=0, int _c=0, int _d=0, int _e=0, int _f=0){
            a=_a;
            b=_b;
            c=_c;
            d=_d;
            e=_e;
            f=_f;
        }
        ~triangle(){}
       void draw(QPainter * &painters);
};

#endif // TRIANGLE_H
