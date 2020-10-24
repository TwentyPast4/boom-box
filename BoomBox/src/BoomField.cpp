#include "BoomField.h"

#include "GLFW/glfw3.h"

using namespace nanogui;

bool BoomField::mouse_button_event(const Vector2i& p, int button, bool down, int modifiers) {
	for (auto it = m_children.rbegin(); it != m_children.rend(); ++it) {
		Widget* child = *it;
		if (child->visible() && child->contains(p - m_pos) &&
			child->mouse_button_event(p - m_pos, button, down, modifiers))
			return true;
	}
	if (button == GLFW_MOUSE_BUTTON_1 && down && !m_focused)
		request_focus();
	return false;
}

bool BoomField::mouse_motion_event(const Vector2i& p, const Vector2i& rel, int button, int modifiers) {
	bool handled = false;

	for (auto it = m_children.rbegin(); it != m_children.rend(); ++it) {
		Widget* child = *it;
		if (!child->visible())
			continue;

		bool contained = child->contains(p - m_pos),
			prev_contained = child->contains(p - m_pos - rel);

		if (contained != prev_contained)
			handled |= child->mouse_enter_event(p, contained);

		if (contained || prev_contained)
			handled |= child->mouse_motion_event(p - m_pos, rel, button, modifiers);
	}

	return handled;
}

bool BoomField::scroll_event(const Vector2i& p, const Vector2f& rel) {
	for (auto it = m_children.rbegin(); it != m_children.rend(); ++it) {
		Widget* child = *it;
		if (!child->visible())
			continue;
		if (child->contains(p - m_pos) && child->scroll_event(p - m_pos, rel))
			return true;
	}
	return false;
}

bool BoomField::mouse_drag_event(const Vector2i&, const Vector2i&, int, int) {
	return false;
}

bool BoomField::mouse_enter_event(const Vector2i&, bool enter) {
	m_mouse_focus = enter;
	return false;
}