#pragma once

#include "Engine.h"
#include "City.h"
#include "Station.h"

class Player
{
public:
	Player();
	~Player();

	void init(string configFile);
	void update();
	void draw();
	void destroy();

	void pay(int amount);
	void earn(int amount);

	int calculateElectrycityTax();
	int calculateProfitTax();
	int calculateParadiseTax();
	int calculatePollutionTax();
	int getmoney();

	void setTexture(SDL_Texture* texture);

	void addCity(City city);
	void addStation(Station station);

private:
	int m_money;

	Drawable m_player;

	vector <City> m_cities;
	vector <Station> m_stations;
};