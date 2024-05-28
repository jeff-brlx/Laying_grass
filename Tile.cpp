//
// Created by jeffr on 18/11/2023.
//

#include "Tile.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <windows.h>

using namespace std;

Tile::Tile(std::vector<std::vector<int>> initShape): player(0),coordinates(0,0),shape( initShape) {}

std::vector<std::vector<int>> Tile::getShape() {
    return this->shape;
}
void Tile::setShape(std::vector<std::vector<int>> newShape) {
    shape=newShape;
}

void Tile::displayTile() {
    /*int tileColor=this->getPlayer();*/

    std::vector<std::vector<int>> tileShape = this->getShape();
    for (int i=0 ; i<tileShape.size();i++){
        for(int j=0 ; j<tileShape[i].size();j++){
            if (tileShape[i][j]==0){
                this->getPlayer();

                std::cout<<" ";
            }else if(tileShape[i][j]==1){
                /*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, tileColor);*/
                std::cout<<char(219);
                /*SetConsoleTextAttribute(hConsole, 7); // Réinitialisation de la couleur à la normale*/

            }
        }std::cout<<"\n";
    }
}


void Tile::reverseTile() {
    std::vector<std::vector<int>> tileShape = this->getShape();
    std::reverse(tileShape.begin(),tileShape.end());
    std::vector<std::vector<int>> newShape=tileShape;
    this->setShape(newShape);
}


 void Tile::rotateTile() {
    //Récupération de la shape de la tuile
    std::vector<std::vector<int>> tileShape= this->getShape();

    //Taille de la matrice
    int lines =tileShape.size();
    int columns =tileShape[0].size();

     // initialisation d'une matrice qui va contenir la matrice retournée
     std::vector<std::vector<int>> newShape(columns, std::vector<int>(lines, 0));


    //transposition de la matrice
    for (int i=0;i<lines;i++){
        for(int j=0;j<columns;j++){

            newShape[j][lines -1- i]=tileShape[i][j];
        }
    }
    this->setShape(newShape);
}
int Tile::getPlayer() {
    return player;
}
void Tile::setPlayer(int newPlayer) {
    player=newPlayer;
}

void Tile::setColor(int newColor){
    color=newColor;
}

int Tile::getColor(){
   return color;
}