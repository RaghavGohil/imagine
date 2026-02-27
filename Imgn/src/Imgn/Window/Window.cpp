#include "Imgn/Window/Window.h"
#include "Imgn/Window/WindowGLFW.h"

namespace Imgn {

    std::unique_ptr<Window> Window::Create(const WindowOptions& options) {
        return std::make_unique<WindowGLFW>(options);
    }

}
