#ifndef __MONITORMANAGER_CPP__
#define __MONITORMANAGER_CPP__

#include "MonitorManager.hpp"
#include "AppMonitor.hpp"

void MonitorManager::Initialize(){
	m_monitors.emplace_back(std::make_unique<AppMonitor>());
	// MediaMonitor, FileOpenMonitor added here
}

void MonitorManager::StartAll(){
	for(auto& m : m_monitors){
		m->Start();
	}

	void MonitorManager::StopAll(){
		for(auto& m : m_monitors){
			m->Stop();
		}
	}

#endif // __MONITORMANAGER__CPP__
