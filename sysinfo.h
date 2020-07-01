#ifndef SYSINFO_H
#define SYSINFO_H


class SysInfo
{
public:
     static SysInfo& instance();
    virtual ~SysInfo();
    /*This function allows the derived class to perform any initialization
    process depending on the OS platform*/
    virtual void init() = 0;

    /*This function calls some OS-specific code to retrieve the
    average CPU load and returns it as a percentage value*/
    virtual double cpuLoadAverage() = 0;
    /*This function calls some OS-specific code to retrieve the memory
    used and returns it as a percentage value*/
    virtual double memoryUsed() = 0;

protected:
     explicit SysInfo();
private:
     SysInfo(const SysInfo& rhs) = delete ;
     SysInfo& operator=(const SysInfo& rhs) = delete ;
};

#endif // SYSINFO_H
