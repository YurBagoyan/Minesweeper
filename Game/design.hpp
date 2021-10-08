#ifndef DESIGN
#define DESIGN

#include <iostream>
#include "input.hpp"

int matrix_start_col = 69, matrix_start_row = 14;

void printSymbol(char** Front, int i, int j)
{
    switch(Front[i][j])
    {
        case 'X':
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "  ";
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            colorCout("X ", 5);
            break;

        case 'F':
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "  ";
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            colorCout("F ", 7);
            break;

        case '_': 
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "  ";
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "_ ";
            break;

        case '#': 
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout <<"  ";
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "# ";
            break;

        case '1':
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "  ";
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            colorCout("1 ", 4); 
            break;

        case '2':  
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "  ";
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            colorCout("2 ", 3); 
            break;

        case '3': 
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "  ";
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            colorCout("3 ", 5); 
            break;

        case '4': 
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "  ";
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            colorCout("4 ", 2); 
            break;

        case '5':  
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "  ";
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            colorCout("5 ", 6); 
            break;

        case '6': 
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "  ";
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            colorCout("6 ", 1); 
            break;

        case '7':  
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "  ";
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            colorCout("7 ", 7); 
            break;

        case '8': 
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            std::cout << "  ";
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);
            colorCout("8 ", 8); 
            break;        
    }
}


void print(char** Front, int size)
{
    system("clear");
    gotoxy(matrix_start_col, matrix_start_row);

    for(int i = 1; i < size - 1; ++i)
    {
        for(int j = 1; j < size -1; ++j)
        {
            printSymbol(Front, i, j);
        }
        gotoxy(matrix_start_col, matrix_start_row + i);
    }
}


void Open(int **Back, char** Front, int i, int j)
{
    switch(Back[i][j])
    {
        case 1:
            Front[i][j] = '1';
            printSymbol(Front, i, j);
            break;

        case 2: 
            Front[i][j] = '2';
            printSymbol(Front, i, j);
            break;

        case 3: 
            Front[i][j] = '3';
            printSymbol(Front, i, j);
            break;

        case 4: 
            Front[i][j] = '4';
            printSymbol(Front, i, j);
            break;

        case 5: 
            Front[i][j] = '5';
            printSymbol(Front, i, j);
            break;

        case 6: 
            Front[i][j] = '6';
            printSymbol(Front, i, j);
            break;  

        case 7: 
            Front[i][j] = '7';
            printSymbol(Front, i, j);
            break;

        case 8: 
            Front[i][j] = '8';
            printSymbol(Front, i, j);
            break;
    }   
}

void Boom(int **Back, char** Front, int size)
{   
    for(int i = 1; i < size - 1; ++i)
    {
        for(int j = 1; j < size - 1; ++j)
        {
            if(Back[i][j] == -1)
            {
                gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                std::cout << " ";

                gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                colorCout("X ", 5);
            }
        }
    }

    gotoxy(matrix_start_col - 15, matrix_start_row + size + 2);
    colorCout("Press 'R' to ", 7);
    gotoxy(matrix_start_col - 2, matrix_start_row + size + 2);
    colorCout("RESTART", 5); 
    gotoxy(matrix_start_col - 15, matrix_start_row + size + 3); 
    colorCout("Press Esc to return to ", 7); 
    gotoxy(matrix_start_col - 2, matrix_start_row + size + 3);
    colorCout("MAIN MENU", 5);
    
    gotoxy(matrix_start_col - 5, matrix_start_row - 3);
    colorCout("BoooooooM ! GAME OVER", 5);

    for(char key; ; )
    {
        cbreak();
        key = keypress();
        normal();

        if(key == 'r' || key == 'R')
        {
            //system("clear");
            
            break;
        }
        else if(key == 27)
        {
            //menu
        }
    }
}

void step(int** Back, char** Front, int size)
{
    //print new matrix for new game   form game.cpp
    int i = 1, j = 1;
    for(char key = -1; key != 27; )
    {
        cbreak();
        key = keypress();
        normal();
    
        switch (key)
        {
            case 'w': case 'W':
                for(int k = 16; k < size + 2; ++k)
                {
                     gotoxy(0, k);
                     std::cout << "  ";
                }

                if(i == 1)
                {     
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);    
                    std::cout << "#";
                    i = size - 2;
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                    colorCout("#", 3);
                }
                else
                {
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                    std::cout << "#";
                    
                    gotoxy(matrix_start_col + j*2, matrix_start_row + (--i));
                    colorCout("#", 3);
                }    
                break;

            case 's': case 'S': 
                for(int k = 16; k < size + 2; ++k)
                    {
                        gotoxy(0, k);
                        std::cout << "  ";
                    }

                if(Front[i+1][j] != 35)
                {
                    break;
                }

                if(i == size-2)
                { 
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);    //(j*2)-1
                    std::cout << "#";
                    i = 1;
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                    colorCout("#", 3);
                }
                else
                {                    
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                    std::cout << "#";
                    
                    gotoxy(matrix_start_col + j*2, matrix_start_row + (++i));
                    colorCout("#", 3);
                }
                break;

            case 'a': case 'A': 
                for(int k = 16; k < size + 2; ++k)
                    {
                        gotoxy(0, k);
                        std::cout << "  ";
                    }

                if(Front[i][j-2] != 35)
                {
                    break;
                }
                if(j == 1)
                {   
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);    //(j*2)-1
                    std::cout << "#";
                    j = size-2;
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                    colorCout("#", 3);
                }
                else
                {                    
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                    std::cout << "#";
                    
                    gotoxy(matrix_start_col + (--j)*2, matrix_start_row + i);
                    colorCout("#", 3);    
                }
                break;

            case 'd': case 'D':  
                for(int k = 16; k < size + 2; ++k)
                    {
                        gotoxy(0, k);
                        std::cout << "  ";
                    }

                if(j == size-2)
                {
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);   
                    std::cout << "#";
                    j = 1;

                    if(Front[i][j+2] != 35)
                    {
                        break;
                    }

                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                    colorCout("#", 3); 
                }
                else
                {
                    //                 
                }
                break;

            case 'f': case 'F':
                Front[i][j] = 'F';
                printSymbol(Front, i, j);
                break;

            case 0x0A:
                switch(Back[i][j])
                {
                    case -1: Boom(Back, Front, size); break;
                    case  0: Front[i][j] = '_'; printSymbol(Front, i, j); break;
                    default: Open(Back, Front, i, j); break;            
                }
                break;

            case 'r': case 'R':
                //Restart
                break;

            case 27:
                //Exit to menu
                break;
        }
    }
}





#endif
