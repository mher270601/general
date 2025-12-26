#ifndef __UTILITY__HPP__
#define __UTILITY__HPP__

#include <string>
#include <Windows.h>

class Utility {
public:
	static std::string GetUtcTimestamp();
	static std::string GetUsernameFromSession(DWORD sessionId);
};

#endif // __UTILITY__HPP__
