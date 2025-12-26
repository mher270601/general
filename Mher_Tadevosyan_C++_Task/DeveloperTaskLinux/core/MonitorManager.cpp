#ifndef __MONITOR__MANAGER__CPP__
#define __MONITOR__MANAGER__CPP__

#include "MonitorManager.hpp"
//#include "AppMonitor.hpp"

void MonitorManager::AddMonitor(std::unique_ptr<IMonitor> monitor){
	m_monitors.emplace_back(std::move(monitor));
}

void MonitorManager::StartAll(){
	for(auto& m : m_monitors){
		m->Start();
	}

}

void MonitorManager::StopAll(){
	for(auto& m : m_monitors){
		m->Stop();
	}
}

#endif // __MONITOR__MANAGER__CPP__
