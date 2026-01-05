#ifndef __MONITORMANAGER_CPP__
#define __MONITORMANAGER_CPP__

#include "MonitorManager.hpp"
#include "./../AppMonitor.hpp"
#include "./../MediaMonitor.hpp"
#include "./../FileOpenMonitor.hpp"

void MonitorManager::Initialize(){
	m_monitors.emplace_back(std::make_unique<AppMonitor>());
	m_monitors.emplace_back(std::make_unique<MediaMonitor>());
	m_monitors.emplace_back(std::make_unique<FileOpenMonitor>());
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

#endif // __MONITORMANAGER__CPP__
