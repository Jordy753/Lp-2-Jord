#ifndef FIGURE_H
#define FIGURE_H

#include<iostream>
#include<QMainWindow>
#include<mainwindow.h>

using namespace std;

class figure:public MainWindow
{
    private:

    public:
       // virtual ~figure();

        virtual void draw(QPainter * painter)=0;

};


#endif // FIGURE_H
