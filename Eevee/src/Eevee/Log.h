#pragma once
#include "evpch.h"
#include "Core.h"
#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>

namespace Eevee {
	class EEVEE_API Log
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


#define EV_CORE_TRACE(...) ::Eevee::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EV_CORE_INFO(...)  ::Eevee::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EV_CORE_WARN(...)  ::Eevee::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EV_CORE_ERROR(...) ::Eevee::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EV_CORE_FATAL(...) ::Eevee::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define EV_TRACE(...)      ::Eevee::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EV_INFO(...)       ::Eevee::Log::GetClientLogger()->info(__VA_ARGS__)
#define EV_WARN(...)       ::Eevee::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EV_ERROR(...)      ::Eevee::Log::GetClientLogger()->error(__VA_ARGS__)
#define EV_FATAL(...)      ::Eevee::Log::GetClientLogger()->fatal(__VA_ARGS__)