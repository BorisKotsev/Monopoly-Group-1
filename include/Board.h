#pragma once

#include "Engine.h"
#include "Question.h"
#include "Button.h"
#include "TextField.h"
#include "Popup.h"
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
	Button m_rollButton;
	Drawable m_dice1Drawable, m_dice2Drawable;
	Drawable m_playerOnTurnDrawable;
	Drawable m_p[4];

	
	
	int m_dice1, m_dice2;
	void initDice(string Config);
	void loadQuestions();
	void rollDice();
	int numberOfPlayers;
	int playerOnTurn = 1;
	int doubleAmount = -1;

	void updateUI();
	void drawUI();
	void initUI();
	
	int numQuestions = 20; //TEST

	int questionIndexTEST = 0;

	TextField m_testField;
	TextField m_playerOnTurnField;
	Popup m_popup;
	
	TextField m_igrachiUI[4];
	void initplayersUI();

};