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
	string tmp, img;

	fstream stream;

	stream.open(CONFIG_FOLDER + "menu.txt");


	stream >> tmp >> img;
	stream >> tmp >> m_2pbutton.x >> m_2pbutton.y >> m_2pbutton.w >> m_2pbutton.h;
	stream >> tmp >> m_3pbutton.x >> m_3pbutton.y >> m_3pbutton.w >> m_3pbutton.h;
	stream >> tmp >> m_4pbutton.x >> m_4pbutton.y >> m_4pbutton.w >> m_4pbutton.h;



	stream.close();

	m_menu = loadTexture(img);

	m_nump = -1;

}

void Menu::run()
{

	drawObject(m_menu);

	if (isMouseInRect(InputManager::m_mouseCoor, m_2pbutton) && InputManager::isMousePressed()) {

		m_nump = 2;

		world.m_stateManager.changeGameState(GAME_STATE::GAME);
		return;
	}
	
	if (isMouseInRect(InputManager::m_mouseCoor, m_3pbutton) && InputManager::isMousePressed()) {

		m_nump = 3;

		world.m_stateManager.changeGameState(GAME_STATE::GAME);
		return;
	}
	
	if (isMouseInRect(InputManager::m_mouseCoor, m_4pbutton) && InputManager::isMousePressed()) {

		m_nump = 4;

		world.m_stateManager.changeGameState(GAME_STATE::GAME);
		return;
	}


}

void Menu::destroy()
{

	SDL_DestroyTexture(m_menu);

}
