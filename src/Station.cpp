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
	stream >> tmp >> m_price;
	stream >> tmp >> m_stationRect.x >> m_stationRect.y;
	stream >> tmp >> m_electricity;
	stream >> tmp >> m_profit;
	stream >> tmp >> m_pollution;

	stream.close();

	m_stationRect.w = 160;
	m_stationRect.h = 80;

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
