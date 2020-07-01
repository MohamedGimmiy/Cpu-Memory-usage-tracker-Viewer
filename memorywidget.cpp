#include "memorywidget.h"
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLineSeries>
#include <QLinearGradient>
#include <QPen>
#include<sysinfo.h>
using namespace QtCharts;


const int CHART_X_RANGE_COUNT = 50;
const int CHART_X_RANGE_MAX = CHART_X_RANGE_COUNT - 1;

const int COLOR_DARK_BLUE = 0x209fdf;
const int COLOR_LIGHT_BLUE = 0xbfdfef;
const int PEN_WIDTH = 3;


MemoryWidget::MemoryWidget(QWidget *parent) :
SysInfoWidget(parent),
mSeries(new QLineSeries(this)),
mPointPositionX(0)
{
    // setting gradient
    QPen pen(COLOR_DARK_BLUE);
    pen.setWidth(PEN_WIDTH);
    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(1.0, COLOR_DARK_BLUE);
    gradient.setColorAt(0.0, COLOR_LIGHT_BLUE);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);

    // we want to display an area not only a line that changes
    // we add this line to our area
    QAreaSeries* areaSeries = new QAreaSeries(mSeries);

    // setting gradient
    areaSeries->setPen(pen);
    areaSeries->setBrush(gradient);

    QChart* chart = chartView().chart();
    chart->addSeries(areaSeries);
    chart->setTitle("Memory used");

    /*The chart->createDefaultAxes() function creates an X and Y axis based on
    the areaSeries type. If we used a 3D series, the createDefaultAxes()
    function would have added a Z axis.*/
    chart->createDefaultAxes();

    // Hide the X axis tick values
    chart->axisX()->setVisible(false);

    // To define the number of points we want to display
    chart->axisX()->setRange(0, CHART_X_RANGE_MAX);
    chart->axisY()->setRange(0, 100);
}

void MemoryWidget::updateSeries()
{
    double memoryUsed = SysInfo::instance().memoryUsed();
    // we increament the x axis of our line and apply the change our y axis
    mSeries->append(mPointPositionX++, memoryUsed);

    // if number of data points excceeded the chart points
    // we scroll
    if (mSeries->count() > CHART_X_RANGE_COUNT) {
        QChart* chart = chartView().chart();
        chart->scroll(chart->plotArea().width()
        / CHART_X_RANGE_MAX, 0);

        /*We then remove the point at the index 0 with mSeries->remove(0)
         *  to ensure that the widget will not store
            an infinite dataset.*/
        mSeries->remove(0);
    }
}
