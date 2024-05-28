//
// Created by jeffr on 19/11/2023.
//
// CODE JEFFREY
#ifndef PROJET_TEST_BOARD_H
#define PROJET_TEST_BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "player.h"
class Board{
private:
    //grid est remplacé par territorries
    int boardSize;
    std::vector<std::vector<int>> territories; // Zones de territoire pour chaque joueur
    std::vector<Player> players; // Liste des joueurs
    int currentPlayer;

public:
    Board(int numPlayers);
    Player& getPlayer(int index); // Déclaration de la méthode pour récupérer un joueur par son indice
    void displayBoard( std::vector<std::vector<int>> gridToDisplay);
    void setGrid(std::vector<std::vector<int>> newGrid);
    std::vector<std::vector<int>> getGrid();
    int getBoardSize();
    void putPlayers();
    std::vector<Player> getPlayersList();
    void setCurrentPlayer(int newCurrentPlayer);
    int getCurrentPlayer();

private:
    void divideTerritory(); // Méthode pour diviser la grille en zones de territoire pour chaque joueur
    void placePlayers(); // Méthode pour placer les joueurs sur la grille

};

#endif //PROJET_TEST_BOARD_H
