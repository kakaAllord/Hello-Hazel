#pragma once

#include "hzpch.h"
#include "Hazel/Core.h"


namespace Hazel {

	enum class EventType
	{
		None = 0,
		WindowResize, WindowMoved, WindowFocused, WindowLostFocus, WindowClose,
		ApplicationTick, ApplicationUpdate, ApplicationRender,
		KeyPressed, KeyReleased,
		MouseMoved, MouseScrolled,
		MouseButtonPressed, MouseButtonReleased,
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4),
	};

	#define EVENT_CLASS_TYPE(type)	static EventType GetEventStaticType() { return EventType::##type; }\
									virtual EventType GetEventType() const override { return GetEventStaticType(); }\
									virtual const char* GetName() const override  { return #type; }

	#define EVENT_CLASS_CATEGORY(category)	virtual int  GetEventCategoryFlags() const override { return category; }

	class HAZEL_API Event
	{
	private:
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetEventCategoryFlags() const = 0;
		virtual inline std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category) 
		{
			return GetEventCategoryFlags() & category; 
		}

	protected:
		bool m_Handled = false;
	};

	class HAZEL_API EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{

		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetEventStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

};