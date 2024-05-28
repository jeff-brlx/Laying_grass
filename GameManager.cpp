//
// Created by jeffr on 18/11/2023.
//


#include <iostream>
#include "GameManager.h"
#include "board.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <limits>
//il faut donner un int player à game board
GameManager::GameManager():currentRound(1),currentPlayer(1),tileList(initializeTiles()),gameBoard(2) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    actualTile= std::rand()  % tileList.size();
};
void GameManager::setCurrentPlayer() {
    int numPlayer=gameBoard.getPlayersList().size();
    if (currentPlayer >= numPlayer ){
        currentPlayer=1;
    }else{
        currentPlayer+=1;
    }
}

int GameManager::getCurrentPlayer() {
    return currentPlayer;
}
void GameManager::setBoard(Board boardToSet) {
    gameBoard=boardToSet;
}
void GameManager::setCurrentRound() {
    currentRound+=1;
}
int GameManager::getCurrentRound() {
    return currentRound;
}
Board  GameManager::getBoard() {
    return gameBoard;
};
void GameManager::setTileList( std::vector<Tile> newTileList) {
    tileList= newTileList;
}
std::vector<Tile> GameManager::getTileList(){
    return tileList;
}
int GameManager::getActualTile() {
    return actualTile;
}
void GameManager::updateActualTile(int index){
    actualTile+=index;
}
void GameManager::setActualTile( int newActualTile) {
    actualTile=newActualTile;
}
std::vector<Tile> GameManager::initializeTiles() {
    std::vector<Tile> tiles;
    std::vector<std::vector<std::vector<int>>> tilesShapes ={

            {{1,0,0},{1,1,1}},         // bloc 0
            {{0,1,0},{0,1,0},{1,1,1}}, // bloc 1
            {{0,1,0},{1,1,1},{0,1,0}}, // bloc 2
            {{0,0,1},{1,1,1},{1,0,0}}, // bloc 3
            {{0,1,0},{1,1,1}},         // bloc 4
            {{1,1},{1,1}},             // bloc 5
            {{1,0,1},{1,1,1}},         // bloc 6
            {{1,1,1}},                 // bloc 7
            {{0,1},{1,1},{1,0}},       // bloc 8
            {{1,0},{1,1}},             // bloc 9
            {{0,0,1},{0,1,1},{1,1,0}}, // bloc 10
            {{1,1}},                    // bloc 11
            {{0,1},{1,1},{1,0},{1,0},{1,1}},                               // bloc 12
            {{1,1,1},{1,0,0},{1,0,0},{1,0,0}},                             // blOC 13
            {{0,0,0,1,0},{0,0,0,1,0},{0,0,0,1,1},{0,1,1,1,0},{1,1,0,0,0}}, // bloc 14
            {{0,0,1},{0,1,1},{1,1,0},{1,0,0}},                             // bloc 15
            {{0,1,0},{1,1,1},{1,1,0}}, // bloc 16
            {{1,1,1}},// bloc 17
            {{1,0},{1,1},{1,0},{1,0}},// bloc 18
            {{0,1,1},{1,1,0},{1,1,0}},// bloc 19
            {{0,1,0},{1,1,0},{1,1,1}},// bloc 20
            {{0,1,0},{0,1,0},{1,1,1},{1,0,0}},// bloc 21
            {{1,0},{1,1}},// bloc 22
            {{1,1},{1,1},{1,1}},// bloc 23
            {{1,1,1},{0,1,0},{0,1,0},{0,1,0}},// bloc 24
            {{1,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,1,1}},// bloc 25
            {{1,1,1,1}},// bloc 26
            {{1,0,0},{1,1,1},{0,0,1},{0,0,1}},// bloc 27
            {{1,0},{1,1},{1,0},{1,1},{1,0}},// bloc 28
            {{1,0},{1,1},{1,1},{1,0}},// bloc 29
            {{0,1,0},{0,1,0},{0,1,0},{1,1,1},{1,0,1}},// bloc 30
            {{1,1}},// bloc 31
            {{1,0,0,0},{1,1,1,0},{1,0,1,1}},// bloc 32
            {{0,1},{0,1},{1,1},{1,0},{1,0}},// bloc 33
            {{1,1,0,0},{0,1,0,0},{0,1,1,1},{1,1,0,0},{1,0,0,0}},// bloc 34
            {{1,0},{1,0},{1,1},{1,0}},// bloc 35
            {{0,1},{1,1},{1,0}},// bloc 36
            {{1,0,0,1},{1,1,1,1}},// bloc 37
            {{0,0,0,1,1},{1,0,0,0,1},{1,1,1,1,1}},// bloc 38
            {{1,0,0,0},{1,0,0,0},{1,1,0,0},{0,1,1,1}},// bloc 39
            {{1,1,0},{0,1,1},{1,1,0},{0,1,1},{0,1,0}},// bloc 40
            {{1,0},{1,1},{1,1}},// bloc 41
            {{0,1,0,0},{0,1,0,0},{1,1,1,1}},// bloc 42
            {{1,1},{1,1}},// bloc 43
            {{0,1},{1,1},{1,1},{1,0}},// bloc 44
            {{1,1,1},{0,1,0},{1,1,0}},// bloc 45
            {{1,1,1,1}},// bloc 46
            {{0,1,0},{1,1,1}},// bloc 47
            {{1,0,0,0},{1,0,0,0},{1,1,1,1}},
            {{0,1,1,0},{1,1,0,0},{0,1,1,1}},
            {{0,1},{1,1},{1,0},{1,0}},
            {{1,0,0},{1,1,1}},
            {{1,0},{1,1},{1,0},{1,0},{1,0},{1,0}},
            {{0,0,1,1,1},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{1,1,1,0,0}},
            {{0,1},{0,1},{1,1},{1,0},{1,1},{1,0}},
            {{1,1,1,1}},
            {{1,1,0,0},{0,1,0,0},{0,1,1,1},{0,0,0,1}},//bloc 56
            {{0,1,0},{0,1,0},{1,1,1},{0,1,0},{0,1,0}},
            {{0,0,1},{0,0,1},{1,1,1}},
            {{1},{1},{1},{1},{1},{1},{1}},//bloc59
            {{1,0,1},{1,1,1},{0,1,0},{1,1,0}},
            {{0,0,1,0},{1,1,1,0},{0,1,1,1},{0,1,0,0}},
            {{0,1,1},{0,1,0},{0,1,0},{1,1,1}},
            {{1,0},{1,0},{1,1},{1,0},{1,0}},//bloc 63
            {{1,1,0,0},{0,1,0,0},{0,1,0,1},{1,1,1,1}},//bloc 64
            {{0,0,1},{0,1,1},{1,1,0},{1,0,0},{1,1,0}},
            {{0,1,1},{0,1,0},{0,1,0},{0,1,0},{1,1,0},{1,0,0}},
            {{1,0,1,0},{1,1,1,1}},//bloc 67
            {{1,1,0,0},{0,1,0,1},{0,1,0,1},{0,1,1,1}}, //bloc 68
            {{1,0},{1,1},{1,0},{1,0},{1,0}},
            {{1,0,0,0},{1,0,1,0},{1,1,1,1},{0,1,0,0},{0,1,0,0}},
            {{1,1},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0}}//bloc 71

    };

    for (int i=0;i<tilesShapes.size();i++){
        Tile tile(tilesShapes[i]);
        tiles.push_back(tile);
        /*std::cout <<"Tuile"<<i<<":"<<std::endl;
        tile.displayTile();*/
    }
    this->setTileList(tiles);
    return tiles;
}
bool GameManager::placeTile( int currentPlayer,int currentRound,Tile tileToPlace, int x, int y,GameManager gameManager) {
    std::vector<std::vector<int>> shapeExtract = tileToPlace.getShape();

    // Recherche du premier carré occupé dans la forme de la tuile
    int firstSquareX = -1;
    int firstSquareY = -1;

    for (int i = 0; i < shapeExtract.size(); i++) {
        for (int j = 0; j < shapeExtract[i].size(); j++) {
            if (shapeExtract[i][j] == 1) {
                firstSquareX = i;
                firstSquareY = j;
                break;
            }
        }
        if (firstSquareX != -1 && firstSquareY != -1) {
            break;
        }
    }

    // Liste des coordonnées relatives de la tuile par rapport à son premier carré occupé
    std::vector<std::tuple<int, int>> relativeCoordinatesList;

    for (int i = 0; i < shapeExtract.size(); i++) {
        for (int j = 0; j < shapeExtract[i].size(); j++) {
            if (shapeExtract[i][j] == 1) {
                int relativeX = i - firstSquareX +x;
                int relativeY = j - firstSquareY+y ;
                relativeCoordinatesList.push_back(std::make_tuple(relativeX, relativeY));
            }
        }
    }

    // Insertion des coordonnées d'origine dans la liste
    relativeCoordinatesList.insert(relativeCoordinatesList.begin(), std::make_tuple(x, y));
    //vérification de la collision

    // check de la collison et des débordements
    std::vector <std::vector<int>> boardToCheck= gameManager.getBoard().getGrid();
    std::vector<std::tuple<int,int>> tupleListToCheck=relativeCoordinatesList;

    bool collide=checkCollide(boardToCheck , tupleListToCheck);
    if (collide){
        return false;
    };

    //Check si la première tuile est voisine du bloc de départ
    bool starterBlock= checkFirstChoice(currentPlayer,currentRound,boardToCheck,tupleListToCheck);
    if(!starterBlock){
        std::cout<<"Please make sure that the first one is in contact with your starting tile."<<std::endl;
        return false;
    }


   /* //Check la tuile est collée à une autre tuile
    bool gotNeighboor= checkNeighboor(currentPlayer,currentRound,boardToCheck,tupleListToCheck);
    if(!gotNeighboor){
        std::cout<<"Please make sure that the tile touch another tile of your territory."<<std::endl;
        return false;
    }*/



    // Mise à jour de la grille du jeu
    std::vector<std::vector<int>> newGrid = gameBoard.getGrid();

    // on itère dans le vecteur contenant les tuples , on détache les deux membres puis on modifie l'élément du tableau correspondant
    for (int i=0;i<relativeCoordinatesList.size();i++) {

        int k = std::get<0>(relativeCoordinatesList[i]);
        int h = std::get<1>(relativeCoordinatesList[i]);
        newGrid[k][h] = 111;
    }

    // Affichage de la grille mise à jour
    gameBoard.setGrid(newGrid);
    gameBoard.putPlayers();
    std::vector<std::vector<int>> actualGrid = gameBoard.getGrid();
    gameBoard.displayBoard(actualGrid);

    return true;
}

