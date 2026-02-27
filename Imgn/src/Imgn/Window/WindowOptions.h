#pragma once
#include "Imgnpch.h"

namespace Imgn {

    struct WindowOptions {
        uint32_t Width = 1920;
        uint32_t Height = 1080;
        std::string Title = "Imgn Application";

        WindowOptions(uint32_t width = 1920, uint32_t height = 1080, const std::string& title = "Imgn Application")
            : Width(width), Height(height), Title(title) {}
    };

}
