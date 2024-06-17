#pragma once

#include "Button.h"
#include "ConfiglessTTF.h"
class TTFButton : public Button{
public:
	TTFButton();
	~TTFButton();
	
	void init(SDL_Rect rect, int increasePF, int maxIncrease, string background);
	void update();
	void draw();
	void destroy();
	bool isVisible();
	void setVisibility(bool visible);
	void setXY(int2 coor);
	void setText(string text);
private:
	ConfiglessTTF m_text;
	SDL_Rect m_originalTextRect;
	SDL_Rect m_currTextRect;
	void hover();
	void reset();
	bool m_visible;
};