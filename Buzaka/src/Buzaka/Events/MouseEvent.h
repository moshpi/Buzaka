#pragma once

#include "Event.h"

namespace Buzaka {

    class MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y) {}

        [[nodiscard]] inline float GetX() const { return m_MouseX; }
        [[nodiscard]] inline float GetY() const { return m_MouseY; }

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: (" << m_MouseX << ", " << m_MouseY << ')';
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategory_Input | EventCategory_Mouse)

    private:
        float m_MouseX, m_MouseY;
    };

    class MouseScrolledEvent : public Event {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset) {}

        [[nodiscard]] inline float GetXOffset() const { return m_XOffset; }
        [[nodiscard]] inline float GetYOffset() const { return m_YOffset; }

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: (" << m_XOffset << ", " << m_YOffset << ')';
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategory_Input | EventCategory_Mouse)

    private:
        float m_XOffset, m_YOffset;
    };

    class MouseButtonEvent : public Event {
    public:
        [[nodiscard]] inline int GetMouseButton() const { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategory_Input | EventCategory_MouseButton)

    protected:
        explicit MouseButtonEvent(int button)
            : m_Button(button) {}

        int m_Button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent {
    public:
        explicit MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {}

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent {
    public:
        explicit MouseButtonReleasedEvent(int button)
        : MouseButtonEvent(button) {}

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::MouseButtonReleased)
    };

}

