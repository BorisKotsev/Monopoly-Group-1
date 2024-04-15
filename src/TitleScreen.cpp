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

	stream.open(CONFIG_FOLDER + TITLESCREEN_FOLDER + "TitleScreen.txt");

	stream >> tmp >> img;
	stream >> tmp >> presskey;
	stream >> tmp >> m_presskey.rect.x >> m_presskey.rect.y >> m_presskey.rect.w >> m_presskey.rect.h;
	stream >> tmp >> m_presskey.opacity >> m_presskey.cpf;

	stream.close();

	m_titlescreen = loadTexture(TITLESCREEN_FOLDER + img);
	m_presskey.texture = loadTexture(TITLESCREEN_FOLDER + presskey);

}

void TitleScreen::run()
{
	drawObject(m_titlescreen);
	drawObject(m_presskey);
	m_presskey.opacity += m_presskey.cpf;

	if (m_presskey.opacity >= 255) {

		m_presskey.cpf *= -1;
		m_presskey.opacity = 255;

	}

	if (m_presskey.opacity <= 50) {

		m_presskey.cpf *= -1;
		m_presskey.opacity = 50;

	}

	if (isAnyKeyPressed())
	{
		world.m_stateManager.changeGameState(GAME_STATE::MENU);
		return;
	}
}

void TitleScreen::destroy()
{
	SDL_DestroyTexture(m_titlescreen);
	SDL_DestroyTexture(m_presskey.texture);
}