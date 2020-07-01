#include "sysinfowidget.h"
#include <QVBoxLayout>
using namespace QtCharts;

SysInfoWidget::SysInfoWidget(QWidget *parent,
                            int startDelayMs,
                            int updateSeriesDelayMs) :
                            QWidget(parent),
                            mChartView(this)
{
    mRefreshTimer.setInterval(updateSeriesDelayMs);

    // Timer signal when the timer is over it fires a signal timeout
    connect(&mRefreshTimer, &QTimer::timeout,
    this, &SysInfoWidget::updateSeries);

    // start our timer
    QTimer::singleShot(startDelayMs,
    [this] { mRefreshTimer.start(); });

        // to make chart smooth
    mChartView.setRenderHint(QPainter::Antialiasing);

    mChartView.chart()->legend()->setVisible(false);

    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(&mChartView);

    setLayout(layout);
}

QChartView& SysInfoWidget::chartView()
{
    return mChartView;
}
