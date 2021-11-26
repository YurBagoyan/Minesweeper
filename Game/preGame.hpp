#ifndef PREGAME
#define PREGAME

#include <iostream>
#include <ctime>

#include "input.hpp"
#include "game.hpp"
#include "show.hpp"

//Choose the random cage and add there mine
void randomMines(int** Back, int const size, int bombCount)
{   
    srand(time(NULL));
    int const min = 1, max = size - 1;
    while (bombCount != 0) {
        int i = min + rand() % (max - min);
        int j = min + rand() % (max - min);

        if (Back[i][j] == -1) {
            continue;
        }

        Back[i][j] = -1;
        bombCount--;
    }
}

void aroundMine(int** Back, int const size, int const i, int const j) 
{
    for (int row_i = i - 1; row_i <= i + 1; ++row_i) {
        for (int col_j = j - 1; col_j <= j + 1; ++col_j) {
            if (Back[row_i][col_j] != -1) {
                ++Back[row_i][col_j];
            }   
        }
    }
}

void addNumbers(int** Back, int const size)
{
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            //Find the mine
            if (Back[i][j] == -1) {
                // +1 in cages around mine 
                aroundMine(Back, size, i, j); 
            }
        }
    }
}

void boundsOfMatrix(int** Back, char** Front, int const size)
{
    for(int i = 0; i < size; ++i) {
        Back[0][i] = -2;
    
        Back[i][0] = -2;
    
        Back[i][size - 1] = -2;

        Back[size - 1][i] = -2;
    }
}

void level(int const choosedLevel, int* size, int* bombCount, int const customSize, int const customBombCount)
{
    switch(choosedLevel) {
        case 1: *size = 10; *bombCount = 10; break;   //Beginner
        case 2: *size = 12; *bombCount = 20; break;   //Veteran
        case 3: *size = 14; *bombCount = 35; break;   //Expert
        case 4: *size = 17; *bombCount = 50; break;   //Pro
        case 5: *size = 20; *bombCount = 99; break;   //Master
        case 11: *size = customSize + 2; *bombCount = customBombCount; break; //Custom
    }
}

void mainPreGame(int const customSize, int const customBombCount, int const choosedLevel, bool const GodModeOn, bool* exitFromGame, int* winRow, int* winCol)
{ 
    system("clear");

    int size, bombCount;
    level(choosedLevel, &size, &bombCount, customSize, customBombCount);
    int** Back = new int* [size];        //Back is a matrix with numbers
    char** Front = new char* [size];     //Front is a matrix that will see the user

    for (int i = 0; i < size; ++i) {
        Back[i] = new int[size];
        Front[i] = new char [size];
    }        
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; j++) {
            Back[i][j] = 0;
            Front[i][j] = '#';
        }
    }

    randomMines(Back, size, bombCount);
    addNumbers(Back, size);
    boundsOfMatrix(Back, Front, size);
            
    //The main game
    //This function is in game.hpp
    game(Back, Front, size, bombCount, GodModeOn, &(*exitFromGame), &(*winRow), &(*winCol));
        
    //Deleting dinamic matrixes
    for(int i = 0; i < size; ++i) {
        delete[] Back[i];
        delete[] Front[i];
    }
    delete[] Back;
    delete[] Front;
}

void preGame(int const customSize, int const customBombCount, int const choosedLevel, bool const GodModeOn, int* winRow, int* winCol)
{
    bool exitFromGame = false;
    while(!exitFromGame) {
        mainPreGame(customSize, customBombCount, choosedLevel, GodModeOn, &exitFromGame, &(*winRow), &(*winCol));
    }
}


#endif

