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
	stream >> tmp >> m_electricity;
	stream >> tmp >> m_profit;
	stream >> tmp >> m_pollution;

	stream.close();

	m_price = 200;

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
