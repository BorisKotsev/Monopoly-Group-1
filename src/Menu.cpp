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
	string tmp, img, b2img, b3img, b4img, playimg;

	fstream stream;

	stream.open(CONFIG_FOLDER + "menu.txt");


	stream >> tmp >> img;
	stream >> tmp >> b2img >> m_2pbutton.rect.x >> m_2pbutton.rect.y >> m_2pbutton.rect.w >> m_2pbutton.rect.h;
	stream >> tmp >> b3img >> m_3pbutton.rect.x >> m_3pbutton.rect.y >> m_3pbutton.rect.w >> m_3pbutton.rect.h;
	stream >> tmp >> b4img >> m_4pbutton.rect.x >> m_4pbutton.rect.y >> m_4pbutton.rect.w >> m_4pbutton.rect.h;
	stream >> tmp >> playimg >> m_play.rect.x >> m_play.rect.y >> m_play.rect.w >> m_play.rect.h;

	stream.close();

	m_drawb = false;
	m_drawplay = true;

	m_play.texture = loadTexture(MENU_FOLDER + playimg);
	m_2pbutton.texture = loadTexture(MENU_FOLDER + b2img);
	m_3pbutton.texture = loadTexture(MENU_FOLDER + b3img);
	m_4pbutton.texture = loadTexture(MENU_FOLDER + b4img);

	m_menu = loadTexture(MENU_FOLDER + img);

	m_nump = -1;

}

void Menu::run()
{

	drawObject(m_menu);
	
	
	if (m_drawplay == true) {

	drawObject(m_play);

	}

	if (m_drawb == true) {
		
		drawObject(m_2pbutton);
		drawObject(m_3pbutton);
		drawObject(m_4pbutton);

	}

	if (isMouseInRect(InputManager::m_mouseCoor, m_2pbutton.rect) && InputManager::isMousePressed()) {

		m_nump = 2;

		world.m_stateManager.changeGameState(GAME_STATE::GAME);
		return;
	}
	
	if (isMouseInRect(InputManager::m_mouseCoor, m_3pbutton.rect) && InputManager::isMousePressed()) {

		m_nump = 3;

		world.m_stateManager.changeGameState(GAME_STATE::GAME);
		return;
	}
	
	if (isMouseInRect(InputManager::m_mouseCoor, m_4pbutton.rect) && InputManager::isMousePressed()) {

		m_nump = 4;

		world.m_stateManager.changeGameState(GAME_STATE::GAME);
		return;
	}
	
	if (isMouseInRect(InputManager::m_mouseCoor, m_play.rect) && InputManager::isMousePressed()) {
		
		m_drawplay = false;
		m_drawb = true;
		

	}

}

void Menu::destroy()
{

	SDL_DestroyTexture(m_menu);

}
