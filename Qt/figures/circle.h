#ifndef CIRCLE_H
#define CIRCLE_H

#include<iostream>
#include<QMainWindow>
#include<figures.h>

using namespace std;

class circle:public figure{

    private:
        int x;
        int y;
        int alto;
        int ancho;
    public:
        circle(int _x=0,int _y=0, int _alto=0, int _ancho=0){
            x=_x;
            y=_y;
            alto=_alto;
            ancho=_ancho;
        }
       virtual ~circle();

        void draw(QPainter * painter){
            int r = rand() % 100 + 1;
            painter->setBrush(Qt::gray);
            painter->drawEllipse(300,100 , r, r);
        }


};



#endif // CIRCLE_H
