#ifndef FIGURE_H
#define FIGURE_H

#include<iostream>
#include<QMainWindow>
#include<QColor>
#include<QPainter>
#include<QPixmap>
#include<QPen>

using namespace std;

class figure{
    private:

    public:
    virtual ~figure(){}

    virtual void draw(QPainter * &painters)=0;

};


#endif // FIGURE_H
