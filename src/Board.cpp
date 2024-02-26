#include "Board.h"
#include "Presenter.h"
#include "InputManager.h"
#include "SoundManager.h"

Board::Board()
{

}

Board::~Board()
{

}

void Board::init()
{
	string configFile = "boardInit.txt";

	fstream stream;

	string backgorundImg, tmp, diceConfig;

	stream.open(CONFIG_FOLDER + configFile);

    stream >> tmp >> backgorundImg;

	stream >> tmp >> diceConfig;


	stream.close();
	initDice(diceConfig);
	m_background = loadTexture(backgorundImg);

	//loadQuestions();
}

void Board::update()
{
	rollDice();
}

void Board::draw()
{
	drawObject(m_background);
	drawObject(m_dice1Drawable);
	drawObject(m_dice2Drawable);
	
}

void Board::destroy()
{
	SDL_DestroyTexture(m_background);
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
	
	
	string tmp;
	fstream stream;
	stream.open(CONFIG_FOLDER + Config);
	stream >> tmp >> m_dice1Drawable.rect.x >> m_dice1Drawable.rect.y >> m_dice1Drawable.rect.w >> m_dice1Drawable.rect.h;
	stream >> tmp >> m_dice2Drawable.rect.x >> m_dice2Drawable.rect.y >> m_dice2Drawable.rect.w >> m_dice2Drawable.rect.h;
	stream >> tmp >> m_rollButton.x >> m_rollButton.y >> m_rollButton.w >> m_rollButton.h;
	stream.close();

	for (int i = 1; i <= 6; i++) {
		tmp = "DiceFace" + to_string(i) + ".bmp";
		m_diceFaces[i] = loadTexture(tmp);
	}
	
	m_dice1Drawable.texture = m_diceFaces[1];
	m_dice2Drawable.texture = m_diceFaces[1];
	//m_dice1Drawable.rect = { 100,100,100,100 };
	//tmpd.rect=
}

void Board::rollDice()
{
	if (InputManager::isMousePressed() && isMouseInRect(InputManager::m_mouseCoor, m_rollButton)) {
		m_dice1 = rand() % 6 + 1;
		m_dice2 = rand() % 6 + 1;

		m_dice1Drawable.texture = m_diceFaces[m_dice1];
		m_dice2Drawable.texture = m_diceFaces[m_dice2];
		
	}
	
}

void Board::loadQuestions()
{
	fstream stream;
	string tmp;

	stream.open(CONFIG_FOLDER + "questions.txt");

	while (!stream.eof())
	{
		stream >> tmp;

		Question _question;

		_question.init(tmp);

		m_questions.push_back(_question);
	}
}
