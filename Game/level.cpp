#include <iostream>
#include <iomanip>
#include <ctime>

#include "input.hpp"
#include "game.hpp"

void showFront(char** Front, int size)
{
    for (int i = 1; i < size - 1; ++i){
        for (int j = 1; j < size - 1; ++j){
            std::cout << " " << Front[i][j];
        }
        gotoxy(70, 15 + i);
    }
}

int main()
{
    system("clear");
    srand(time(NULL));

    int size = 15;
    int** Back = new int* [size];       //Back is a matrix with numbers
    char**Front = new char* [size];     //Front is a matrix that we will see throughout the game

    for (int i = 0; i < size; ++i){
        Back[i] = new int[size];
        Front[i] = new char [size];
    }

    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; j++){
            Back[i][j] = 0;
            Front[i][j] = '#';
        }
    }

    int Bomb_Count = 25;
    int Bomb_temp = Bomb_Count;
    //Choose the random cage and add there mine
    int min = 1, max = size - 2;
    while (Bomb_temp != 0)
    {
        int i = min + rand() % (max - min);
        int j = min + rand() % (max - min);

        if (Back[i][j] == -1)
        {
            continue;
        }

        Back[i][j] = -1;
        Bomb_temp--;
    }

    //Numbers around mines
    for (int i = 1; i < size - 1; ++i){
        for (int j = 1; j < size - 1; ++j){
            //Find the mine
            if (Back[i][j] == -1)
            {
                // +1 in empty cages around mine 
                for (int row_i = i - 1; row_i <= i + 1; ++row_i){
                    for (int col_j = j - 1; col_j <= j + 1; ++col_j){
                        if (Back[row_i][col_j] != -1)
                        {
                            Back[row_i][col_j]++;
                        }
                    }
                }
            }
        }
    }

    //To be make sure that the hider 
    for(int i = 0; i < size; ++i){
        Back[0][i] = -2;
        Back[i][0] = -2;
    }

    gotoxy(70, 15);
    showFront(Front, size);
    gotoxy(71, 15);
    colorCout("#", 3);
    
    //This function is in game.hpp
    game(Back, Front, size, Bomb_Count);
    
    //Deleting dinamic matixes
    for(int i = 0; i < size; ++i){
        delete[] Back[i];
        delete[] Front[i];
    }

    delete[] Back;
    delete[] Front;
}
