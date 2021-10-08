#include <iostream>
#include <iomanip>
#include <ctime>

#include "input.hpp"
#include "design.hpp"

void showBack(int** Back, int size)
{
    for (int i = 1; i < size - 1; ++i)
    {
        for (int j = 1; j < size - 1; ++j)
        {
            std::cout << std::setw(2) << "\t" << Back[i][j];
        }
        std::cout << std::endl;
    }
}

void showFront(char** Front, int size)
{
    for (int i = 1; i < size - 1; ++i)
    {
        for (int j = 1; j < size - 1; ++j)
        {
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
    int** Back = new int* [size];
    char**Front = new char* [size];
    for (int i = 0; i < size; ++i)
    {
        Back[i] = new int[size];
        Front[i] = new char [size];
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; j++)
        {
            Back[i][j] = 0;
            Front[i][j] = '#';
        }
    }


    int Bomb_Count = 15;

    //Random -> Bomb
    int min = 1, max = size - 2;
    while (Bomb_Count != 0)
    {
        int i = min + rand() % (max - min);
        int j = min + rand() % (max - min);

        if (Back[i][j] == -1)
        {
            continue;
        }

        Back[i][j] = -1;
        Bomb_Count--;
    }

    //Numbers around bombs
    for (int i = 1; i < size - 1; ++i)
    {
        for (int j = 1; j < size - 1; ++j)
        {
            if (Back[i][j] == -1)
            {
                for (int row_i = i - 1; row_i <= i + 1; ++row_i)
                {
                    for (int col_j = j - 1; col_j <= j + 1; ++col_j)
                    {
                        if (Back[row_i][col_j] != -1)
                        {
                            Back[row_i][col_j]++;
                        }
                    }
                }

            }
        }
    }

    //showBack(Back_Matrix, size);
    //std::cout << "\n\n";

    gotoxy(70, 15);
    showFront(Front, size);
    gotoxy(71, 15);
    colorCout("#", 3);
    

    step(Back, Front, size);

    for(int i = 0; i < size; ++i)
    {
        delete[] Back[i];
        delete[] Front[i];
    }
    delete[] Back;
    delete[] Front;
}
