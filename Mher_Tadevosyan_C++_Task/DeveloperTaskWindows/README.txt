Use VS IDE or another IDE where included Windows.h

For Mac` install mingw-w64 for cross compilation
brew install mingw-w64


Compile using the following expression`

x86_64-w64-mingw32-g++ -std=c++20 \
			core/Logger.cpp \
			core/MonitorManager.cpp \
			core/Utility.cpp \
			AppMonitor.cpp \
			MediaMonitor.cpp \
			FileOpenMonitor.cpp \
			main.cpp \
			-Icore \
			-o app-monitor.exe \
			-lpsapi \
			-lwtsapi32 \
			-lole32 \
			-lstrmiids \
			-lrstrtmgr \
			-lpthread \
			-static-libgcc \
			-static-libstdc++
