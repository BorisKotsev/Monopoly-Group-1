#include "TTFButton.h"
#include "Presenter.h"

#include "InputManager.h"


TTFButton::~TTFButton()
{

}

TTFButton::TTFButton()
{
}



void TTFButton::init(SDL_Rect rect, int increasePF, int maxIncrease, string background)
{
	SDL_Rect textRect = { rect.x + rect.w / 10, rect.y + rect.h / 10, (rect.w * 8) / 10, (rect.h * 8) / 10 };
	m_button_drawable.rect = rect;
	originalRect = rect;
	m_increasePerFrameY = increasePF;
	//cout << m_button_drawable.rect.h; 
	//SDL_Delay(9999999);
	m_increasePerFrameX = (m_increasePerFrameY * m_button_drawable.rect.w) / m_button_drawable.rect.h;
	m_maxIncrease = maxIncrease;
	m_button_drawable.texture = loadTexture(GAME_FOLDER + background);
	m_text.init(textRect, 30, 1, "");
}

void TTFButton::update()
{
	//cout << m_button_drawable.rect.w << '\n';
	m_isClicked = false;
	if (isMouseInRect(m_button_drawable.rect)) {
		hover();
		if (InputManager::isMousePressed()) {
			m_isClicked = true;
		}
	}
	else {
		reset();

	}
}

void TTFButton::draw()
{
	drawObject(m_button_drawable);
	m_text.draw();
	//cout << m_button_drawable.rect.h<<'\n';
}

void TTFButton::destroy()
{
	SDL_DestroyTexture(m_button_drawable.texture);
	m_text.destroy();
}

bool TTFButton::isVisible()
{
	return m_visible;
}

void TTFButton::setVisibility(bool visible)
{
	m_visible = visible;
}

void TTFButton::setXY(int2 coor)
{
	originalRect.x = coor.x;
	originalRect.y = coor.y;
	m_button_drawable.rect.x = coor.x;
	m_button_drawable.rect.y = coor.y;

	m_currTextRect.x = coor.x +m_button_drawable.rect.w/10;
	m_currTextRect.y = coor.y +m_button_drawable.rect.h/10;
	m_originalTextRect.x = coor.x +m_button_drawable.rect.w/10;
	m_originalTextRect.y = coor.y +m_button_drawable.rect.h/10;


	m_text.setRect(m_currTextRect);
	cout << m_text.getRect().x << ' ' << m_text.getRect().y << '\n';
	
}

void TTFButton::setText(string text)
{
	//cout << text << '\n';
	m_text.setText(text.c_str());
}

void TTFButton::hover()
{
	if (m_currIncreaseY < m_maxIncrease) {
		m_currIncreaseX += m_increasePerFrameX;
		m_currIncreaseY += m_increasePerFrameY;


		m_button_drawable.rect.w = originalRect.w + m_currIncreaseX;
		m_button_drawable.rect.h = originalRect.h + m_currIncreaseY;
		m_button_drawable.rect.x = originalRect.x - m_currIncreaseX / 2;
		m_button_drawable.rect.y = originalRect.y - m_currIncreaseY / 2;


		m_currTextRect.w = m_originalTextRect.w + m_currIncreaseX;
		m_currTextRect.h = m_originalTextRect.h + m_currIncreaseY;
		m_currTextRect.x = m_originalTextRect.x - m_currIncreaseX / 2;
		m_currTextRect.y = m_originalTextRect.y - m_currIncreaseY / 2;
		m_text.setRect(m_currTextRect);

		//cout << m_button_drawable.rect.x << endl;
	}
}

void TTFButton::reset()
{
	if (m_currIncreaseY >= 0) {
		m_currIncreaseX -= m_increasePerFrameX;
		m_currIncreaseY -= m_increasePerFrameY;
		m_button_drawable.rect.w = originalRect.w + m_currIncreaseX;
		m_button_drawable.rect.h = originalRect.h + m_currIncreaseY;
		m_button_drawable.rect.x = originalRect.x - m_currIncreaseX / 2;
		m_button_drawable.rect.y = originalRect.y - m_currIncreaseY / 2;
		m_currTextRect.w = m_originalTextRect.w + m_currIncreaseX;
		m_currTextRect.h = m_originalTextRect.h + m_currIncreaseY;
		m_currTextRect.x = m_originalTextRect.x - m_currIncreaseX / 2;
		m_currTextRect.y = m_originalTextRect.y - m_currIncreaseY / 2;
		m_text.setRect(m_currTextRect);


		//cout << m_button_drawable.rect.x << endl;
	}
}



