#ifndef __APPMONITOR__HPP__
#define __APPMONITOR__HPP__

#include "core/IMonitor.hpp"
#include <atomic>
#include <thread>

class AppMonitor : public IMonitor{
public:
	AppMonitor();
	~AppMonitor();

	void Start() override;
	void Stop() override;

private:
	void Run();

	std::atomic<bool> m_running;
	std::thread m_thread;
};

#endif // __APPMONITOR__HPP__
