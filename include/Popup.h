#pragma once
#include "TextField.h"
#include "Button.h"
class Popup {
public:
	Popup();
	~Popup();

	void init(string config);
	void draw();
	void update();
	void destroy();
	void show(string name, int price);
	void hide();
private:
	TextField m_text;
	TextField m_topText;
	bool m_showing;

	Button m_yes;
	Button m_no;
	Drawable m_backround;
};