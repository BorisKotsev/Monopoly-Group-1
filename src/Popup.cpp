#include "Popup.h"
#include "Presenter.h"

Popup::Popup()
{
}

Popup::~Popup()
{
}

void Popup::init(string config)
{
	fstream stream;
	string yesConf, noConf, textConf, tmp, bgrImgName, topConf;
	stream.open(CONFIG_FOLDER + GAME_FOLDER + config);

	stream >> tmp >> bgrImgName;
	stream >> tmp >> m_backround.rect.x >> m_backround.rect.y >> m_backround.rect.w >> m_backround.rect.h;
	stream >> tmp >> textConf;
	stream >> tmp >> topConf;
	stream >> tmp >> yesConf;
	stream >> tmp >> noConf;
	stream.close();
	//cout << yesConf;
	//SDL_Delay(1000000);
	m_backround.texture = loadTexture(GAME_FOLDER + bgrImgName);
	m_text.init(textConf);
	m_topText.init(topConf);
	m_yes.init(yesConf, GAME_FOLDER);
	m_no.init(noConf, GAME_FOLDER);
	m_showing = false;
	

}

void Popup::draw()
{
	if (m_showing) {
		drawObject(m_backround);
		m_text.draw();
		m_topText.draw();
		m_yes.draw();
		m_no.draw();
	}
}

void Popup::update()
{
	if (m_showing) {
		m_yes.update();
		m_no.update();

		
	}
}

void Popup::destroy()
{
	SDL_DestroyTexture(m_backround.texture);
	m_text.destroy();
	m_yes.destroy();
	m_no.destroy();
}

void Popup::show(string name, int price, int type)
{
	if (type == 1) {
		m_topText.setText("Would you like to buy");
		m_text.setText(name + " for " + to_string(price));
	}
	else {
		m_topText.setText("You were taxed");
		m_text.setText("for " + to_string(price) + " by " + name);
	}
	m_showing = true;
}

void Popup::hide()
{
	m_showing = false;
}

