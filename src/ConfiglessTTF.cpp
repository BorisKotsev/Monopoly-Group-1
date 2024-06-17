#include "ConfiglessTTF.h"
#include "Presenter.h"

ConfiglessTTF::ConfiglessTTF()
{
}

ConfiglessTTF::~ConfiglessTTF()
{
}

void ConfiglessTTF::init(SDL_Rect rect, int font, int color, string background)
{
	m_text.rect = rect;
	m_fontSize = font;
	m_color = color;
	m_background.texture = loadTexture(FIELD_FOLDER + background);

	m_needToDrawBackground = false;
}

SDL_Rect ConfiglessTTF::getRect()
{
	return m_text.rect;
}

void ConfiglessTTF::setRect(SDL_Rect rect)
{
	m_text.rect = rect;
}
