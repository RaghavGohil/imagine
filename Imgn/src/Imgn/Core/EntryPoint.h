#pragma once

#include "Imgnpch.h"

extern std::shared_ptr<Imgn::Application> Imgn::CreateApplication();

int main(int argc, char** argv) {
    std::shared_ptr<Imgn::Application> application = Imgn::CreateApplication();
    application->Init();
    application->Run();
}