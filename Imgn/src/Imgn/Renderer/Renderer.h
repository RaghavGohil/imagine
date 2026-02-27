#pragma once

#include "Imgn/Core/Log.h"

namespace Imgn
{

class Renderer
{

public:
    Renderer() = delete;
    static void Init();
    enum class Context : uint8_t
    {
        None,
        OpenGL,
        // add more here?
    };
    static Context context;
    
private:

};

};
