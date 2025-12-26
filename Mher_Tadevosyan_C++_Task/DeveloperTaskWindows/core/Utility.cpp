#ifndef __UTILITY__CPP__
#define __UTILITY__CPP__

#include "Utility.hpp"
#include <Wtsapi32.h>
#pragma comment(lib, "Wtsapi32.lib")

std::string Utility::GetUtcTimestamp(){
	SYSTEMTIME st;
	GetSystemTime(&st);
	char buf[64];
	sprintf_s(buf, "%04d-%02d-%02d %02d:%02d:%02d UTC", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
	return buf;
}

std::string Utility::GetUsernameFromSession(DWORD sessionId){
	LPSTR buffer = nullptr;
	DWORD bytes = 0;
	std::string username = "UNKNOWN";

	if(WTSQuerySessionInformationA(WTS_CURRENT_SERVER_HANDLE, sessionId, WTSUserName, &buffer, &bytes)){
		username = buffer;
		WTSFreeMemory(buffer);
	}

	return username;
}

#endif // __UTILITY__CPP__
