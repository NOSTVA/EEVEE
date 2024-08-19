#pragma once

#ifdef EV_PLATFORM_WINDOWS
	#ifdef EV_BUILD_DLL
		#define EEVEE_API __declspec(dllexport)
	#else
		#define EEVEE_API __declspec(dllimport)
	#endif
#else
	#error Eevee only supports windows!
#endif

#ifdef EV_DEBUG
	#define EV_ENABLE_ASSERTS
#endif

#ifdef EV_ENABLE_ASSERTS
	#define EV_ASSERT(x, ...) {if(!(x)) { EV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define EV_CORE_ASSERT(x, ...) {if(!(x)) { EV_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define EV_ASSERT(x, ...)
	#define EV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
