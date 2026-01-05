#ifndef __MEDIAMONITOR__HPP__
#define __MEDIAMONITOR__HPP__

#include "core/IMonitor.hpp"
#include <atomic>
#include <thread>
#include <Windows.h>
#include <string>

class MediaMonitor : public IMonitor{
public:
	MediaMonitor();
	~MediaMonitor();

	void Start() override;
	void Stop() override;

private:
	void Run();
	void CheckMediaDevices();

	bool IsProcessUsingCamera();
	bool IsProcessUsingMicrophone();
	void LogMediaStatus(const std::string& deviceType, bool isActive, const std::string& username);

	std::atomic<bool> m_running;
	std::thread m_thread;

	bool m_lastCameraState;
	bool m_lastMicrophoneState;
	std::string m_lastLoggedUser;
};

#endif // __MEDIAMONITOR__HPP__
