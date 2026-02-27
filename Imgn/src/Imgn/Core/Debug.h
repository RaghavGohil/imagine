#pragma once

#include "Imgn/Core/Log.h" 

#ifdef Imgn_ENABLE_DEBUG
	#if defined(Imgn_PLATFORM_WINDOWS)
		#define Imgn_DEBUGBREAK() __debugbreak()
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define Imgn_ENABLE_ASSERTS
#else
	#define Imgn_DEBUGBREAK()
#endif

#ifdef Imgn_ENABLE_ASSERTS

    #define Imgn_ASSERT(condition, ...) { \
        if (!(condition)) { \
            Imgn_LOG_CORE(Imgn_ERR, "Assertion failed: {0}", __VA_ARGS__); \
            Imgn_DEBUGBREAK(); \
        } \
    }

    #define Imgn_ASSERT_NO_MSG(condition) { \
        if (!(condition)) { \
            Imgn_LOG_CORE(Imgn_ERR, "Assertion '{0}' failed at {1}:{2}", #condition); \
            Imgn_DEBUGBREAK(); \
        } \
    }

#else
    #define Imgn_ASSERT(...)
    #define Imgn_ASSERT_NO_MSG(...)
#endif