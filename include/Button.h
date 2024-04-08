#pragma once

#include"defines.h"

class Button {
public:

	
	
	bool isClicked();
	void init(string config_file, string folder);
	void update();
	void draw();
	void destroy();
private:
	int m_maxIncrease;
	int m_increasePerFrameX, m_increasePerFrameY;
	int m_currIncreaseX, m_currIncreaseY;

	bool m_isClicked = false;
	Drawable m_button_drawable;
	SDL_Rect originalRect;


	void hover();
	void reset();

};