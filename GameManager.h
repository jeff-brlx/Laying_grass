//
// Created by jeffr on 18/11/2023.
//

#ifndef PROJET_TEST_GAMEMANAGER_H
#define PROJET_TEST_GAMEMANAGER_H
#include <vector>
#include  "Tile.h"
#include "board.h"

class GameManager {
private:
    Board gameBoard;
    int actualTile;
    int currentRound;
    std::vector<Tile> tileList;
    int currentPlayer;

public:
    GameManager();
    int getCurrentPlayer();
    std::vector <Tile> initializeTiles();
    std::vector<Tile> getTileList();
    void setTileList(std::vector<Tile> newTileList);
    bool placeTile(int currentPlayer,int currentRound,Tile tileToPlace,int x, int y,GameManager gameManager);
    int getActualTile();
    void setActualTile(int newActualTile);
    Board getBoard();
    void setBoard(Board boardToSet);
    int getCurrentRound();
    void setCurrentRound();
    bool checkCollide(std::vector<std::vector<int>> boardToCheck , std::vector<std::tuple<int,int>> tupleListToCheck);
    void printColorCodes();
    int startGame();
    void putLastTile(std::vector<Player> playersList);
    std::tuple<int,int>getLastTileCoordinates();
    bool checkFirstChoice(int currentPlayer,int currentRound,std::vector<std::vector<int>> boardToCheck , std::vector<std::tuple<int,int>> tupleListToCheck);
    void setCurrentPlayer();
    void updateActualTile(int index);
    bool checkNeighboor(int currentPlayer,int currentRound ,std::vector<std::vector<int>> boardToCheck , std::vector<std::tuple<int,int>> tupleListToCheck);
};

#endif //PROJET_TEST_GAMEMANAGER_H

