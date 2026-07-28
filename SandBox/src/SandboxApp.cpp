#include <Hazel.h>
#include <stdio.h>

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		:Layer("Example") {}

	void OnUpdate() override
	{
		HZ_INFO("{}", Hazel::Input::GetMousePosition().first);
	}

	void OnEvent(Hazel::Event& e) override
	{
		HZ_TRACE("{}", e.ToString());
	}

};

class Sandbox : public Hazel::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushLayer(new Hazel::ImGuiLayer());
	}
	~Sandbox() {}

};

Hazel::Application* Hazel::CreateApplication()
{	
	return new Sandbox();
}