#include "Player.h"
#include "Presenter.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::init(string configFile)
{
    fstream stream;
    string tmp, PlayerImgName;
    stream.open(CONFIG_FOLDER + configFile);
    stream >> tmp >> PlayerImgName;
    //stream >> tmp >> m_player.rect.x >> m_player.rect.y >> m_player.rect.w >> m_player.rect.h;
    stream.close();
    m_player.texture = loadTexture(PlayerImgName);
    m_player.rect = { 1000, 1000, 40, 40 };
}

void Player::update()
{

}

void Player::draw()
{
    drawObject(m_player);
}

void Player::destroy()
{
    SDL_DestroyTexture(m_player.texture);
}

void Player::pay(int amount)
{
    m_money -= amount;
}

void Player::earn(int amount)
{
    m_money += amount;
}

int Player::calculateElectrycityTax()
{
    //calculate electricity tax city and station
    int electricity=0;
    for (int i = 0; i < m_stations.size(); i++) {
        electricity += m_stations[i].getPollution();
    }
    for (int i = 0; i < m_cities.size(); i++) {
        electricity += m_cities[i].getPollution();
    }

    return electricity;
}

int Player::calculateProfitTax()
{
    int profit = 0;
    for (int i = 0; i < m_cities.size(); i++) {
        profit += m_cities[i].getProfit();
    }

    for (int i = 0; i < m_stations.size(); i++) {
        profit += m_stations[i].getProfit();
    }

    return profit/10;
}

int Player::calculateParadiseTax()
{
    //rand num between x and y 

    return 50 + rand() % 101;
}

int Player::calculatePollutionTax()
{
    int polution=0;
    for (int i = 0; i < m_stations.size(); i++) {
        polution += m_stations[i].getPollution();
    }
    for (int i = 0; i < m_cities.size(); i++) {
        polution += m_cities[i].getPollution();
    }
    return polution;
}

void Player::setTexture(SDL_Texture* texture)
{
    m_player.texture = texture;
}

void Player::addCity(City city)
{
    m_cities.push_back(city);

}

void Player::addStation(Station station)
{
    m_stations.push_back(station);
}
