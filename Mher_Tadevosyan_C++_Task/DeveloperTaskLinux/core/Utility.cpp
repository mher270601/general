#ifndef __UTILITY__CPP__
#define __UTILITY__CPP__

#include "Utility.hpp"
#include <ctime>
#include <pwd.h>
#include <unistd.h>

std::string Utility::GetUtcTimestamp(){
	time_t now = time(nullptr);
	tm gmt{};
	gmtime_r(&now, &gmt);

	char buf[64];
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S UTC", &gmt);
	return buf;
}

std::string Utility::GetUsername(){
	passwd* pw = getpwuid(getuid());
	return pw ? pw->pw_name : "unknown";
}

#endif // __UTILITY__CPP__
