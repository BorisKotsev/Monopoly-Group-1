#pragma once

#include "State.h"
#include "Board.h"

class WinScreen : public State
{
public:

	WinScreen();
	~WinScreen();

	

	void init();
	void destroy();
	void run();
private:
	SDL_Rect m_play_Again;
	SDL_Rect m_quit;
	SDL_Texture* m_backround;
};