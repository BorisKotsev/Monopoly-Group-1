#pragma once

#include "Engine.h"

class Station
{
public:
	Station();
	~Station();

	void init(string configFile);

	int getPollution();
	int getElectricity();
	int getPrice();
	int getProfit();

	bool m_canBeBought = true;

private:
	int m_price;
	int m_pollution;
	int m_electricity;
	int m_profit;

	SDL_Rect m_stationRect;

	string m_stationType;
};