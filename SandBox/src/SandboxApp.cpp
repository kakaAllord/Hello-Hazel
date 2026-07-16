#include <Hazel.h>
#include <stdio.h>

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		:Layer("Example") {}

	void OnUpdate() override
	{
		HZ_INFO("ExampleLayer::OnUpdate() Called");
	}

	void OnEvent(Hazel::Event& e) override
	{
		//HZ_TRACE("{}", e.ToString());
		std::string str = e.ToString();

		printf("%s\n", str.c_str());

		HZ_TRACE("{}", str);
		printf("An Event has been received~~\n");
		HZ_TRACE("{}", e.GetName());
		HZ_TRACE("Hi");
	}

};

class Sandbox : public Hazel::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {}

};

Hazel::Application* Hazel::CreateApplication()
{	
	return new Sandbox();
}