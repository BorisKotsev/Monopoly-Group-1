#include "Station.h"

Station::Station()
{
}

Station::~Station()
{
}

void Station::init(string configFile)
{
	string tmp;

	fstream stream;

	stream.open(CONFIG_FOLDER + STATIONS_FOLDER + configFile);

	stream >> tmp >> m_stationType;
	stream >> tmp >> m_stationRect.x >> m_stationRect.y >> m_stationRect.w >> m_stationRect.h;
  


	stream.close();

	m_price = 200;

	m_profit = m_price / 10;
	m_electricity = m_price / 15;
	m_pollution = m_price / 12;

}

int Station::getPollution()
{
	return m_pollution;
}

int Station::getElectricity()
{
	return m_electricity;
}

int Station::getPrice()
{
	return m_price;
}

int Station::getProfit()
{
	return m_profit;
}

string Station::getstationType()
{
	return m_stationType;
}
