#include "Menu.h"
#include "World.h"
#include "InputManager.h"

extern World world;

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::init()
{
	string tmp, img, b2, b3, b4, play, bexit;

	fstream stream;

	stream.open(CONFIG_FOLDER + MENU_FOLDER + "menu.txt");


	stream >> tmp >> img;
	stream >> tmp >> b2;
	stream >> tmp >> b3;
	stream >> tmp >> b4;
	stream >> tmp >> play;
	stream >> tmp >> bexit;

	stream.close();

	m_drawb = false;
	m_drawplay = true;

	m_2pbutton.init(b2, MENU_FOLDER);
	m_3pbutton.init(b3, MENU_FOLDER);
	m_4pbutton.init(b4, MENU_FOLDER);
	m_play.init(play, MENU_FOLDER);
	m_exit.init(bexit, MENU_FOLDER);

	m_menu = loadTexture(MENU_FOLDER + img);

	m_nump = -1;

}

void Menu::run()
{

	drawObject(m_menu);
	m_2pbutton.update();
	m_3pbutton.update();
	m_4pbutton.update();
	m_play.update();
	m_exit.update();

	if (m_drawplay == true) {

		m_play.draw();
	}

	if (m_drawb == true) {
		
		m_2pbutton.draw();
		m_3pbutton.draw();
		m_4pbutton.draw();
		

	}
	
	m_exit.draw();
	

	if (m_2pbutton.isClicked()) {

		m_nump = 2;

		world.m_stateManager.changeGameState(GAME_STATE::GAME);
		return;
	}
	
	if (m_3pbutton.isClicked()) {

		m_nump = 3;

		world.m_stateManager.changeGameState(GAME_STATE::GAME);
		return;
	}
	
	if (m_4pbutton.isClicked()) {

		m_nump = 4;

		world.m_stateManager.changeGameState(GAME_STATE::GAME);
		return;
	}


	if (m_play.isClicked()) {

		m_drawplay = false;
		m_drawb = true;

	}
	
	if (m_exit.isClicked()) {

		world.m_stateManager.changeGameState(GAME_STATE::NONE);
		return;
	}
}

void Menu::destroy()
{

	SDL_DestroyTexture(m_menu);
	m_2pbutton.destroy();
	m_3pbutton.destroy();
	m_4pbutton.destroy();
	m_play.destroy();
	m_exit.destroy();

}
