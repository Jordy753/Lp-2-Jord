#ifndef RECT_H
#define RECT_H

#include<iostream>
#include<QMainWindow>
#include<figures.h>
#include<QColor>
#include<QPainter>
#include<QPixmap>
#include<QPen>

using namespace std;

class square:public figure{
    private:
        int x,y,h,w;
    public:
        square(int _x=0,int _y=0, int _h=0, int _w=0){
            x=_x;
            y=_y;
            h=_h;
            w=_w;
        }
        ~square(){}
        void draw(QPainter * &painters);
};



#endif // RECT_H
