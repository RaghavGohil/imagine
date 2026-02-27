#pragma once

#include "Imgnpch.h"
#include "Imgn/Window/Window.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace Imgn {

    class WindowGLFW : public Window {
    public:
        WindowGLFW(const WindowOptions& options);
        ~WindowGLFW();

        uint32_t GetWidth() const override;
        uint32_t GetHeight() const override;
        void SetVsync(bool enabled) override;
        bool IsVsync() const override;
        void OnUpdate() override;

    private:
        GLFWwindow* m_Window;
    };

}
