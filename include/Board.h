#pragma once

#include "Engine.h"

class Board
{
public:
	Board();
	~Board();

	void init();
	void update();
	void draw();
	void destroy();

private:
	SDL_Texture* m_background;
	SDL_Texture* m_diceFaces[7];
	SDL_Rect m_rollButton;
	Drawable m_dice1Drawable, m_dice2Drawable;
	Drawable tmpd;
	int m_dice1, m_dice2;
	void initDice(string Config);
	void rollDice();
	
};