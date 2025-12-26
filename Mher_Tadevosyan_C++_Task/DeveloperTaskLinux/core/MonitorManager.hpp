#ifndef __MONITORMANAGER__HPP__
#define __MONITORMANAGER__HPP__

#include <vector>
#include <memory>
#include "IMonitor.hpp"

class MonitorManager{
public:
	void AddMonitor(std::unique_ptr<IMonitor> monitor);
	void StartAll();
	void StopAll();

private:
	std::vector<std::unique_ptr<IMonitor> > m_monitors;
};

#endif // __MONITORMANAGER__HPP__
