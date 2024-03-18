#include "WinScreen.h"
#include "World.h"
extern World world;
WinScreen::WinScreen()
{
}

WinScreen::~WinScreen()
{
}

void WinScreen::init()
{
	string tmp, backraundImageStr;
	fstream stream;
	stream.open(CONFIG_FOLDER+"WinScreenInit.txt");
	stream >> tmp >> backraundImageStr;
	stream >> tmp >> m_play_Again.x >> m_play_Again.y >> m_play_Again.w >> m_play_Again.h;
	stream >> tmp >> m_quit.x >> m_quit.y >> m_quit.w >> m_quit.h;
	stream.close();
	m_backround = loadTexture(backraundImageStr);
}

void WinScreen::destroy()
{
	SDL_DestroyTexture(m_backround);
}

void WinScreen::run()
{
	drawObject(m_backround);
	if (InputManager::isMousePressed()) {
		if (isMouseInRect(InputManager::m_mouseCoor, m_play_Again)){
			world.m_stateManager.changeGameState(GAME_STATE::MENU);
		}
		if (isMouseInRect(InputManager::m_mouseCoor, m_quit)) {
			world.m_stateManager.init(GAME_STATE::NONE);
		}
	}
}
