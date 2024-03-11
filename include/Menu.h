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
	 SDL_Rect m_2pbutton;
	 SDL_Rect m_3pbutton;
	 SDL_Rect m_4pbutton;
};