#include "Imgn/Renderer/Renderer.h"

namespace Imgn
{

    Renderer::Context Renderer::context;

    void Renderer::Init()
    {

        context = Renderer::Context::OpenGL; // the default render api would be opengl
        Imgn_LOG_CORE(Imgn_INFO,"Renderer is set to OpenGL."); 
        Imgn_LOG_CORE(Imgn_INFO,"Renderer is initalized!"); 
    }

};