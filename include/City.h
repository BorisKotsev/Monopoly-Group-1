#pragma once

#include "Engine.h"

class City
{
public:
	City();
	~City();

	void init(string configFile);

	int getElectricity();
	int getProfit();
	int getPollution();
	int getPrice();
	string getcityName();
	int getColor();
	bool m_canBeBought = true;
private:
	int m_price;
	int m_electricity;
	int m_profit;
	int m_pollution;
	int m_color; //1 - GREEN; 2 - DARK BLUE; 3 - LIGHT BLUE; 4 - PURPLE; 5 - ORANGE; 6 - RED; 7 - LIGHT GREEN; 8 - PINK;

	SDL_Rect m_cityRect;

	string m_cityName;
};