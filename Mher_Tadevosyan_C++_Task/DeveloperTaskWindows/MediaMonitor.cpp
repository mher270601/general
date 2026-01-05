#ifndef __MEDIAMONITOR__CPP__
#define __MEDIAMONITOR__CPP__

#include "MediaMonitor.hpp"
#include "core/Logger.hpp"
#include "core/Utility.hpp"
#include <Windows.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <string>
#include <vector>
#include <algorithm>

#pragma comment(lib, "Psapi.lib")

MediaMonitor::MediaMonitor() : m_running(false), m_lastCameraState(false), m_lastMicrophoneState(false){
}

MediaMonitor::~MediaMonitor(){
	Stop();
}

void MediaMonitor::Start(){
	m_running = true;
	m_thread = std::thread(&MediaMonitor::Run, this);
}

void MediaMonitor::Stop(){
	m_running = false;
	if(m_thread.joinable()){
		m_thread.join();
	}
}

void MediaMonitor::Run(){
	while(m_running){
		CheckMediaDevices();
		Sleep(2000);
	}
}

void MediaMonitor::CheckMediaDevices(){
	DWORD sessionId = WTSGetActiveConsoleSessionId();
	if(sessionId == 0xFFFFFFFF){
		return;
	}

	std::string username = Utility::GetUsernameFromSession(sessionId);

	bool cameraActive = IsProcessUsingCamera();
	bool microphoneActive = IsProcessUsingMicrophone();

	if(cameraActive != m_lastCameraState || username != m_lastLoggedUser){
		LogMediaStatus("CAMERA", cameraActive, username);
		m_lastCameraState = cameraActive;
	}

	if(microphoneActive != m_lastMicrophoneState || username != m_lastLoggedUser){
		LogMediaStatus("MICROPHONE", microphoneActive, username);
		m_lastMicrophoneState = microphoneActive;
	}

	m_lastLoggedUser = username;
}

bool MediaMonitor::IsProcessUsingCamera(){
	std::vector<std::string> cameraProcesses = {
		"Teams.exe", "zoom.exe", "chrome.exe", 
		"firefox.exe", "Skype.exe", "obs64.exe",
		"viber.exe", "discord.exe", "msteams.exe",
		"msedge.exe", "Camera.exe", "ManyCam.exe",
		"obs.exe", "bdcam.exe", "webcam.exe"
	};

	for(auto& proc : cameraProcesses){
		std::transform(proc.begin(), proc.end(), proc.begin(), ::tolower);
	}

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if(hSnapshot == INVALID_HANDLE_VALUE){
		return false;
	}

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	bool cameraInUse = false;

	if(Process32First(hSnapshot, &pe32)){
		do{
			std::string processName = pe32.szExeFile;
			std::transform(processName.begin(), processName.end(), processName.begin(), ::tolower);

			for(const auto& camProc : cameraProcesses){
				if(processName == camProc){
					cameraInUse = true;
					break;
				}
			}

			if(cameraInUse){
				break;
			}

		} while(Process32Next(hSnapshot, &pe32));
	}

	CloseHandle(hSnapshot);
	return cameraInUse;
}

bool MediaMonitor::IsProcessUsingMicrophone(){
	std::vector<std::string> micProcesses = {
		"Teams.exe", "zoom.exe", "chrome.exe", 
		"firefox.exe", "Skype.exe", "obs64.exe",
		"viber.exe", "discord.exe", "msteams.exe",
		"msedge.exe", "audiodg.exe", "SystemSettings.exe",
		"SoundRecorder.exe", "VoiceRecorder.exe", "obs.exe",
		"steam.exe", "WhatsApp.exe", "Telegram.exe"
	};

	for(auto& proc : micProcesses){
		std::transform(proc.begin(), proc.end(), proc.begin(), ::tolower);
	}

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if(hSnapshot == INVALID_HANDLE_VALUE){
		return false;
	}

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	bool micInUse = false;

	if(Process32First(hSnapshot, &pe32)){
		do{
			std::string processName = pe32.szExeFile;
			std::transform(processName.begin(), processName.end(), processName.begin(), ::tolower);

			for(const auto& micProc : micProcesses){
				if(processName == micProc){
					micInUse = true;
					break;
				}
			}

			if(micInUse){
				break;
			}

		} while(Process32Next(hSnapshot, &pe32));
	}

	CloseHandle(hSnapshot);
	return micInUse;
}

void MediaMonitor::LogMediaStatus(const std::string& deviceType, bool isActive, const std::string& username){
	std::string timestamp = Utility::GetUtcTimestamp();
	std::string status = isActive ? "ACTIVE" : "INACTIVE";

	std::string log = timestamp + " | User = " + username + " | " + deviceType + " = " + status;

	if(deviceType == "CAMERA"){
		Logger::Instance().LogCamera(log);
	} else if(deviceType == "MICROPHONE"){
		Logger::Instance().LogMicrophone(log);
	}

	Logger::Instance().LogEvent(log);
}

#endif // __MEDIAMONITOR__CPP__
