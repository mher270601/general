#include "core/MonitorManager.hpp"
#include <Windows.h>

int main(){
	MonitorManager manager;
	manager.Initialize();
	manager.StartAll();

	Sleep(INFINITE);
	return 0;
}
