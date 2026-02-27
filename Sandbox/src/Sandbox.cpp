#include "Imgn.h"

class Sandbox : public Imgn::Application
{
public:
private:
};

std::shared_ptr<Imgn::Application> Imgn::CreateApplication()
{
    return std::make_shared<Sandbox>();
}
