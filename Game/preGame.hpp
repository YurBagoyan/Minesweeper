#ifndef PREGAME
#define PREGAME

#include <iostream>
#include <iomanip>
#include <ctime>

#include "input.hpp"
#include "game.hpp"

void showFront(char** Front, int const size)
{
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            std::cout << " " << Front[i][j];
        }
        gotoxy(70, 15 + i);
    }
}

//Choose the random cage and add there mine
void randomMines(int** Back, int const size, int Bomb_Count)
{   
    int min = 1, max = size - 1;
    while (Bomb_Count != 0) {
        int i = min + rand() % (max - min);
        int j = min + rand() % (max - min);

        if (Back[i][j] == -1) {
            continue;
        }

        Back[i][j] = -1;
        Bomb_Count--;
    }

}

void addNumbers(int** Back, int const size)
{
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            //Find the mine
            if (Back[i][j] == -1) {
                // +1 in empty cages around mine 
                for (int row_i = i - 1; row_i <= i + 1; ++row_i) {
                    for (int col_j = j - 1; col_j <= j + 1; ++col_j) {
                        if (Back[row_i][col_j] != -1) {
                        Back[row_i][col_j]++;
                        }   
                    }
                }
            }
        }
    }
}

void boundsOfMatrix(int** Back, char** Front, int const size)
{
    for(int i = 0; i < size; ++i) {
        Back[0][i] = -2;
        //Front[0][i] = '*';
    
        Back[i][0] = -2;
        //Front[i][0] = '*';
    
        Back[i][size - 1] = -2;
        //Front[i][size - 1] = '*';

        Back[size - 1][i] = -2;
       //Front[size - 1][i] = '*';
    }

}

void GodeModeOn(int** Back, int const size)
{
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout << Back[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void mainGame(bool* exitFromGame)
{
    system("clear");
    srand(time(NULL));

    int size = 15;
    int** Back = new int* [size];        //Back is a matrix with numbers
    char** Front = new char* [size];     //Front is a matrix that we will see throughout the game

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
    
    int Bomb_Count = 25;
    randomMines(Back, size, Bomb_Count);
    addNumbers(Back, size);
    boundsOfMatrix(Back, Front, size);

    //GodeModeOn(Back, size);

    //go to the center and prinf matrix
    gotoxy(70, 15);
    showFront(Front, size);
    gotoxy(71, 15);
    colorCout("#", 3);
                
    //The main game
    //This function is in game.hpp
    game(Back, Front, size, Bomb_Count, &(*exitFromGame));
        
    //Deleting dinamic matrixes
    for(int i = 0; i < size; ++i) {
        delete[] Back[i];
        delete[] Front[i];
    }
    delete[] Back;
    delete[] Front;
}

void preGame()
{
    bool exitFromGame = false;
    while(!exitFromGame) {
        mainGame(&exitFromGame);
    }
}


#endif
