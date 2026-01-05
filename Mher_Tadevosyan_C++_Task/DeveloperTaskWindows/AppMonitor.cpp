#ifndef __APPMONITOR__CPP__
#define __APPMONITOR__CPP__

#include "AppMonitor.hpp"
#include "core/Logger.hpp"
#include "core/Utility.hpp"
#include <Windows.h>
#include <Psapi.h>
#include <Wtsapi32.h>

#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "Wtsapi32.lib")

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
		DWORD sessionId = WTSGetActiveConsoleSessionId();
		if(sessionId == 0xFFFFFFFF){
			continue;
		}

		HWND hwnd = GetForegroundWindow();
		if(hwnd){
			DWORD pid;
			GetWindowThreadProcessId(hwnd, &pid);

			char title[256];
			GetWindowTextA(hwnd, title, sizeof(title));

			HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
			char exePath[MAX_PATH] = "UNKNOWN";
			if(hProcess){
				GetModuleFileNameExA(hProcess, NULL, exePath, MAX_PATH);
				CloseHandle(hProcess);
			}

			std::string username = Utility::GetUsernameFromSession(sessionId);
			std::string timestamp = Utility::GetUtcTimestamp();

			std::string log = timestamp + " | Session = " + std::to_string(sessionId) +
				" | User = " + username +
				" | PID = " + std::to_string(pid) +
				" | Exe = " + exePath +
				" | Title = " + title;

			Logger::Instance().LogApp(log);
		}
		Sleep(100);
	}
}

#endif // __APPMONITOR__CPP__
