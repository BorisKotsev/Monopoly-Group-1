#pragma once

#include "State.h"
//#include "Board.h"
#include "Button.h"
class WinScreen : public State
{
public:

	WinScreen();
	~WinScreen();

	

	void init();
	void destroy();
	void run();
private:

	SDL_Texture* m_backround;
	Button m_playAgain;
	Button m_quit;
	
};