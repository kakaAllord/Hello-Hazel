#pragma once

#include "Core.h"
#include "hzpch.h"
#include "Window.h"

namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application();
		~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
		
	Application* CreateApplication();
}