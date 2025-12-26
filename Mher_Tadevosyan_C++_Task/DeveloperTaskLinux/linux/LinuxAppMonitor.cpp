#ifndef __LINUX__APP__MONITOR__CPP__
#define __LINUX__APP__MONITOR__CPP__

#include "LinuxAppMonitor.hpp"
#include "../core/Utility.hpp"
#include "../core/Logger.hpp"

#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <unistd.h>
#include <limits.h>

LinuxAppMonitor::LinuxAppMonitor() : m_running(false) {}
LinuxAppMonitor::~LinuxAppMonitor() { 
	Stop(); 
}

void LinuxAppMonitor::Start(){
	m_running = true;
	m_thread = std::thread(&LinuxAppMonitor::Run, this);
}

void LinuxAppMonitor::Stop(){
	m_running = false;
	if(m_thread.joinable()){
		m_thread.join();
	}
}

void LinuxAppMonitor::Run(){
	Display* display = XOpenDisplay(nullptr);
	if(!display){
		std::cout << "Invalid display" << std::endl;
		return;
	}

	Logger logger("/home/" + Utility::GetUsername() + "/log-app");

	while(m_running){
		Window window;
		int revert;
		XGetInputFocus(display, &window, &revert);

		Atom pidAtom = XInternAtom(display, "_NET_WM_PID", True);
		Atom type;
		int format;
		unsigned long nitems, bytes;
		unsigned char* prop = nullptr;

		pid_t pid = -1;
		if(XGetWindowProperty(display, window, pidAtom, 0, 1, False, XA_CARDINAL, &type, &format, &nitems, &bytes, &prop) == Success){
			pid = *(pid_t*)prop;
			XFree(prop);
		}

		char title[256];
		XFetchName(display, window, reinterpret_cast<char**>(&prop));
		snprintf(title, sizeof(title), "%s", prop ? (char * )prop : "");
		
		if(prop){
			XFree(prop);
		}

		char exePath[PATH_MAX] = "";
		if(pid > 0){
			char link[64];
			snprintf(link, sizeof(link), "/proc/%d/exe", pid);
			readlink(link, exePath, sizeof(exePath));
		}

		logger.Log(Utility::GetUtcTimestamp() + " USER = " + Utility::GetUsername() + " PID = " + std::to_string(pid) + " EXE = " + exePath + " TITLE = " + title);
	}

	XCloseDisplay(display);
}

#endif // __LINUX__APP__MONITOR__CPP__
