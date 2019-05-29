#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "figures.h"
#include "circle.h"

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
}

MainWindow::~MainWindow()
{
	delete ui;
    delete pixmap;
    delete pen;
    delete painter;
    delete as;
}

void MainWindow::draw_circle(QPainter * painter)
{
	int r = rand() % 100 + 1;
    painter->setBrush(Qt::blue);
    painter->drawEllipse(300,100 , r, r);
    //int r = rand()%100+1;
}

void MainWindow::draw_triangle(QPainter * painter){
    int a = rand()%pixmap->width();
    int b = rand()%pixmap->height();
    int c = rand()%100+1;int d = rand()%100+1;
    int e = rand()%100+1;int f = rand()%100+1;
    //painter->setBrush(Qt::blue);
    painter->drawLine(a,b,c,d);
    painter->drawLine(a,b,e,f);
    painter->drawLine(e,f,c,d);
}

void MainWindow::draw_rect(QPainter *painter){
    int r = rand() % 100 + 1;
    painter->setBrush(Qt::blue);
    painter->drawRect(rand()%pixmap->width(), rand()%pixmap->height(), r, r);
}

void MainWindow::on_b_draw_circle_clicked()
{
    pixmap->fill(Qt :: black); //clear
    draw_circle(painter);
	ui->label_draw_area->setPixmap(*pixmap);
}

void MainWindow::on_b_draw_triangle_clicked()
{
    pixmap->fill(Qt :: black); //clear

    draw_triangle(painter);

    ui->label_draw_area->setPixmap(*pixmap);
}


void MainWindow::on_b_draw_rect_clicked()
{
    pixmap->fill(Qt :: black); //clear

    draw_rect(painter);

    ui->label_draw_area->setPixmap(*pixmap);
}
