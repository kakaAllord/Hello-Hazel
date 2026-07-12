#pragma once

#include "hzpch.h"
#include "Event.h"

namespace Hazel {
	class HAZEL_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(int MouseX, int MouseY)
			: m_MouseX(MouseX), m_MouseY(MouseY) {}

		inline int GetMouseX() const { return m_MouseX; }
		inline int GetMouseY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		int m_MouseX, m_MouseY;
	};

	class HAZEL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(int OffsetX, int OffsetY)
			: m_OffsetX(OffsetX), m_OffsetY(OffsetY) {
		}

		inline int GetMouseX() const { return m_OffsetX; }
		inline int GetMouseY() const { return m_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_OffsetX << ", " << m_OffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse  | EventCategoryInput)
	private:
		int m_OffsetX, m_OffsetY;
	};

	class HAZEL_API MouseButtonEvent : public Event
	{
	public:
		virtual int GetButton() const { return m_Button;  }
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int Button)
			:m_Button(Button) {}

		int m_Button;
	};

	class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int Button)
			: MouseButtonEvent(Button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int Button)
			: MouseButtonEvent(Button) {
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}