#pragma once

#include "Imgnpch.h"
#include "Imgn/Core/PlatformDetection.h"
#include "Imgn/Core/Log.h"
#include "Imgn/Renderer/Renderer.h"
#include "Imgn/Window/Window.h"

namespace Imgn
{

    class Imgn_API Application
    {
    
    public:

        Application(); 
        ~Application(); 
        void Init() const;
        void Run() const;

    private:

    };

    std::shared_ptr<Application> CreateApplication(); // defined in the client for flexibility.

};