#include "HousePopup.h"
#include "Presenter.h"
void housePopup::init(string conf)
{
	fstream stream;
	string exitButtonConf, backButtonConf, backgroundImg, btnBackgroundImg;
	SDL_Rect btnRect;
	int buttonIcreasePerFrame;
	int buttonMaxIncrease;
	//TTFButton TmpButton;
	string tmp;
	stream.open(conf);
	stream >> tmp >> backgroundImg;
	stream >> tmp >> m_background.rect.x >> m_background.rect.y >> m_background.rect.w >> m_background.rect.h;
	stream >> tmp >> m_buttonArray.x >> m_buttonArray.y >> m_buttonArray.w >> m_buttonArray.h;
	stream >> tmp >> m_buttonWH.x >> m_buttonWH.y;
	stream >> tmp >> buttonIcreasePerFrame >> buttonMaxIncrease;
	stream >> tmp >> btnBackgroundImg;
	stream >> tmp >> exitButtonConf;
	stream >> tmp >> backButtonConf;

	stream.close();
	m_background.texture = loadTexture(GAME_FOLDER + backgroundImg);

	btnRect = { 0, 0, m_buttonWH.x, m_buttonWH.y};
	//cout << btnRect.w<<' '<<btnRect.h<<'\n';
	for (int i = 0; i < 8; i++) {

		m_buttons[i].init(btnRect,buttonIcreasePerFrame, buttonMaxIncrease, btnBackgroundImg);
		m_buttons[i].setVisibility(false);
		m_buttons[i].setText(to_string(i));
	}
	for (int i=0; i < 3; i++) {
		m_secondary[i].init(btnRect, buttonIcreasePerFrame, buttonMaxIncrease, btnBackgroundImg);
		m_secondary[i].setVisibility(true);

	}
	m_exit.init(exitButtonConf, GAME_FOLDER);

	m_back.init(backButtonConf, GAME_FOLDER);
	m_visible = true;
}

void housePopup::draw()
{
	if(m_visible){
		drawObject(m_background);
		
		if (m_secondaryMode) {
			for (int i = 0; i < 3; i++) {
				m_secondary[i].draw();
			}
			m_back.draw();
			
		}
		else {
			for (int i = 0; i < 8; i++) {
				if (m_buttons[i].isVisible()) {
					//cout << "hello again\n";
					m_buttons[i].draw();
				}
			}
		}
		m_exit.draw();
	}
}

void housePopup::update()
{

	if(m_visible){
		if (m_secondaryMode) {
			for (int i = 0; i < 3; i++) {
				m_secondary[i].update();
				if (m_secondary[i].isClicked()) {

					m_secondaryMode = false;
				}
			}
			m_back.update();
			if (m_back.isClicked()) {
				m_secondaryMode = false;
			}
		}
		else {
			for (int i = 0; i < 8; i++) {
				if (m_buttons[i].isVisible()) {
					m_buttons[i].update();
				}
				if (m_buttons[i].isClicked()) {
					m_secondaryMode = true;
					for (int j = 0; j < 3; j++) {

						m_secondary[j].setText(m_cities[i + 1][j].getcityName().c_str());
						//cout << m_cities[i + 1][j].getcityName() << '\n';
					}
				}
			}
		}
		m_exit.update();
		if (m_exit.isClicked()) {
			m_visible = false;
		}
	}
}

void housePopup::destroy()
{
	
}

void housePopup::getCities(vector<City> in)
{
	m_visible = true;
	m_visibleButtonsCounter = 0;
	for (int i = 1; i < 9; i++) {
		m_cities[i].clear();
		m_buttons[i - 1].setVisibility(false);
	}
	for (int i = 0; i < in.size(); i++) {
		/*cout << in[i].getColor() << ' ' << in[i].getcityName() << "\n";
		SDL_Delay(50000);*/
		m_cities[in[i].getColor()].push_back(in[i]);

	}
	for (int i = 1; i < 9; i++) {
		if (m_cities[i].size()==3) {
			m_visibleButtonsCounter++;
		}
	}
	int flag = 1;
	int2 coor;
	if (m_visibleButtonsCounter <= 4) {
		int spacing = (m_buttonArray.w - m_buttonWH.x * m_visibleButtonsCounter) / (m_visibleButtonsCounter + 1);
		for (int i = 1; i < 9; i++) {
			if (m_cities[i].size() == 3) {
				coor.x = m_buttonArray.x + spacing * flag + m_buttonWH.x * (flag - 1);
				coor.y = m_buttonArray.y;
				m_buttons[i - 1].setXY(coor);
				m_buttons[i - 1].setVisibility(true);
				//cout << coor.x<<' '<<coor.y<<'\n';
				flag++;
			}
		}
	}
	else {
		int topSpacing = (m_buttonArray.w - m_buttonWH.x * 4) / 3;
		int bottomSpacing = (m_buttonArray.w - m_buttonWH.x * (m_visibleButtonsCounter - 4)) / (m_visibleButtonsCounter + 3);
		for (int i = 1; i < 9; i++) {
			if (m_cities[i].size() == 3) {
				if (flag < 5) {
					coor.x = m_buttonArray.x + topSpacing * flag + m_buttonWH.x * (flag - 1);
					coor.y = m_buttonArray.y;
				}
				else {
					coor.x = m_buttonArray.x + topSpacing * (flag - 4) + m_buttonWH.x * (flag - 5);
					coor.y = m_buttonArray.y + m_buttonArray.w - m_buttonWH.y;
				}
				m_buttons[i - 1].setXY(coor);
				m_buttons[i - 1].setVisibility(true);
				//cout << coor.x<<' '<<coor.y<<'\n';
				flag++;
			}
		}
	}
}

void housePopup::loadColors()
{

}

