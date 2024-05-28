//
// Created by jeffr on 19/11/2023.
//

#ifndef PROJET_TEST_GAMEUI_H
#define PROJET_TEST_GAMEUI_H
#include <iostream>
#include  <vector>
#include "Tile.h"
#include "GameManager.h"
#include<tuple>
class GameUi {
public:
    /*void displayTiles(GameManager &gameManager, int actualTile, std::vector<Tile> tilesList);*/
    void displayCurrentTile(int actualTile,std::vector<Tile> tilesList);
    void displayNextTiles(int actualTile, std::vector<Tile> tilesList);
    char getUserFirstChoice();
    char getUserSecondChoice();
    void displayFlippedTile(int actualTile, std::vector<Tile> tilesList);
    void displayRotatedTile(int actualTile, std::vector<Tile> tilesList);
    std::tuple<int,int> getVerifyCoordinate(GameManager &gameManager,int actualTile, std::vector<Tile> tilesList);
    void actualTileSet(int actualTile ,std::vector<Tile> tilesList, GameManager &gameManager);
    void displayUserAction(GameManager &gameManager, int actualTile, std::vector<Tile> tilesList);
    void exchangeTile(GameManager &gameManager, int actualTile,std::vector<Tile> tileList);
};


#endif //PROJET_TEST_GAMEUI_H
