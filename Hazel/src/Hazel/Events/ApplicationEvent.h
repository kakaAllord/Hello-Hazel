#pragma once

#include "hzpch.h"
#include "Event.h"



namespace Hazel {

	class HAZEL_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() { return m_Width; }
		inline unsigned int GetHeight() { return m_Height; }

		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizedEvent: " << m_Width << "," << m_Height;
			return ss.str();
		}
	private:
		unsigned int m_Width, m_Height;
	};

	class HAZEL_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent(){}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAZEL_API ApplicationTick: public Event
	{
	public:
		ApplicationTick() {}

		EVENT_CLASS_TYPE(ApplicationTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAZEL_API ApplicationUpdate : public Event
	{
	public:
		ApplicationUpdate() {}

		EVENT_CLASS_TYPE(ApplicationUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAZEL_API ApplicationRender : public Event
	{
	public:
		ApplicationRender() {}

		EVENT_CLASS_TYPE(ApplicationRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}