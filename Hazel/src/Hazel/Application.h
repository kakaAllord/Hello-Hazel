#pragma once

#include "Core.h"

namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application();
		~Application();

		void Run();

	private:
		bool m_Running = true;
	};
		
	Application* CreateApplication();
}