#pragma once

#include <nanogui/widget.h>

class BoomField : public nanogui::Widget
{
public:
	BoomField();

	/// override mouse events
	virtual bool mouse_button_event(const nanogui::Vector2i& p, int button, bool down, int modifiers);
	virtual bool mouse_motion_event(const nanogui::Vector2i& p, const nanogui::Vector2i& rel, int button, int modifiers);
	virtual bool mouse_drag_event(const nanogui::Vector2i& p, const nanogui::Vector2i& rel, int button, int modifiers);
	virtual bool mouse_enter_event(const nanogui::Vector2i& p, bool enter);
	virtual bool scroll_event(const nanogui::Vector2i& p, const nanogui::Vector2f& rel);

	/// Responsible for drawing the Button.
	virtual void draw(NVGcontext* ctx) override;
};