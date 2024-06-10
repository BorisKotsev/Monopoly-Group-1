#pragma once

#include "defines.h"
#include "State.h"
#include "Button.h"

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
	 Button m_2pbutton;
	 Button m_3pbutton;
	 Button m_4pbutton;	
	 Button m_play;
	 Button m_exit;
	 bool m_drawb;
	 bool m_drawplay;
};