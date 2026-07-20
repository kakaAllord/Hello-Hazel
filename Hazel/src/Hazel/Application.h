#pragma once

#include "Core.h"
#include "hzpch.h"
#include "Window.h"


#include "LayerStack.h"

#include "Events/ApplicationEvent.h"

namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application();
		~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		static Application* Get() { return s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	};
		
	Application* CreateApplication();
}