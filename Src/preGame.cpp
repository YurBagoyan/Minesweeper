#include <ctime>
#include <iostream>

#include "../Include/game.hpp"
#include "../Include/input.hpp"
#include "../Include/preGame.hpp"
#include "../Include/show.hpp"

void preGame(const int customSize, const int customBombCount, const int choosedLevel, const bool GodModeOn, int& winRow, int& winCol)
{
    bool exitFromGame = false;
    while (!exitFromGame) {
        gamePreparation(customSize, customBombCount, choosedLevel, GodModeOn, exitFromGame, winRow, winCol);
    }
}

void gamePreparation(const int customSize, const int customBombCount, const int choosedLevel, const bool GodModeOn, bool& exitFromGame, int& winRow, int& winCol)
{
    system("clear");

    size_t size, bombCount;

    // Selection size of the matrix and bomb count depending on the choice of level from user
    level(choosedLevel, size, bombCount, customSize, customBombCount);

    int** Back = new int* [size];       //Back is a matrix with numbers
    char** Front = new char* [size];    //Front is a matrix that will see the user

    for (size_t i = 0; i < size; ++i) {
        Back[i] = new int[size];
        Front[i] = new char[size];
    }

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; j++) {
            Back[i][j] = 0;
            Front[i][j] = '#';
        }
    }
    
    fillRandomMines(Back, size, bombCount);
    fillNumbersAroundMines(Back, size);
    fillBoundsOfMatrix(Back, size);

    //The main game
    //This function is in game.cpp
    game(Back, Front, size, choosedLevel, bombCount, GodModeOn, exitFromGame, winRow, winCol);

    //Deleting dinamic matrixes
    for (size_t i = 0; i < size; ++i) {
        delete[] Back[i];
        delete[] Front[i];
    }
    delete[] Back;
    delete[] Front;
}

void level(const int choosedLevel, size_t& size, size_t& bombCount, const int customSize, const int customBombCount)
{
    switch (choosedLevel) {
    case 1: size = 10; bombCount = 10; break;   //Beginner
    case 2: size = 12; bombCount = 20; break;   //Veteran
    case 3: size = 14; bombCount = 35; break;   //Expert
    case 4: size = 17; bombCount = 50; break;   //Pro
    case 5: size = 20; bombCount = 99; break;   //Master
    case 11: size = customSize + 2; bombCount = customBombCount; break; //Custom
    }
}

//Choose the random cage and add there mine
void fillRandomMines(int** Back, const size_t size, size_t bombCount)
{  
    srand(time(NULL));
    const int min = 1, max = size - 1;
    while (bombCount != 0) {
        int i = min + rand() % (max - min);
        int j = min + rand() % (max - min);

        if (Back[i][j] == -1) {
            continue;
        }

        Back[i][j] = -1;
        --bombCount;
    }
}

void addOneInCellsAround(int** Back, const int i, const int j)
{
    for (int row = i - 1; row <= i + 1; ++row) {
        for (int col = j - 1; col <= j + 1; ++col) {
            if (Back[row][col] != -1) {
                ++Back[row][col];
            }   
        }
    }
}

void fillNumbersAroundMines(int** Back, const size_t size)
{
    for (size_t i = 1; i < size - 1; ++i) {
        for (size_t j = 1; j < size - 1; ++j) {
            //Find the mine
            if (Back[i][j] == -1) {
                // +1 to the cells around the mine
                addOneInCellsAround(Back, i, j);
            }
        }
    }
}

void fillBoundsOfMatrix(int** Back, const size_t size)
{
    for(size_t i = 0; i < size; ++i) {
        Back[0][i] = -2;
        Back[i][0] = -2;
        Back[i][size - 1] = -2;
        Back[size - 1][i] = -2;
    }
}