bool GameManager::checkCollide(std::vector<std::vector<int>> boardToCheck , std::vector<std::tuple<int,int>> tupleListToCheck){

    bool collideVerify=false;
    int boardSize=boardToCheck.size();
    for( int i=0;i<tupleListToCheck.size();i++){
        int a= std::get<0>(tupleListToCheck[i]);
        int c=std::get<1>(tupleListToCheck[i]);
        if (boardToCheck[a][c]!=0  ){
            std::cout<<std::endl<<"Please Make sure to not overlay your tiles"<<std::endl;
            collideVerify = true;
            break;
        }if ( a >=boardSize or a<0 or c>=boardSize or c<0){
            std::cout<<std::endl<<"Please do not exceed the boundaries of the table"<<std::endl;
            collideVerify = true;
            break;
        }
    }
return collideVerify;
}

void GameManager::printColorCodes() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < 16; ++i) {
        SetConsoleTextAttribute(hConsole, i);
        std::cout << "Color code : " << i << std::endl;
    }
    SetConsoleTextAttribute(hConsole, 7); // Réinitialisation de la couleur à la normale (blanc sur fond noir)
}


int GameManager::startGame() {
    int numPlayers;

    std::cout << "Welcome to the  Laying Grass game !" << std::endl;
    std::cout << "Enter the number of players  (from 2 to 9) : ";
    std::cin >> numPlayers;

    // Validation du nombre de joueurs
    if (numPlayers < 2 || numPlayers > 9) {
        std::cout << "Invalid player number . Please choose  from 2 to 9" << std::endl;
        return 1;
    }

    std::cout << "The colors code :" << std::endl;
    printColorCodes();

    Board gameBoard(numPlayers);


    std::cout << "Enter a name and choose a color for every player :" << std::endl;
    for (int i = 0; i < numPlayers; ++i) {
        std::string playerName;
        int playerColor;

        std::cout << "Player " << i + 1 << " : ";
        std::cin >> playerName;

        std::cout << "Choose a color (from 2 to 9) for " << playerName << " : ";
        std::cin >> playerColor;

        gameBoard.getPlayer(i).setName(playerName);
        gameBoard.getPlayer(i).setColor(playerColor);
    }

    std::cout << "Players: " << std::endl;
    for (int i = 0; i < numPlayers; ++i) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, gameBoard.getPlayer(i).getColor());
        std::cout << "Player " << i + 1 << " : " << gameBoard.getPlayer(i).getName() << std::endl;
        SetConsoleTextAttribute(hConsole, 7); // Réinitialisation de la couleur à la normale (blanc sur fond noir)
    }
    this->setBoard(gameBoard);
    std::cout << std::endl;
    std::vector<std::vector<int>> actualGrid= gameBoard.getGrid();
    gameBoard.displayBoard(actualGrid); // Affichage de la grille

    return numPlayers;
};

