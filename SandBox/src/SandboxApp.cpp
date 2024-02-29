#include <DollHouse.h>

class Sandbox : public DollHouse::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

DollHouse::Application* DollHouse::CreateApplication()
{
	return new Sandbox();
}