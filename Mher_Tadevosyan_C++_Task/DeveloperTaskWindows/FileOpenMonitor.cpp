#ifndef __FILEOPENMONITOR__CPP__
#define __FILEOPENMONITOR__CPP__

#include "FileOpenMonitor.hpp"
#include "core/Logger.hpp"
#include "core/Utility.hpp"
#include <Windows.h>
#include <Psapi.h>
#include <TlHelp32.h>
#include <restartmanager.h>
#include <iostream>

#pragma comment(lib, "Rstrtmgr.lib")
#pragma comment(lib, "Psapi.lib")

FileOpenMonitor::FileOpenMonitor() : m_running(false) {
	GetSystemTimeAsFileTime(&m_lastOpenTime);
	m_lastOpenerPid = 0;
}

FileOpenMonitor::~FileOpenMonitor(){
	Stop();
}

void FileOpenMonitor::Start(){
	m_running = true;
	m_thread = std::thread(&FileOpenMonitor::Run, this);
}

void FileOpenMonitor::Stop(){
	m_running = false;
	if(m_thread.joinable()){
		m_thread.join();
	}
}

void FileOpenMonitor::Run(){
	while(m_running){
		CheckFileAccess();
		Sleep(2000);
	}
}

void FileOpenMonitor::CheckFileAccess(){
	const std::string targetFile = "C:\\log-events.txt";

	DWORD openerPid = 0;
	if(IsFileOpenByProcess(targetFile, openerPid)){
		FILETIME currentTime;
		GetSystemTimeAsFileTime(&currentTime);

		ULONGLONG lastTime = ((ULONGLONG)m_lastOpenTime.dwHighDateTime << 32) | m_lastOpenTime.dwLowDateTime;
		ULONGLONG currTime = ((ULONGLONG)currentTime.dwHighDateTime << 32) | currentTime.dwLowDateTime;

		if(openerPid != m_lastOpenerPid || (currTime - lastTime) > 50000000){ // 5 seconds in 100-ns intervals
			std::string processName = GetProcessNameFromPid(openerPid);
			std::string username = GetUsernameFromPid(openerPid);
			std::string timestamp = Utility::GetUtcTimestamp();

			std::string log = timestamp + " | User = " + username + 
				" | PID = " + std::to_string(openerPid) + 
				" | Process = " + processName + 
				" | File = " + targetFile;

			Logger::Instance().LogFileOpen(log);

			m_lastOpenTime = currentTime;
			m_lastOpenerPid = openerPid;
		}
	}
}

bool FileOpenMonitor::IsFileOpenByProcess(const std::string& filePath, DWORD& openerPid){
	DWORD dwSession;
	WCHAR szSessionKey[CCH_RM_SESSION_KEY + 1] = { 0 };
	DWORD dwError = RmStartSession(&dwSession, 0, szSessionKey);

	if(dwError != ERROR_SUCCESS){
		return false;
	}

	std::wstring wFilePath(filePath.begin(), filePath.end());
	LPCWSTR lpcwstrPath = wFilePath.c_str();

	dwError = RmRegisterResources(dwSession, 1, &lpcwstrPath, 0, NULL, 0, NULL);

	if(dwError != ERROR_SUCCESS){
		RmEndSession(dwSession);
		return false;
	}

	DWORD dwReason;
	UINT nProcInfoNeeded = 0;
	UINT nProcInfo = 0;
	RM_PROCESS_INFO* rgpi = NULL;

	dwError = RmGetList(dwSession, &nProcInfoNeeded, &nProcInfo, NULL, &dwReason);

	if(dwError == ERROR_MORE_DATA){
		rgpi = new RM_PROCESS_INFO[nProcInfoNeeded];
		nProcInfo = nProcInfoNeeded;

		dwError = RmGetList(dwSession, &nProcInfoNeeded, &nProcInfo, rgpi, &dwReason);

		if(dwError == ERROR_SUCCESS){
			if(nProcInfo > 0){
				openerPid = rgpi[0].Process.dwProcessId;
				delete[] rgpi;
				RmEndSession(dwSession);
				return true;
			}
		}
		delete[] rgpi;
	}

	RmEndSession(dwSession);
	return false;
}

std::string FileOpenMonitor::GetProcessNameFromPid(DWORD pid){
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
	if(hProcess == NULL){
		return "UNKNOWN";
	}

	char processName[MAX_PATH] = { 0 };
	DWORD size = sizeof(processName);

	if(QueryFullProcessImageNameA(hProcess, 0, processName, &size)){
		CloseHandle(hProcess);
		return processName;
	}

	CloseHandle(hProcess);
	return "UNKNOWN";
}

std::string FileOpenMonitor::GetUsernameFromPid(DWORD pid){
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
	if(hProcess == NULL){
		return "UNKNOWN";
	}

	HANDLE hToken = NULL;
	if(!OpenProcessToken(hProcess, TOKEN_QUERY, &hToken)){
		CloseHandle(hProcess);
		return "UNKNOWN";
	}

	DWORD tokenInfoSize = 0;
	GetTokenInformation(hToken, TokenUser, NULL, 0, &tokenInfoSize);

	if(tokenInfoSize == 0){
		CloseHandle(hToken);
		CloseHandle(hProcess);
		return "UNKNOWN";
	}

	PTOKEN_USER pTokenUser = (PTOKEN_USER)new BYTE[tokenInfoSize];

	if(GetTokenInformation(hToken, TokenUser, pTokenUser, tokenInfoSize, &tokenInfoSize)){
		DWORD usernameSize = 0;
		DWORD domainSize = 0;
		SID_NAME_USE sidType;

		LookupAccountSid(NULL, pTokenUser->User.Sid, NULL, &usernameSize, NULL, &domainSize, &sidType);

		if(usernameSize > 0){
			char* username = new char[usernameSize];
			char* domain = new char[domainSize];

			if(LookupAccountSid(NULL, pTokenUser->User.Sid, username, &usernameSize, domain, &domainSize, &sidType)){
				std::string result = std::string(domain) + "\\" + std::string(username);
				delete[] username;
				delete[] domain;
				delete[] pTokenUser;
				CloseHandle(hToken);
				CloseHandle(hProcess);
				return result;
			}

			delete[] username;
			delete[] domain;
		}
	}

	delete[] pTokenUser;
	CloseHandle(hToken);
	CloseHandle(hProcess);
	return "UNKNOWN";
}

#endif // __FILEOPENMONITOR__CPP__
