#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string playerName;
    int playerNumber;
    int xCoordinate;
    int yCoordinate;
    int playerColor; // Couleur du joueur
    int stone;
    int exchange;
    int steal;

public:
    Player(); // Constructeur par défaut

    void setName(const std::string& name); // Définit le nom du joueur
    std::string getName() const; // Obtient le nom du joueur

    void setNumber(int number); // Définit le numéro du joueur
    int getNumber() const; // Obtient le numéro du joueur

    void setCoordinates(int x, int y); // Définit les coordonnées du joueur
    int getXCoordinate() const; // Obtient la coordonnée X du joueur
    int getYCoordinate() const; // Obtient la coordonnée Y du joueur

    void setColor(int color); // Définit la couleur du joueur
    int getColor() const; // Obtient la couleur du joueur

    int getNumEx();
    void setExchange();
};

#endif // PLAYER_H
