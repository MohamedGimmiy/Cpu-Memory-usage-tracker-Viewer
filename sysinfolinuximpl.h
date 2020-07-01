#ifndef SYSINFOLINUXIMPL_H
#define SYSINFOLINUXIMPL_H


#include "sysinfo.h"
#include <QtGlobal>
#include <QVector>
class SysInfoLinuxImpl : public SysInfo
{
public:
SysInfoLinuxImpl();
void init() override;
double cpuLoadAverage() override;
double memoryUsed() override;

private:
    QVector<qulonglong> cpuRawData();
private:
    QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOLINUXIMPL_H
