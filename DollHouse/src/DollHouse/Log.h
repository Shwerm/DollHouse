#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace DollHouse {

	class DOLLHOUSE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;


	};
	
}

// Core log Macros
#define DH_CORE_ERROR(...) ::DollHouse::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DH_CORE_WARN(...)  ::DollHouse::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DH_CORE_INFO(...)  ::DollHouse::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DH_CORE_TRACE(...) ::DollHouse::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DH_CORE_FATAL(...) ::DollHouse::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log Macros
#define DH_ERROR(...)      ::DollHouse::Log::GetClientLogger()->error(__VA_ARGS__)
#define DH_WARN(...)       ::DollHouse::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DH_INFO(...)       ::DollHouse::Log::GetClientLogger()->info(__VA_ARGS__)
#define DH_TRACE(...)      ::DollHouse::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DH_FATAL(...)      ::DollHouse::Log::GetClientLogger()->fatal(__VA_ARGS__)
