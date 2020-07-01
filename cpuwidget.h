#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include "sysinfowidget.h"
#include <QtCharts/QPieSeries>
#include "sysinfo.h"
class CpuWidget : public SysInfoWidget
{
    /*we override the SysInfoWidget::updateSeries() slot, we have to include
    the Q_OBJECT macro to allow CPUWidget to respond to
    the SysInfoWidgetmRefreshTimer::timeout() signal.*/
Q_OBJECT
public:
    explicit CpuWidget(QWidget* parent = 0);
protected slots:
    void updateSeries() override;
private:
    QtCharts::QPieSeries* mSeries;
};

#endif // CPUWIDGET_H
