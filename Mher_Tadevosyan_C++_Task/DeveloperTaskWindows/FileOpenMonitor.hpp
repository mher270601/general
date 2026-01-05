#ifndef __FILEOPENMONITOR__HPP__
#define __FILEOPENMONITOR__HPP__

#include "core/IMonitor.hpp"
#include <atomic>
#include <thread>
#include <Windows.h>
#include <string>

class FileOpenMonitor : public IMonitor{
public:
	FileOpenMonitor();
	~FileOpenMonitor();

	void Start() override;
	void Stop() override;

private:
	void Run();
	void CheckFileAccess();
	bool IsFileOpenByProcess(const std::string& filePath, DWORD& openerPid);
	std::string GetProcessNameFromPid(DWORD pid);
	std::string GetUsernameFromPid(DWORD pid);

	std::atomic<bool> m_running;
	std::thread m_thread;

	FILETIME m_lastOpenTime;
	DWORD m_lastOpenerPid;
};

#endif // __FILEOPENMONITOR__HPP__
