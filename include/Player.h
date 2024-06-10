#pragma once

#include "Engine.h"
#include "City.h"
#include "Station.h"
#include "InputManager.h"
#include <cstdlib>
#include <algorithm>


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
	int tile = 0;
	int sTile = 0;
	int city = 0;
	int station = 0;

	

	void movement(int multiplier);


	int calculateElectrycityTax();
	int calculateProfitTax();
	int calculateParadiseTax();
	int calculatePollutionTax();

	void setTexture(SDL_Texture* texture);

	void addCity(City city);
	void addStation(Station station);

private:
	InputManager inpMan;
	int m_money;

	Drawable m_player;

	vector <City> m_cities;
	vector <Station> m_stations;
};