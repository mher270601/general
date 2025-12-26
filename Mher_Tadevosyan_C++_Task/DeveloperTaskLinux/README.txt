Compile using the following expression`

g++ -std=c++20 \            
	core/Logger.cpp \
	core/MonitorManager.cpp \
	core/Utility.cpp \
	linux/LinuxAppMonitor.cpp \
	linux/main.cpp \
	-o app-monitor \
	-I/opt/X11/include \
	-L/opt/X11/lib \
	-lX11 \
	-pthread
