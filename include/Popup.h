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
	void show(string name, int price, int type);
	void hide();
private:
	TextField m_text;
	TextField m_topText;
	bool m_showing;
	int m_type;
	/*
	Types:
	1: Ask would the player like to buy something
	2: The player has to pay to another player
	3: Taxes
	4: going trough the start (doesn't need name)
	5: going to jain (doesn't need name nor price)
	*/

	Button m_yes;
	Button m_no;
	Button m_ok;
	Drawable m_backround;
};

