#ifndef __LINUX__APP__MONITOR__HPP__
#define __LINUX__APP__MONITOR__HPP__

#include "../core/IMonitor.hpp"
#include <atomic>
#include <thread>

class LinuxAppMonitor : public IMonitor{
public:
	LinuxAppMonitor();
	~LinuxAppMonitor();

	void Start() override;
	void Stop() override;

private:
	void Run();
	std::atomic<bool> m_running;
	std::thread m_thread;
};

#endif // __LINUX__APP__MONITOR__HPP__
