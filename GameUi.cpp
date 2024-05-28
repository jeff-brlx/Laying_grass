//
// Created by jeffr on 19/11/2023.
//

#include "GameUi.h"
#include <iostream>
#include  <vector>
#include <limits>
using namespace std;


void GameUi::displayCurrentTile(int actualTile,std::vector<Tile> tilesList){
    // Affichage de la tuile actuelle
    cout << "Current tile :" << endl;
    tilesList[actualTile].displayTile();
};
void GameUi::displayNextTiles(int actualTile, std::vector<Tile> tilesList){
    // Affichage des tuiles suivantes
    cout << "Next Tiles :" << endl;
    vector<vector<vector<int>>> nextTiles;

    //retour au début affichage des tuiles
    int actualIndex;
    int listSize = tilesList.size();

    for (int i = actualTile + 1; i <= actualTile + 5; i++) {
        // Ajuster l'index si nécessaire
        if (i >= listSize) {//listsize =72 , à 72 ON repart de 0
            actualIndex = i % listSize;
        } else {
            actualIndex = i;
        }

        // Accéder à la liste et effectuer les opérations nécessaires
        nextTiles.push_back(tilesList[actualIndex].getShape());
        tilesList[actualIndex].displayTile();
        cout << endl;
    }

};
char GameUi::getUserFirstChoice(){
    char choice;
    // Options pour l'utilisateur
    cout << "Take Tile (T)" << endl;
    cout << "Exchange tile (E)" << endl;
    cout << "Display queue (D)" << endl;
    cout << "> ";
    cin >> choice;
    return choice;
};
char GameUi::getUserSecondChoice(){
    char choice;
    cout << "Flip Tile (F)" << endl;
    cout << "Rotate tile (R)" << endl;
    cout << "Place Tile (P)" << endl;
    cout << "> ";
    cin >> choice;
    return choice;
};
void GameUi::displayFlippedTile(int actualTile, std::vector<Tile> tilesList){
    tilesList[actualTile].reverseTile();
    cout << "Tile flipped:" << endl;
    tilesList[actualTile].displayTile();
};
void GameUi::displayRotatedTile(int actualTile, std::vector<Tile> tilesList){
    tilesList[actualTile].rotateTile();
    cout << "Tile rotated:" << endl;
    tilesList[actualTile].displayTile();

};
tuple<int,int> GameUi::getVerifyCoordinate(GameManager &gameManager,int actualTile, std::vector<Tile> tilesList){
    int x;
    int y;
    /*int gridSize=gameManager.getBoard().getBoardSize();*/
    do {

        cout << "Line   (most top-left square of the tile): ";
        cin >> x;

        // Vérifier si l'entrée est un chiffre
        if (cin.fail()) {
            cout << "Please Enter a number.\n";
            cin.clear(); // Réinitialiser le flag d'erreur
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Recommencer la boucle
            /*this->displayTiles(gameManager, actualTile,tilesList);*/
        }

        cout << "Column (most top-left square of the tile): ";
        cin >> y;

        // Vérifier si l'entrée est un chiffre
        if (cin.fail()) {
            cout << "Please Enter a number.\n";
            cin.clear(); // Réinitialiser le flag d'erreur
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer le reste de la ligne
            continue; // Recommencer la boucle
        }

        int gridSize=gameManager.getBoard().getBoardSize();
        // Vérifier si les coordonnées sont dans les limites de la matrice
        if (x < 0 || x >= gridSize || y < 0 || y >= gridSize) {
            cout << std::endl<< "Please Enter a number between in the table range."<< std::endl;
            continue; // Recommencer la boucle
        }
        // Si tout est valide, sortir de la boucle
        break;

    } while (true);
    //renvoie des coordonnées choisies
    return std::make_tuple(x,y);
}
void GameUi::actualTileSet(int actualTile ,std::vector<Tile> tilesList, GameManager &gameManager){
    // passer à la tuile suivante
    if (actualTile==tilesList.size()-1){
        gameManager.setActualTile( 0);
    }else{
        gameManager.setActualTile(actualTile + 1);
    }
}


void GameUi::displayUserAction(GameManager &gameManager, int actualTile, std::vector<Tile> tilesList){
    int currentRound=gameManager.getCurrentRound();
    int currentPlayer=gameManager.getCurrentPlayer();
    //affichage tuile acctuelle
    displayCurrentTile( actualTile, tilesList);
    //affichage prochaines tuiles
    displayNextTiles( actualTile, tilesList);
    // Options pour l'utilisateur
    char choice =getUserFirstChoice();

    // Traitement en fonction du choix
    if (choice == 'T') {
        // Sous-boucle pour permettre à l'utilisateur de tourner, inverser ou placer la tuile
        do {
            // options secondaires pour l'utilisateur
            choice=getUserSecondChoice();
            // Traitement en fonction du choix dans la sous-boucle
            if (choice == 'F') {
                //renversement de la tuile
                tilesList[actualTile].reverseTile();
                cout << "Tile flipped:" << endl;
                tilesList[actualTile].displayTile();
            } else if (choice == 'R') {
                // Rotation de la tuile
                tilesList[actualTile].rotateTile();
                cout << "Tile rotated:" << endl;
                tilesList[actualTile].displayTile();
            } else if (choice == 'P') {

                //Choix & vérification de coordonnées
                tuple<int,int> coordinates=getVerifyCoordinate( gameManager,actualTile,tilesList);

                //récupération des coordonnées valides
                int x=get<0>(coordinates);
                int y=get<1>(coordinates);



                // Effectuer le placement de la tuile
                if (!(gameManager.placeTile(currentPlayer,currentRound,tilesList[actualTile], x, y,gameManager))){
                    continue;
                }
                else{

                //Attribution d'un joueur et d'une couleur à la tuile
                int currentPlayer=gameManager.getCurrentPlayer();
                tilesList[actualTile].setPlayer(currentPlayer);


                std::vector<Player>playersList=gameManager.getBoard().getPlayersList();
                int color=playersList[currentPlayer-1].getColor();
                tilesList[actualTile].setColor(color);

                gameManager.getBoard().setCurrentPlayer(currentPlayer);
                // passer à la tuile suivante
                actualTileSet(actualTile ,tilesList, gameManager);

                gameManager.setCurrentRound();
                gameManager.setCurrentPlayer();

             }
            }

        } while (choice != 'P'); // La sous-boucle continue tant que l'utilisateur ne choisit pas de placer la tuile
    } else if (choice == 'E') {
        // Logique pour l'échange de tuile
        exchangeTile(gameManager,actualTile,tilesList);

    } else if (choice == 'D') {
        //affichage prochaines tuiles
        this->displayUserAction(gameManager, actualTile,  tilesList);
    }
}

void GameUi::exchangeTile(GameManager &gameManager,int  actualTile, std::vector<Tile> tileList) {
    int actualPlayer=gameManager.getCurrentPlayer();
    vector<Player>playersList=gameManager.getBoard().getPlayersList();
    Player player=playersList[actualPlayer-1];
    int numBonusExchange= player.getNumEx();
    if(numBonusExchange>0){
        int choice ;
        std::cout<<"Enter the index of the tile you want to take ( 1 to 5 ) :";
        std::cin>>choice;
        std::cout<<std::endl;
        actualTile+=choice;
        gameManager.updateActualTile(choice);
        player.setExchange();
        displayUserAction(gameManager, actualTile,  tileList);


    }else{
        std::cout<<"Sorry,you don't have enaugh exchange Bonus";
        displayUserAction(gameManager, actualTile,  tileList);

    }
}