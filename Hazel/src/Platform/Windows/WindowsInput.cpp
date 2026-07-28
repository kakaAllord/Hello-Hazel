#include "hzpch.h"
#include "WindowsInput.h"

#include <GLFW/glfw3.h>
#include "Hazel/Application.h"

namespace Hazel
{
	Input* Input::s_Instance = new WindowsInput();

	static GLFWwindow* GetGLFWWindow()
	{
		Application* app = Application::Get();
		return static_cast<GLFWwindow*>(app->GetWindow().GetNativeWindow());
	}

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto state = glfwGetKey(GetGLFWWindow(), keycode);
		return state == GLFW_PRESS || GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto state = glfwGetMouseButton(GetGLFWWindow(), button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		double xPos, yPos;
		glfwGetCursorPos(GetGLFWWindow(), &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}

	float WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}
}