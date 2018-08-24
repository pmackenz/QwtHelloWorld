#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qwt_plot.h"
#include "qwt_plot_curve.h"
#include "qwt_legend.h"
#include <qwt_plot_shapeitem.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_textlabel.h>
#include <qwt_text.h>
#include <qwt_symbol.h>

#include <QGridLayout>
#include <QPainter>
#include <QFont>

#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    plot = new QwtPlot(ui->centralWidget);
    plot->setCanvasBackground(QBrush(Qt::white));

    QGridLayout *lyt = new QGridLayout();
    lyt->addWidget(plot,0,0);
    lyt->setMargin(6);
    ui->centralWidget->setLayout(lyt);

    QwtPlotCurve *curve = new QwtPlotCurve();

    QVector<QPointF> theSamples;

    for (int i=0; i<100; i++)
    {
        double x = 2.*M_PI*i/100.;
        double y = sin(x);
        theSamples.append(QPointF(x,y));
    }
    curve->setSamples(theSamples);
    curve->attach(plot);

    QwtPlotMarker *d_marker2 = new QwtPlotMarker();
    d_marker2->setLineStyle( QwtPlotMarker::HLine );
    d_marker2->setLabelAlignment( Qt::AlignRight | Qt::AlignBottom );
    d_marker2->setLinePen( QColor( 200, 150, 0 ), 0, Qt::DashDotLine );
    d_marker2->setSymbol( new QwtSymbol( QwtSymbol::Diamond,
                                         QColor( Qt::yellow ),
                                         QColor( Qt::green ),
                                         QSize( 8, 8 ) ) );
    d_marker2->attach( plot );

    QString label = "QwtPlotMarker: Hello, World!";

    QwtText text( label );
    text.setFont( QFont( "Helvetica", 14, QFont::Bold ) );
    text.setColor( QColor( 200, 150, 0 ) );

    d_marker2->setValue( M_PI, 0.5 );
    d_marker2->setLabel( text );

    QwtText title( "QwtPlotTextLabel: Hello, World!" );
    title.setRenderFlags( Qt::AlignHCenter | Qt::AlignTop );

    QFont font;
    font.setBold( true );
    title.setFont( font );

    QwtPlotTextLabel *titleItem = new QwtPlotTextLabel();
    titleItem->setText( title );
    titleItem->attach( plot );

    //connect(plot->canvas(), SIGNAL(paintEvent(QPaintEvent)), this, SLOT(paintEvent(QPaintEvent)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent( QPaintEvent *event )
{
    //QWidget::paintEvent( event );

    QPainter *painter = new QPainter(plot);
    painter->setClipRect( contentsRect() );
    drawContents( painter );
}

void MainWindow::drawContents( QPainter *painter )
{
    QwtText title( "QwtPlotTextLabel in drawContent: Hello, World!" );
    title.setRenderFlags( Qt::AlignHCenter | Qt::AlignBottom );

    QFont font;
    font.setBold( true );
    title.setFont( font );

    QwtPlotTextLabel *titleItem = new QwtPlotTextLabel();
    titleItem->setText( title );
    titleItem->attach( plot );

}

