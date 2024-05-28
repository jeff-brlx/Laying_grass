//
// Created by jeffr on 19/11/2023.
//

#include "board.h"

#include <iostream>
#include <string>
#include "board.h"
#include <vector>
#include <tuple>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
using namespace std;
//constructeur



Board::Board(int numPlayers):boardSize(10){

    //code abdoulaye
    boardSize = (numPlayers >= 2 && numPlayers <= 4) ? 20 : 30;
    territories.assign(boardSize, std::vector<int>(boardSize, 0)); // Initialisation des zones de territoire avec '.'
    players.reserve(numPlayers); // Réserver la mémoire pour les joueurs


    // Initialisation des joueurs avec des numéros uniques
    for (int i = 1; i <= numPlayers; ++i) {
        Player newPlayer;
        newPlayer.setNumber(i);
        players.push_back(newPlayer);
    }

    divideTerritory(); // Diviser la grille en zones de territoire
    placePlayers(); // Placer les joueurs sur la grille

}





vector<vector<int>> Board::getGrid() {
    return territories;
}


void Board::setGrid(vector<vector<int>> newGrid){
    territories=newGrid;
}

void Board::displayBoard( std::vector<std::vector<int>>gridToDisplay) {
    int tileColor=this->getCurrentPlayer();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int gridSize = this->getBoardSize();

    std::cout << "The current board:  " << std::endl;;
    std::cout << std::setw(3) << "     ";  //4 espaces
    for (int i = 0; i < gridSize; i++) {
        if (i < 10) {
            std::cout << i << "  ";
        } else {
            std::cout <<i<<" ";
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (j == 0 && i < 10) {
                std::cout << std::setw(2) << i << " ";
            }else if ( j==0 && i>=10){
                std::cout << std::setw(2) << i<<" ";
            }
            if (gridToDisplay[i][j] == 0) {
                std::cout << "  .";
            } else if (gridToDisplay[i][j] == 111) {
                SetConsoleTextAttribute(hConsole, tileColor);
                std::cout << "  " << char(219);
                SetConsoleTextAttribute(hConsole, 7); // Réinitialisation de la couleur à la normale (blanc sur fond noir)
            }else if(gridToDisplay[i][j] >= 1 && gridToDisplay[i][j] <= 9){
                int playerIndex = gridToDisplay[i][j] - 1;
                int playerColor = players[playerIndex].getColor();

                SetConsoleTextAttribute(hConsole, playerColor);
                std::cout << "  "<< gridToDisplay[i][j];
                SetConsoleTextAttribute(hConsole, 7);
            }
        }
        std::cout << std::endl;
        SetConsoleTextAttribute(hConsole, 7); // Réinitialisation de la couleur à la normale (blanc sur fond noir)
    }
    /*for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            std::cout<<gridToDisplay[i][j]<<" ";
        }std::cout<<std::endl;
    }*/

}

int Board::getBoardSize() {
    return boardSize;
}
Player& Board::getPlayer(int index) {
    return players[index];
}
void Board::divideTerritory() {
    srand(static_cast<unsigned int>(time(nullptr))); // Initialisation du générateur de nombres aléatoires

    int parts = (boardSize == 20) ? 2 : 3; // Nombre de sections par côté

    int playersCount = players.size();
    if (playersCount <= 4) { // Pour 2 à 4 joueurs
        parts = 2;
    } else if (playersCount <= 6) { // Pour 5 à 6 joueurs
        parts = 3;
    } // Ajoutez des conditions supplémentaires pour gérer davantage de joueurs si nécessaire

    for (int i = 0; i < parts; ++i) {
        for (int j = 0; j < parts; ++j) {
            int startX = i * (boardSize / parts);
            int startY = j * (boardSize / parts);

            int endX = startX + (boardSize / parts);
            int endY = startY + (boardSize / parts);

            int playerNumber = (i * parts) + j;

            // Vérifier si la zone du joueur est libre
            bool occupied = false;
            for (int x = startX; x < endX; ++x) {
                for (int y = startY; y < endY; ++y) {
                    if (territories[x][y] >= 1 && territories[x][y] <= 9) {
                        occupied = true;
                        break;
                    }
                }
                if (occupied) {
                    break;
                }
            }

            // Si la zone du joueur est libre, placer son numéro
            if (!occupied && playerNumber < playersCount) {
                int randomX = startX + rand() % (endX - startX);
                int randomY = startY + rand() % (endY - startY);
                territories[randomX][randomY] = playerNumber + 1; // Pour commencer à partir du joueur 1
                players[playerNumber].setCoordinates(randomX, randomY);
            }
        }
    }
}


void Board::placePlayers() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (territories[i][j] >= 1 && territories[i][j] <= 9) {
                players[territories[i][j] - 1].setCoordinates(i, j);
            }
        }
    }
}
void Board::putPlayers() {
    // Fonction inutile
    for (int i = 0; i < this->players.size(); ++i) {
        int x=this->players[i].getXCoordinate();
        int y=this->players[i].getYCoordinate();
        int number =this->players[i].getNumber();
        int color=this->players[i].getColor();
        this->territories[x][y]=number;
    std::cout<<"oue";

    }

}

std::vector<Player> Board::getPlayersList(){
    return players;
}

void Board::setCurrentPlayer(int newCurrentPlayer){
    currentPlayer=newCurrentPlayer;
}

int Board::getCurrentPlayer(){
        return currentPlayer;
}