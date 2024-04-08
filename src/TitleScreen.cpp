#include "TitleScreen.h"
#include "World.h"

extern World world;

TitleScreen::TitleScreen()
{

}

TitleScreen::~TitleScreen()
{

}

void TitleScreen::init()
{
	string tmp, img, presskey;

	fstream stream;

	stream.open(CONFIG_FOLDER + "TitleScreen.txt");

	stream >> tmp >> img;
	stream >> tmp >> presskey >> m_presskey.rect.x >> m_presskey.rect.y >> m_presskey.rect.w >> m_presskey.rect.h;

	stream.close();

	m_presskey.texture = loadTexture(MENU_FOLDER + presskey);

}

void TitleScreen::run()
{
	drawObject(m_titlescreen);

	if (isAnyKeyPressed())
	{
		world.m_stateManager.changeGameState(GAME_STATE::GAME);
		return;
	}
}

void TitleScreen::destroy()
{
	SDL_DestroyTexture(m_titlescreen.texture);
}