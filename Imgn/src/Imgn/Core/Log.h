#pragma once

#include "Imgnpch.h"
#include "Imgn/Core/PlatformDetection.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Imgn
{

    class Imgn_API Log
    {

    public:
        
        Log() = delete;
        Log(const Log&) = delete;
        Log& operator=(const Log&) = delete;

        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetLogCore() { return s_LogCore; }
        inline static std::shared_ptr<spdlog::logger>& GetLogClient() { return s_LogClient; }

    private:

        static std::shared_ptr<spdlog::logger> s_LogCore;
        static std::shared_ptr<spdlog::logger> s_LogClient;

    };

    #define Imgn_TRACE  spdlog::level::trace
    #define Imgn_DEBUG  spdlog::level::debug
    #define Imgn_INFO   spdlog::level::info
    #define Imgn_WARN   spdlog::level::warn
    #define Imgn_ERR    spdlog::level::err
    #define Imgn_CTCL   spdlog::level::critical

    // Logging macros for core and client messages
    #define Imgn_LOG_CORE(severity, msg, ...) \
        ::Imgn::Log::GetLogCore()->log(spdlog::source_loc{__FILE__, __LINE__, __FUNCTION__}, severity, msg, ##__VA_ARGS__)

    #define Imgn_LOG_CLIENT(severity, msg, ...) \
        ::Imgn::Log::GetLogClient()->log(spdlog::source_loc{__FILE__, __LINE__, __FUNCTION__}, severity, msg, ##__VA_ARGS__)

};
