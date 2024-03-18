#pragma once

#include "defines.h"
#include "State.h"


class Menu : public State
{
public:
	Menu();
	~Menu();

	void init();
	void run();
	void destroy();
	int m_nump;

private:
	 SDL_Texture* m_menu;
	 Drawable m_2pbutton;
	 Drawable m_3pbutton;
	 Drawable m_4pbutton;
	 Drawable m_play;
	 bool m_drawb;
	 bool m_drawplay;
};