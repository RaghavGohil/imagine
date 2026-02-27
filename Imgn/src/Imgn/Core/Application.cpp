#include "Imgn/Core/Application.h"

namespace Imgn{

    Application::Application(){}
    Application::~Application(){}

    void Application::Init() const
    {

        Log::Init();
        Renderer::Init();
    }

    void Application::Run() const
    {
        auto window = Window::Create();
        while(true)
        {
            window->OnUpdate();
        }
    }

};