#include "hzpch.h"
#include "Application.h"

#include "Events/applicationEvent.h"
#include "Log.h"

namespace Hazel {
	Application::Application()
	{

	}
	
	Application::~Application()
	{

	}

	void Application::Run()
	{
		bool printed = false;
		while (m_Running)
		{
			WindowResizeEvent e(1200, 720); 
			if (!printed)
			{
				if(e.IsInCategory(EventCategoryApplication))
					HZ_WARN(e.ToString());
				if (e.IsInCategory(EventCategoryInput))
					HZ_ERROR(e.ToString());
				printed = true;
			}
		}
	}
}