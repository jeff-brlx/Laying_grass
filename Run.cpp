//
// Created by jeffr on 23/11/2023.
//
#include "Run.h"
#include <vector>
#include <limits>
#include <windows.h>

using namespace std;

void Run::run(){
    //Configuration de la partie
    GameManager gameManager;
    GameUi gameUi;
    vector<Tile> tileListInit= gameManager.initializeTiles();
    std::vector<Player> playersList=gameManager.getBoard().getPlayersList();
    gameManager.startGame();
    int roundNumber=playersList.size()*3;

    // Tant que le dernier round n'est pas atteint la partie continue
    while(gameManager.getCurrentRound()<=roundNumber) { // "=" parce que le dernier round est joué
        //récupération des infos du joueur
        int actualPlayer=gameManager.getCurrentPlayer();

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, gameManager.getBoard().getPlayer(actualPlayer-1).getColor());
        std::cout << "Player turn : " << gameManager.getBoard().getPlayer(actualPlayer-1).getName() << std::endl;
        SetConsoleTextAttribute(hConsole, 7); // Réinitialisation de la couleur à la normale (blanc sur

        //chaque joueur joue à tour de role
        gameUi.displayUserAction(gameManager, gameManager.getActualTile(), tileListInit);
        // le round et le joeur acctuel sont acctualisés ensuite

    }
    // une fois le dernier round atteint les joueurs place une dernière tuile 1*1
    gameManager.putLastTile(playersList);

}