#pragma once

#ifdef DH_PLATFORM_WINDOWS

extern DollHouse::Application* DollHouse::CreateApplication();

int main(int argc, char** argv)
{
	DollHouse::Log::Init();
	DH_CORE_WARN("Initialised Log!");
	int a = 5;
	DH_INFO("Hello! Var={0}", a);



	auto app = DollHouse::CreateApplication();
	app->Run();
	delete app;
}


#endif
