#pragma once

#include "Core.h"
#include "Event/Event.h"

namespace DollHouse 
{
	class DOLLHOUSE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

