#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qwt_plot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void drawContents( QPainter *painter );

private slots:
    void paintEvent( QPaintEvent *event );

private:
    Ui::MainWindow *ui;

    QwtPlot *plot;
};

#endif // MAINWINDOW_H