void GameManager::putLastTile(std::vector<Player> playersList){
    std::cout<<"We have reached the end of the game. Each player must now place a 1x1 tile to complete his territory!"<<std::endl;
    int numPlayers= playersList.size();

    for (int i=0;i<numPlayers;i++){
        std::cout<<"Player "<<i+1<<": Place your last 1*1 Tile"<<std::endl;

        std::tuple<int,int>coordinates=this->getLastTileCoordinates();
        std::vector<std::vector<int>> grid=this->gameBoard.getGrid();
        int k = std::get<0>(coordinates);
        int h = std::get<1>(coordinates);
        grid[k][h] = 111;
        this->gameBoard.setGrid(grid);
        this->gameBoard.displayBoard(grid);
    }
    std::cout<<"END OF THE GAME ! The winner is the player with the largest full square of tiles";
}
std::tuple<int,int> GameManager::getLastTileCoordinates() {
        int x;
        int y;
        int gridSize=this->getBoard().getBoardSize();
        do {

        std::cout << "Choose your Last tile Line : ";
        std::cin >> x;

        // Vérifier si l'entrée est un chiffre
        if (std::cin.fail()) {
        std::cout << "Please Enter a number.\n";
        std::cin.clear(); // Réinitialiser le flag d'erreur
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue; // Recommencer la boucle
        }

        std::cout << "Choose your last tile Column : ";
        std::cin >> y;

        // Vérifier si l'entrée est un chiffre
        if (std::cin.fail()) {
        std::cout << "Please Enter a number.\n";
        std::cin.clear(); // Réinitialiser le flag d'erreur
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer le reste de la ligne
        continue; // Recommencer la boucle
        }


        // Vérifier si les coordonnées sont dans les limites de la matrice
        if (x < 0 || x >= gridSize || y < 0 || y >= gridSize) {
        std::cout << "Please Enter a number between in the table range.";
        continue; // Recommencer la boucle
        }
        // Si tout est valide, sortir de la boucle
        break;

        } while (true);
        //renvoie des coordonnées choisies
        return std::make_tuple(x,y);
}

