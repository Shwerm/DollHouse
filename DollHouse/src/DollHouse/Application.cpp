#include "dhpch.h"
#include "Application.h"

#include "DollHouse/Event/ApplicationEvent.h"
#include "DollHouse/Log.h"

namespace DollHouse {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			DH_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			DH_TRACE(e);
		}
		while (true);
	}
}
