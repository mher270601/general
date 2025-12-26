#ifndef __APPMONITOR__CPP__
#define __APPMONITOR__CPP__

#include "AppMonitor.hpp"
#include "core/Logger.hpp"
#include "core/Utility.hpp"
#include <Windows.h>
#include <Psapi.h>

#pragma comment(lib, "Psapi.lib")

AppMonitor::AppMonitor() : m_running(false) {}

AppMonitor::~AppMonitor(){
	Stop();
}

void AppMonitor::Start(){
	m_running = true;
	m_thread = std::thread(&AppMonitor::Run, this);
}

void AppMonitor::Stop(){
	m_running = false;
	if(m_thread.joinable()){
		m_thread.join();
	}
}

void AppMonitor::Run(){
	while(m_running){
		HWND hwnd = GetForegroundWindow();
		if(hwnd){
			DWORD pid;
			GetWindowThreadProcessId(hwnd, &pid);

			char title[256];
			GetWindowTextA(hwnd, title, sizeof(title));

			std::string log = Utility::GetUtcTimestamp() + " PID =" + std::to_string(pid) + " TITLE = " + title;

			Logger::Instance().Log(log);
		}
		Sleep(1000);
	}
}

#endif // __APPMONITOR__CPP__
