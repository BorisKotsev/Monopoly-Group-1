#include "Board.h"
#include "Presenter.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "World.h"

extern World world; 

Board::Board()
{

}

Board::~Board()
{

}

void Board::init()
{
	string configFile ="boardInit.txt";

	fstream stream;

	string backgorundImg, tmp, diceConfig;

	stream.open(CONFIG_FOLDER+ GAME_FOLDER + configFile);

    stream >> tmp >> backgorundImg;

	stream >> tmp >> diceConfig;


	stream.close();
	
	initDice(diceConfig);
	m_background = loadTexture(GAME_FOLDER + backgorundImg);
	numberOfPlayers = world.m_stateManager.m_menu->m_nump;
	loadQuestions();

	m_testField.init("enterProduct.txt");
}

void Board::update()
{
	m_rollButton.update();
	rollDice();
	m_testField.update();
}

void Board::draw()
{
	drawObject(m_background);
	drawObject(m_dice1Drawable);
	drawObject(m_dice2Drawable);
	drawObject(m_playerOnTurnDrawable);
	m_rollButton.draw();
	m_testField.draw();
	
	/*if (questionIndexTEST >= m_questions.size())
	{
		questionIndexTEST = 0;
	}

	m_questions[questionIndexTEST].run();

	if (m_questions[questionIndexTEST].m_answer == 1)
	{
		cout << m_questions[questionIndexTEST].getMoney() << endl;
		m_questions[questionIndexTEST].m_answer = -1;

		questionIndexTEST++;
	}
	else if (m_questions[questionIndexTEST].m_answer == 0)
	{
		cout << m_questions[questionIndexTEST].loseMoney() << endl;
		m_questions[questionIndexTEST].m_answer = -1;

		questionIndexTEST++;
	}*/
}

void Board::destroy()
{
	SDL_DestroyTexture(m_background);
	m_rollButton.destroy();
}

int2 Board::getDices()
{
	int2 tmp;
	tmp.x = m_dice1;
	tmp.y = m_dice2;
	

	return tmp;
}

void Board::initDice(string Config)
{
	string tmp, rollButtonConf;
	fstream stream;

	stream.open(CONFIG_FOLDER + GAME_FOLDER + Config);
	stream >> tmp >> m_dice1Drawable.rect.x >> m_dice1Drawable.rect.y >> m_dice1Drawable.rect.w >> m_dice1Drawable.rect.h;
	stream >> tmp >> m_dice2Drawable.rect.x >> m_dice2Drawable.rect.y >> m_dice2Drawable.rect.w >> m_dice2Drawable.rect.h;
	stream >> tmp >> rollButtonConf;
	stream >> tmp >> m_playerOnTurnDrawable.rect.x >> m_playerOnTurnDrawable.rect.y >> m_playerOnTurnDrawable.rect.w >> m_playerOnTurnDrawable.rect.h;
	stream.close();

	m_rollButton.init(rollButtonConf, GAME_FOLDER);
	for (int i = 1; i <= 6; i++) {
		tmp = GAME_FOLDER + "diceFaces\\DiceFace" + to_string(i) + ".bmp";
		m_diceFaces[i] = loadTexture(tmp);
	}
	for (int i = 1; i <= 4; i++) {
		tmp = GAME_FOLDER + "numbers\\" + to_string(i) + ".bmp";
		m_numbers[i] = loadTexture(tmp);
	}
	m_playerOnTurnDrawable.texture = m_numbers[1];
	m_dice1Drawable.texture = m_diceFaces[1];
	m_dice2Drawable.texture = m_diceFaces[1];

}

void Board::rollDice()
{
	if (m_rollButton.isClicked()) {
		
		playerOnTurn++;
		if (m_dice1 == m_dice2 && doubleAmount < 4) {
			doubleAmount++;
			playerOnTurn--;

		}
		else {

			doubleAmount = 0;
			if (playerOnTurn > numberOfPlayers) {
				playerOnTurn = 1;
			}
			m_playerOnTurnDrawable.texture = m_numbers[playerOnTurn];

		}
		m_dice1 = rand() % 6 + 1;
		m_dice2 = rand() % 6 + 1;

		m_dice1Drawable.texture = m_diceFaces[m_dice1];
		m_dice2Drawable.texture = m_diceFaces[m_dice2];

		//cout << playerOnTurn << ' ';
		
		m_testField.setText(to_string(m_dice1 + m_dice2));
	}
	
}

void Board::loadQuestions()
{
	for (int i = 1; i <= numQuestions; i++)
	{
		string tmp = "Question" + to_string(i) + ".txt";

		Question _question;

		_question.init(tmp);

		m_questions.push_back(_question);
	}
}
