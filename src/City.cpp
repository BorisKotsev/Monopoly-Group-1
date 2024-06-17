#include "City.h"

City::City()
{

}

City::~City()
{

}

void City::init(string configFile)
{

	string tmp;

	fstream stream;

	stream.open(CONFIG_FOLDER + CITIES_FOLDER + configFile);

	stream >> tmp >> m_cityName;
	stream >> tmp >> m_price;
	stream >> tmp >> m_cityRect.x >> m_cityRect.y >> m_cityRect.w >> m_cityRect.h;
	stream >> tmp >> m_color;


	stream.close();


	m_profit = m_price / 10;
	m_electricity = m_price / 20;
	m_pollution = m_price / 25;

}

int City::getElectricity()
{
	return m_electricity;
}

int City::getProfit()
{
	return m_profit;
}

int City::getPollution()
{
	return m_pollution;
}

int City::getPrice()
{
	return m_price;
}

string City::getcityName()
{
	return m_cityName;
}

int City::getColor()
{
	return m_color;
}
