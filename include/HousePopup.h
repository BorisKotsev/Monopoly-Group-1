#pragma once
#include "TTFButton.h"
#include "City.h"
class housePopup {
public:
	void init(string conf);
	void draw();
	void update();
	void destroy();
	void getCities(vector<City>in);
	void loadColors();
private:
	Drawable m_background;
	TextField m_text;
	TTFButton m_buttons[8];
	TTFButton m_secondary[3];
	vector<City> m_cities[9];
	int m_visibleButtonsCounter;
	SDL_Rect m_buttonArray;
	int2 m_buttonWH;
	Button m_exit;
	Button m_back;
	bool m_secondaryMode;
	bool m_visible;
	

};