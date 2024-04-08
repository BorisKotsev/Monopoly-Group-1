#include "Button.h"
#include "Presenter.h"

#include "InputManager.h"
bool Button::isClicked()
{
	return m_isClicked;
}

void Button::init(string config_file, string folder)
{
	m_isClicked = false;
	m_currIncreaseX = 0;
	m_currIncreaseY = 0;
	fstream stream;
	string tmp, texture;
	stream.open(CONFIG_FOLDER + folder + config_file);
	stream >> tmp >> texture;
	stream >> tmp >> m_button_drawable.rect.x >> m_button_drawable.rect.y >> m_button_drawable.rect.w >> m_button_drawable.rect.h;
	stream >> tmp >> m_maxIncrease;
	stream >> tmp >> m_increasePerFrameY;
	stream.close();
	m_button_drawable.texture = loadTexture(folder + texture);
	originalRect = m_button_drawable.rect;
	m_increasePerFrameX = (m_increasePerFrameY * m_button_drawable.rect.w) / m_button_drawable.rect.h;
	//cout << m_button_drawable.rect.x << endl;
	
}

void Button::update()
{

	m_isClicked = false;
	if (isMouseInRect( m_button_drawable.rect)) {
		hover();
		if (InputManager::isMousePressed()) {
			m_isClicked = true;
		}
	}
	else {
		reset();

	}
	
}

void Button::draw()
{
	drawObject(m_button_drawable);
}

void Button::destroy()
{
	SDL_DestroyTexture(m_button_drawable.texture);
}

void Button::hover()
{
	if (m_currIncreaseY < m_maxIncrease) {
		m_currIncreaseX += m_increasePerFrameX;
		m_currIncreaseY += m_increasePerFrameY;
		m_button_drawable.rect.w = originalRect.w + m_currIncreaseX;
		m_button_drawable.rect.h = originalRect.h + m_currIncreaseY;
		m_button_drawable.rect.x = originalRect.x - m_currIncreaseX/2;
		m_button_drawable.rect.y = originalRect.y - m_currIncreaseY/2;

		//cout << m_button_drawable.rect.x << endl;
	}


}

void Button::reset()
{
	if (m_currIncreaseY > 0) {
		m_currIncreaseX -= m_increasePerFrameX;
		m_currIncreaseY -= m_increasePerFrameY;
		m_button_drawable.rect.w = originalRect.w + m_currIncreaseX;
		m_button_drawable.rect.h = originalRect.h + m_currIncreaseY;
		m_button_drawable.rect.x = originalRect.x - m_currIncreaseX / 2;
		m_button_drawable.rect.y = originalRect.y - m_currIncreaseY / 2;

		//cout << m_button_drawable.rect.x << endl;
	}

}
