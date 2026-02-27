#pragma once

#ifdef _WIN32
    #define Imgn_PLATFORM_WINDOWS
#elif defined(__linux__)
    #define Imgn_PLATFORM_LINUX
#else
    #error Imgn only supports Windows and Linux for now!
#endif

// DLL Export/Import Macros for Windows
#ifdef Imgn_PLATFORM_WINDOWS
    #ifdef Imgn_DYNAMIC_LINK
        #ifdef Imgn_BUILD_DLL
            #define Imgn_API __declspec(dllexport)
        #else
            #define Imgn_API __declspec(dllimport)
        #endif
    #else
        #define Imgn_API
    #endif
#else
    #define Imgn_API
#endif
