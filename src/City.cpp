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
	stream >> tmp >> m_cityRect.x >> m_cityRect.y;
	stream >> tmp >> m_electricity;
	stream >> tmp >> m_profit;
	stream >> tmp >> m_pollution;

	stream.close();

	m_cityRect.w = 160;
	m_cityRect.h = 80;

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
