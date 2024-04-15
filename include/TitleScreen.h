#pragma once

#include "defines.h"
#include "State.h"

class TitleScreen : public State
{
public:
	TitleScreen();
	~TitleScreen();

	void init();
	void run();
	void destroy();

private:
	SDL_Texture* m_titlescreen;
	DrawableWithOpp m_presskey;
};