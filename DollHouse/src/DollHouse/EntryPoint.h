#pragma once

#ifdef DH_PLATFORM_WINDOWS

extern DollHouse::Application* DollHouse::CreateApplication();

int main(int argc, char** argv)
{
	auto app = DollHouse::CreateApplication();
	app->Run();
	delete app;
}


#endif
