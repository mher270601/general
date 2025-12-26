#ifndef __IMONITOR__HPP__
#define __IMONITOR__HPP__

class IMonitor{
public:
	virtual ~IMonitor() = default;
	virtual void Start() = 0;
	virtual void Stop() = 0;
};

#endif // __IMONITOR__HPP__
