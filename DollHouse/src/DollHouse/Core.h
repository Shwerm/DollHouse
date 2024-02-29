#pragma once

#ifdef DH_PLATFORM_WINDOWS
	#ifdef DH_BUILD_DLL
		#define DOLLHOUSE_API __declspec(dllexport)
	#else
		#define DOLLHOUSE_API __declspec(dllimport)
	#endif
#else
	#error Doll House only supports Windows!
#endif
