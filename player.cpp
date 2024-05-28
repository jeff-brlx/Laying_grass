#include "Player.h"

Player::Player() {
    playerName = " ";
    playerNumber = 0;
    xCoordinate = 0;
    yCoordinate = 0;
    playerColor = 7; // Couleur par défaut (blanc)
    exchange=1; //1 bonus echange attribué
}

void Player::setName(const std::string& name) {
    playerName = name;
}



std::string Player::getName() const {
    return playerName;
}

void Player::setNumber(int number) {
    playerNumber = number;
}

int Player::getNumber() const {
    return playerNumber;
}

void Player::setCoordinates(int x, int y) {
    xCoordinate = x;
    yCoordinate = y;
}

int Player::getXCoordinate() const {
    return xCoordinate;
}

int Player::getYCoordinate() const {
    return yCoordinate;
}

void Player::setColor(int color) {
    playerColor = color;
}

int Player::getColor() const {
    return playerColor;
}
int Player::getNumEx() {
    return exchange;
}

void Player::setExchange() {
    exchange-=1;
}