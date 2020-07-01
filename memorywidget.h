#ifndef MEMORYWIDGET_H
#define MEMORYWIDGET_H

#include "sysinfowidget.h"
#include <QtCharts/QLineSeries>

class MemoryWidget : public SysInfoWidget
{
    Q_OBJECT
    public:
    explicit MemoryWidget(QWidget *parent = 0);
    protected slots:
    void updateSeries() override;
    private:
    QtCharts::QLineSeries* mSeries;
    qint64 mPointPositionX;
};

#endif // MEMORYWIDGET_H
