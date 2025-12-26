#include "../core/MonitorManager.hpp"
#include "LinuxAppMonitor.hpp"

#include <memory>
#include <atomic>
#include <csignal>
#include <unistd.h>

static std::atomic<bool> running(true);

void HandleSignal(int) {
    running = false;
}

int main() {
    signal(SIGINT, HandleSignal);
    signal(SIGTERM, HandleSignal);

    MonitorManager manager;
    manager.AddMonitor(std::make_unique<LinuxAppMonitor>());
    manager.StartAll();

    while (running) {
        sleep(1);
    }

    manager.StopAll();
    return 0;
}
