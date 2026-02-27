#pragma once
#include "stb_image.h"
#include <iostream>
#include <glad/gl.h>
#include <vector>
#include "Shader.h"

class Skybox{
public:
    Skybox(std::vector<std::string> faces); 
    unsigned int ID;
    void bind() const;
    void unbind() const;
};