Use VS IDE or another IDE where included Windows.h

Compile using the following expression`

g++ -std=c++20 \
	 core/Logger.cpp \
	 core/MonitorManager.cpp \
	 core/Utility.cpp \
	 AppMonitor.cpp \
	 main.cpp \
	 -Icore \
	 -o app-monitor \
	 -pthread
