#pragma once

#include "Engine.h"
#include "Question.h"

class Board
{
public:
	Board();
	~Board();

	void init();
	void update();
	void draw();
	void destroy();
	int2 getDices();

	vector <Question> m_questions;

private:
	SDL_Texture* m_background;
	SDL_Texture* m_diceFaces[7];
	SDL_Rect m_rollButton;
	Drawable m_dice1Drawable, m_dice2Drawable;
	Drawable m_playerOnTurnDrawable;
	SDL_Texture* m_numbers[5];
	
	int m_dice1, m_dice2;
	void initDice(string Config);
	void loadQuestions();
	void rollDice();
	int numberOfPlayers;
	int playerOnTurn = 1;
	int doubleAmount = 0;
	
	int numQuestions = 20; //TEST

	int questionIndexTEST = 0;

};