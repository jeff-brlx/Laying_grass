//
// Created by jeffr on 18/11/2023.
//

#ifndef PROJET_TEST_TILE_H
#define PROJET_TEST_TILE_H
#include  <vector>
#include <tuple>

class Tile {
private:
    int player;
    int color;
    std::tuple<int,int> coordinates;
    std::vector<std::vector<int>> shape;
public:
    Tile(std::vector<std::vector<int>> initShape);
    void setPlayer(int newPlayer);
    int getPlayer();
    int getColor();
    void setColor(int newColor);
    std::tuple<int,int> getCoordinates();
    std::vector<std::vector<int>> getShape();
    void setCoordinates();
    void setShape(std::vector<std::vector<int>> newShape);
    void displayTile();
    void reverseTile();
    void rotateTile();

};


#endif //PROJET_TEST_TILE_H
