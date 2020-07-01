#ifndef SYSINFOWINDOWSIMPL_H
#define SYSINFOWINDOWSIMPL_H

#include <QtGlobal>
#include <QVector>
#include "sysinfo.h"
// Forward declaration instead of including #windows into .h keep it into .cpp
typedef struct _FILETIME FILETIME;
class SysInfoWindowsImpl : public SysInfo
{
public:
    SysInfoWindowsImpl();
    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;


private:
    /*function that will perform the Windows API call to
    retrieve system timing information and return values in a generic format.*/
    QVector<qulonglong> cpuRawData();

    /* is our second helper. It will convert a
    Windows FILETIME struct syntax to a qulonglong type*/
    qulonglong convertFileTime(const FILETIME& filetime) const;
private:

    /*variable that will store system timing (idle,
    Kernel, and User) at a given moment.*/
    QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOWINDOWSIMPL_H
