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

	string backgorundImg, tmp, diceConfig, popupConf="Popup.txt", bexit;

	stream.open(CONFIG_FOLDER+ GAME_FOLDER + configFile);

    stream >> tmp >> backgorundImg;

	stream >> tmp >> diceConfig;

	stream >> tmp >> bexit;

	stream.close();
	
	initDice(diceConfig);
	m_popup.init(popupConf);
	m_exit.init(bexit, MENU_FOLDER);
	m_background = loadTexture(GAME_FOLDER + backgorundImg);
	numberOfPlayers = world.m_stateManager.m_menu->m_nump;
	loadQuestions();
	initplayersUI();
	initUI();
	loadPlayers();



	m_testField.init("enterProduct.txt");
	m_playerOnTurnField.init("PlayerOnTurn.txt");
	m_popup.show("test", 200, 1);
	m_playerOnTurnField.setText("Player on turn: " + to_string(playerOnTurn));

	m_HPopup.init("housePopup.txt");
}

void Board::update()
{
	m_rollButton.update();
	rollDice();
	m_testField.update();
	m_playerOnTurnField.update();
	m_popup.update();
	m_exit.update();
	updateUI();

	if (m_exit.isClicked()) {

	world.m_stateManager.changeGameState(GAME_STATE::NONE);
		return;
	}
	
}

void Board::draw()
{
	
	drawObject(m_background);
	drawObject(m_dice1Drawable);
	drawObject(m_dice2Drawable);
	drawUI();

	m_popup.draw();
	m_rollButton.draw();
	//m_testField.draw();
	m_playerOnTurnField.draw();
	for (int player = 0; player < players.size(); player++) {
		players[player].draw();
	}

	m_exit.draw();
	
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

void Board::initUI() {

	fstream stream;
	string tmp, img;

	for (int i = 0; i < numberOfPlayers; i++) {

		stream.open(CONFIG_FOLDER + FIELD_FOLDER + "p" + to_string(i + 1) + ".txt");	
		stream >> tmp >> m_p[i].rect.x >> m_p[i].rect.y >> m_p[i].rect.w >> m_p[i].rect.h;
		stream >> tmp >> img;
		
		stream.close();
		m_p[i].texture = loadTexture(FIELD_FOLDER + img);

	}


	

}

void Board::updateUI()
{

	for (int i = 0; i < numberOfPlayers; i++) {

		m_igrachiUI[i].update();
	}

}

void Board::drawUI()
{


	for (int i = 0; i < numberOfPlayers; i++) {

		m_igrachiUI[i].draw();
		drawObject(m_p[i]);
	}
}

void Board::loadPlayers()
{
	for (int i = 1; i <= numberOfPlayers; i++)
	{
		string tmp = "Player" + to_string(i) + ".txt";

		Player _player;

		_player.init(tmp);

		players.push_back(_player);
	}

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
	
	m_dice1Drawable.texture = m_diceFaces[1];
	m_dice2Drawable.texture = m_diceFaces[6];
	m_dice1 = 1;
	m_dice2 = 6;
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

			doubleAmount = 0; //go to jail
			if (playerOnTurn > numberOfPlayers) {
				playerOnTurn = 1;
			}
			

		}


		m_dice1 = rand() % 6 + 1;
		m_dice2 = rand() % 6 + 1;

		m_dice1Drawable.texture = m_diceFaces[m_dice1];
		m_dice2Drawable.texture = m_diceFaces[m_dice2];

		//cout << playerOnTurn << ' ';
		
		m_testField.setText(to_string(m_dice1 + m_dice2));

		m_playerOnTurnField.setText("Player on turn: " + to_string(playerOnTurn));
		players[playerOnTurn - 1].movement(m_dice1 + m_dice2);
	}
	
}

void Board::initplayersUI()
{
	string tmp, p1, p2, p3, p4;
	fstream stream;
	stream.open(CONFIG_FOLDER+GAME_FOLDER+ "playersUI.txt");

	stream >> tmp >> p1;
	stream >> tmp >> p2;
	stream >> tmp >> p3;
	stream >> tmp >> p4;

	stream.close();

	m_igrachiUI[0].init(p1);
	m_igrachiUI[1].init(p2);
	m_igrachiUI[2].init(p3);
	m_igrachiUI[3].init(p4);

	m_igrachiUI[0].m_needToDrawBackground = true;
	m_igrachiUI[1].m_needToDrawBackground = true;
	m_igrachiUI[2].m_needToDrawBackground = true;
	m_igrachiUI[3].m_needToDrawBackground = true;

	m_igrachiUI[0].setText(to_string(1500));
	m_igrachiUI[1].setText(to_string(1500));
	m_igrachiUI[2].setText(to_string(1500));
	m_igrachiUI[3].setText(to_string(1500));


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