bool GameManager::checkFirstChoice(int currentPlayer,int currentRound ,std::vector<std::vector<int>> boardToCheck , std::vector<std::tuple<int,int>> tupleListToCheck){
            bool starterBlock=false;
            if(currentRound==1 or currentRound==2){

                for( int i=0;i<tupleListToCheck.size();i++){
                    int a= std::get<0>(tupleListToCheck[i]);
                    int c=std::get<1>(tupleListToCheck[i]);
                    if (boardToCheck[a+1][c]== currentPlayer or boardToCheck[a-1][c]== currentPlayer or boardToCheck[a][c+1]== currentPlayer or  boardToCheck[a][c-1]== currentPlayer  ){
                        starterBlock=true;
                        break;
                    }
                }
            }else{
                starterBlock=true;
            }
    return starterBlock;
}

bool GameManager::checkNeighboor(int currentPlayer,int currentRound ,std::vector<std::vector<int>> boardToCheck , std::vector<std::tuple<int,int>> tupleListToCheck){
    bool gotNeighboor=false;
    if(currentRound>2){
    for( int i=0;i<tupleListToCheck.size();i++){
        int a= std::get<0>(tupleListToCheck[i]);
        int c=std::get<1>(tupleListToCheck[i]);
        if (boardToCheck[a+1][c]== 101 or boardToCheck[a+1][c]==currentPlayer or boardToCheck[a-1][c]== 101 or boardToCheck[a+1][c]==currentPlayer or boardToCheck[a][c+1]== 101 or boardToCheck[a+1][c]==currentPlayer or  boardToCheck[a][c-1]== 101 or boardToCheck[a+1][c]==currentPlayer  ){
            gotNeighboor=true;
            break;
        }
    }
    }else{
        gotNeighboor=true;
    }
    return gotNeighboor;
}


