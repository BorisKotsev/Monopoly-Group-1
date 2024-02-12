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

	bool m_canBeBought = true;
private:
	int m_price;
	int m_electricity;
	int m_profit;
	int m_pollution;

	SDL_Rect m_cityRect;

	string m_cityName;
};