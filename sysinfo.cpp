#include "sysinfo.h"



#include <QtGlobal>
#ifdef Q_OS_WIN
#include "sysinfowindowsimpl.h"
#elif defined(Q_OS_LINUX)
#include "sysinfolinuximpl.h"
#endif
SysInfo& SysInfo::instance()
{
    #ifdef Q_OS_WIN
    static SysInfoWindowsImpl singleton;
    #elif defined(Q_OS_LINUX)
    static SysInfoLinuxImpl singleton;
    #endif
    return singleton;
}
SysInfo::SysInfo()
{

}

SysInfo::~SysInfo()
{

}
