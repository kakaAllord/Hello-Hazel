#pragma once

#include "Application.h"

#include "Log.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HZ_WARN("Logger Initialized!");
	HZ_CORE_ERROR("Hello Hazel");

	auto App = Hazel::CreateApplication();
	App->Run();
	delete App;
}

#endif