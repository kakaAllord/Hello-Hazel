#pragma once

#include "hzpch.h"
#include "Event.h"

namespace Hazel
{
	class HAZEL_API KeyEvent : public Event{
	
	public:
		inline int GetKeyCode() const { return m_KeyCode;  }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

	protected:
		KeyEvent(unsigned int KeyCode)
			: m_KeyCode(KeyCode) {}

		unsigned int m_KeyCode;
	};

	class HAZEL_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int KeyCode, int repeatCount)
			:KeyEvent(KeyCode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class HAZEL_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int KeyCode)
			:KeyEvent(KeyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class HAZEL_API KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(int KeyCode)
			:KeyEvent(KeyCode) {
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}