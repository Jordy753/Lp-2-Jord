#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <figures.h>
#include <circle.h>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPen>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget * parent = nullptr);
	~MainWindow();

private slots:
	void on_b_draw_circle_clicked();

    void on_b_draw_triangle_clicked();

    void on_b_draw_rect_clicked();

    void on_b_draw_clicked();

private:
	void draw_circle(QPainter * painter);
    void draw_triangle(QPainter * painter);
    void draw_rect(QPainter * painter);

private:
	Ui::MainWindow *ui;

	QPainter * painter;
	QPixmap * pixmap;
	QPen * pen;
    QPixmap *as;
    int k;
    vector<figure*> m;
};

#endif // MAINWINDOW_H
