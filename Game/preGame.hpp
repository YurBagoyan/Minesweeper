#ifndef PREGAME
#define PREGAME

#include <iostream>
#include <iomanip>
#include <ctime>

#include "input.hpp"
#include "game.hpp"
#include "show.hpp"

//Choose the random cage and add there mine
void randomMines(int** Back, int const size, int bombCount)
{   
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

void addNumbers(int** Back, int const size)
{
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            //Find the mine
            if (Back[i][j] == -1) {
                // +1 in cages around mine 
                for (int row_i = i - 1; row_i <= i + 1; ++row_i) {
                    for (int col_j = j - 1; col_j <= j + 1; ++col_j) {
                        if (Back[row_i][col_j] != -1) {
                            ++Back[row_i][col_j];
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
    
        Back[i][0] = -2;
    
        Back[i][size - 1] = -2;

        Back[size - 1][i] = -2;
    }
}

void GodeModeOn(int** Back, int const size)
{
    for(int i = 1; i < size - 1; ++i) {
        for(int j = 1; j < size - 1; ++j) {
            gotoxy((j*3) - 2, i + 1);

            if(Back[i][j] == -1) {
                std::cout << "\x1b[31;1m" << std::setw(3) << "X" << "\x1b[0m\n";
            }
            else if(Back[i][j] == 0) {
                std::cout << std::setw(3) << "-";
            } else {
                std::cout << std::setw(3) << Back[i][j];
            }    
        }
    }
}

void mainPreGame(bool* exitFromGame, int* winRow, int* winCol)
{
    srand(time(NULL));
    system("clear");

    int const size = 12;
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
    
    int const bombCount = 15;
    randomMines(Back, size, bombCount);
    addNumbers(Back, size);
    boundsOfMatrix(Back, Front, size);

    GodeModeOn(Back, size);
            
    //The main game
    //This function is in game.hpp
    game(Back, Front, size, bombCount, &(*exitFromGame), &(*winRow), &(*winCol));
        
    //Deleting dinamic matrixes
    for(int i = 0; i < size; ++i) {
        delete[] Back[i];
        delete[] Front[i];
    }
    delete[] Back;
    delete[] Front;
}

void preGame(int* winRow, int* winCol)
{
    bool exitFromGame = false;
    while(!exitFromGame) {
        mainPreGame(&exitFromGame, &(*winRow), &(*winCol));
    }
}


#endif
