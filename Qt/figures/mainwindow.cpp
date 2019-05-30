#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "figures.h"
#include "circle.h"
#include "triangle.h"
#include "rect.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

    pixmap = new QPixmap(600, 200);
    pixmap->fill(Qt :: black);

    pen = new QPen(QColor("red"));
    pen->setWidth(5);

	ui->label_draw_area->setPixmap(*pixmap);

    painter = new QPainter(pixmap);
    painter->setPen(*pen);
    k=0;
}

MainWindow::~MainWindow()
{
	delete ui;
    delete pixmap;
    delete pen;
    delete painter;
    delete as;
}

void MainWindow::draw_rect(QPainter *painter){
    int r = rand() % 100 + 1;
    painter->setBrush(Qt::blue);
    painter->drawRect(rand()%pixmap->width(), rand()%pixmap->height(), r, r);
}

void MainWindow::on_b_draw_circle_clicked()
{
    pixmap->fill(Qt :: black);
    int r = rand() % 100 + 1;
    m.push_back(new circle(rand()%pixmap->width(),rand()%pixmap->height(),r,r));
    m[k]->draw(painter);
	ui->label_draw_area->setPixmap(*pixmap);
    k++;
}

void MainWindow::on_b_draw_triangle_clicked()
{
    pixmap->fill(Qt :: black);
    int a = rand()%pixmap->width();
    int b = rand()%pixmap->height();
    int c = rand()%100+1;int d = rand()%100+1;
    int e = rand()%100+1;int f = rand()%100+1;
    m.push_back(new triangle(a,b,c,d,e,f));
    m[k]->draw(painter);
    ui->label_draw_area->setPixmap(*pixmap);
    k++;
}


void MainWindow::on_b_draw_rect_clicked()
{
    pixmap->fill(Qt :: black);
    int r= rand() % 100 + 1;
    m.push_back(new square(rand()%pixmap->width(),rand()%pixmap->height(),r,r));
    m[k]->draw(painter);
    ui->label_draw_area->setPixmap(*pixmap);
    k++;
}

void MainWindow::on_b_draw_clicked()
{
    pixmap->fill(Qt :: black);
    for(int i=0;i<k;i++){
        m[i]->draw(painter);
    }
    ui->label_draw_area->setPixmap(*pixmap);
}

void circle::draw(QPainter * &painters){
    painters->setBrush(Qt::blue);
    painters->drawEllipse(x,y,h,w);
}

void triangle::draw(QPainter *&painters){
    painters->drawLine(a,b,c,d);
    painters->drawLine(a,b,e,f);
    painters->drawLine(e,f,c,d);
}

void square::draw(QPainter *&painters){
    painters->setBrush(Qt::blue);
    painters->drawRect(x,y,h,w);
}
