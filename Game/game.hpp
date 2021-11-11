#ifndef GAME
#define GAME

#include <iostream>

#include "input.hpp"
#include "show.hpp"

//To print a character in green color, for cursor move
/* Inputs: Front: [char], i, j: integer
 * Pre: i < size, j < size
 * Output: Front : [char]
 * Post: Front[i][j] with green color
 */
void greenSymbol(char** Front, int const i, int const j)
{
    switch(Front[i][j]) {
        case 'F': colorCout("F", 3); break; 
        case '#': colorCout("#", 3); break;
        case '_': colorCout("_", 3); break;
        case '1': colorCout("1", 3); break;
        case '2': colorCout("2", 3); break;
        case '3': colorCout("3", 3); break;
        case '4': colorCout("4", 3); break;
        case '5': colorCout("5", 3); break;
        case '6': colorCout("6", 3); break;
        case '7': colorCout("7", 3); break;
        case '8': colorCout("8", 3); break;
    }
}

//To print a character in its specific color
/* Inputs: Front: [char]; i, j: integer
 * Pre: i < size; j < size
 * Output: Front : [char]
 * Post: Front[i][j] with its specific color
 */
void printSymbol(char** Front, int const i, int const j, int const matrixStartRow, int const matrixStartCol)  
{
    switch(Front[i][j]) {
        case 'X':
            //Delete previous character
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);   
            std::cout << "  ";
            //Print new character in its specific color
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            colorCout("X ", 5);
            break;

        case 'F':
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout << "  ";
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            colorCout("F ", 7);
            break;

        case '_': 
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout << "  ";
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout << "_ ";
            break;

        case '#': 
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout <<"  ";
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout << "# ";
            break;

        case '1':
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout << "  ";
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            colorCout("1 ", 4); 
            break;

        case '2':  
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout << "  ";
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            colorCout("2 ", 10); 
            break;

        case '3': 
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout << "  ";
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            colorCout("3 ", 5); 
            break;

        case '4': 
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout << "  ";
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            colorCout("4 ", 2);
            break;

        case '5':  
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout << "  ";
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            colorCout("5 ", 6); 
            break;

        case '6': 
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout << "  ";
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            colorCout("6 ", 1); 
            break;

        case '7':  
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout << "  ";
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            colorCout("7 ", 7); 
            break;

        case '8': 
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            std::cout << "  ";
            gotoxy(matrixStartCol + j*2, matrixStartRow + i);
            colorCout("8 ", 9); 
            break;        
    }
}

//Checking for a win
bool isWin(char** Front, int const size)
{
    for(int i = 1; i < size-1; ++i) {
        for(int j = 1; j < size -1 ; ++j) {
            if(Front[i][j] == '#')
            {
                return false;
            }
        }
    }
    return true;
}

//Print after winning
void win(int** Back, char** Front, int const size, bool* restart, bool* exitFromGame, int const matrixStartRow, int const matrixStartCol, int const rowCenter, int const colCenter)
{
    //Print all mines positions
    gotoxy(matrixStartCol, matrixStartRow);
    for(int i = 1; i < size-1; ++i) {
        for(int j = 1; j < size-1; ++j) {
            if(Back[i][j] == -1) {
                Front[i][j] = 'X';
                greenSymbol(Front, i, j);
            }    
        }
        gotoxy(matrixStartCol, matrixStartRow + i);
    }
    
    //Show inscription WINNER
    Show_Win(colCenter, rowCenter);

    //Restart or Exit to main menu
    for(char key; ; ) {
        cbreak();
        key = keypress();

        if(key == 'r' || key == 'R') {
            *restart = true;
            break; 
        }
        if(key == 27) {
            *exitFromGame = true;
            break;
        }
    }
}

//Open the number
void Open(int **Back, char** Front, int const i, int const j, int* Fcount, int const matrixStartRow, int const matrixStartCol)
{   
    if(Back[i][j] > 0) {
        if(Front[i][j] == 'F') {
            --(*Fcount);
        }

        //In ASCII table symbol of the number = number + 48
        Front[i][j] = Back[i][j] + 48;
        printSymbol(Front, i, j, matrixStartRow, matrixStartCol);        
    }
}

//If there are no mines or numbers under #
/* Inputs: Back: [integer], Front : [char], i, j, Fcount: integer
 * Pre: i < size, j < size, Fcount < Bomb_Count, Back[i][j] = 0
 * Output: Back : [integer], Front : [char], Fcount : integer 
 * Post: Front[i][j] = '_', Back[i][j] = 10, 
 */
void Empty(int** Back, char** Front, int const i, int const j, int* Fcount, int const matrixStartRow, int const matrixStartCol)
{
    Front[i][j] = '_';
    gotoxy(matrixStartCol + j*2, matrixStartRow + i);
    printSymbol(Front, i, j, matrixStartRow, matrixStartCol);

    Back[i][j] = 10;
    
    //Opening all around if under # is empty
    for(int row_i = i - 1; row_i <= i + 1; ++row_i) {
        for(int col_j = j - 1; col_j <= j + 1; ++col_j) {
            if(Front[row_i][col_j] == '#' || Front[row_i][col_j] == 'F') {
                if(Front[row_i][col_j] == 'F') {
                    //Flag count
                    --(*Fcount);
                }

                if(Back[row_i][col_j] == 0) {
                    Empty(Back, Front, row_i, col_j, &(*Fcount), matrixStartRow, matrixStartCol);
                }
                else if(Back[row_i][col_j] < 9 && Back[row_i][col_j] != -2) {
                    Open(Back, Front, row_i, col_j, &(*Fcount), matrixStartRow, matrixStartCol);
                }
            }
        }   
    }
}

//Game over, print all mines positions
void Boom(int **Back, char** Front, int const size, bool* exitFromGame, bool* restart, int const matrixStartRow, int const matrixStartCol, int const rowCenter, int const colCenter)
{   
    for(int i = 1; i < size - 1; ++i) {
        for(int j = 1; j < size - 1; ++j) {
            if(Back[i][j] == -1) {
                Front[i][j] = 'X';
                printSymbol(Front, i, j, matrixStartRow, matrixStartCol);
            }
        }
    }

    //show inscription Game Over
    Show_GameOver(rowCenter, colCenter); 
    //Show_Win(rowCenter, colCenter);

    for(char key; ; ) {
        cbreak();
        key = keypress();

        if(key == 'r' || key == 'R') {
            *restart = true;
            break; 
        }
        if(key == 27) {
            *exitFromGame = true;
            break;
        }
    }
}

//Main game
void game(int** Back, char** Front, int const size, int const bombCount, bool* exitFromGame, int const rowCenter, int const colCenter)
{
    int const matrixStartRow = rowCenter - size/2; 
    int const matrixStartCol = colCenter - size + 1; 

    int i = 1, j = 1, Fcount = 0;
    bool restart = false;
    for(char key = -1; ; ) {
        //Checking the game status
        if(isWin(Front, size)) {
            win(Back, Front, size, &restart, &(*exitFromGame), matrixStartRow, matrixStartCol, rowCenter, colCenter);
        }
        
        cbreak();
        key = keypress();
        
        // Restart or Exit to main menu
        if(key == 'r' || key == 'R' || restart) {
            break;
        }
        if(key == 27 || *exitFromGame) {
            *exitFromGame = true;
            break;
        }
        
        switch (key) {
            case 'w': case 'W':
                //Print specific color of the charcter
                gotoxy(matrixStartCol + j*2, matrixStartRow + i);    
                printSymbol(Front, i, j, matrixStartRow, matrixStartCol);
                
                //Print the next symbol in green color
                if(i == 1) {
                    i = size - 2;
                    gotoxy(matrixStartCol + j*2, matrixStartRow + i);
                    greenSymbol(Front, i, j);
                } else {
                    gotoxy(matrixStartCol + j*2, matrixStartRow + (--i));
                    greenSymbol(Front, i, j);
                    
                }
                break;

            case 's': case 'S': 
                gotoxy(matrixStartCol + j*2, matrixStartRow + i);    
                printSymbol(Front, i, j, matrixStartRow, matrixStartCol);

                if(i == size - 2) {
                    i = 1;
                    gotoxy(matrixStartCol + j*2, matrixStartRow + i);
                    greenSymbol(Front, i, j);
                } else {
                    gotoxy(matrixStartCol + j*2, matrixStartRow + (++i));
                    greenSymbol(Front, i, j);
                    
                }
                break;

            case 'a': case 'A': 
                gotoxy(matrixStartCol + j*2, matrixStartRow + i);    
                printSymbol(Front, i, j, matrixStartRow, matrixStartCol);

                if(j == 1) {
                    j = size - 2;
                    gotoxy(matrixStartCol + j*2, matrixStartRow + i);
                    greenSymbol(Front, i, j);
                } else {
                    gotoxy(matrixStartCol + (--j)*2, matrixStartRow + i);
                    greenSymbol(Front, i, j);
                }    
                break;

            case 'd': case 'D':  
                gotoxy(matrixStartCol + j*2, matrixStartRow + i);    
                printSymbol(Front, i, j, matrixStartRow, matrixStartCol);

                if(j == size - 2) {
                    j = 1;
                    gotoxy(matrixStartCol + j*2, matrixStartRow + i);
                    greenSymbol(Front, i, j);
                } else {
                    gotoxy(matrixStartCol + (++j)*2, matrixStartRow + i);
                    greenSymbol(Front, i, j);
                }    
                break;

            case 'f': case 'F':    //Flags 
                if(Front[i][j] == '#') {
                    if(Fcount < bombCount) {    
                        ++Fcount;
                        Front[i][j] = 'F';
                        printSymbol(Front, i, j, matrixStartRow, matrixStartCol);
                    }      
                } else if (Front[i][j] == 'F') {
                    Front[i][j] = '#';
                    gotoxy(matrixStartCol + j*2, matrixStartRow + i);
                    greenSymbol(Front, i, j);
                    --Fcount;
                }
            
            break;

            case 10:  //10 = Enter
                switch(Back[i][j]) {
                    case -1: //There is mine under cage
                        Boom(Back, Front, size, &(*exitFromGame), &restart, matrixStartRow, matrixStartCol, rowCenter, colCenter);
                        break;
                    case 0: //Empty cage
                        Empty(Back, Front, i, j, &Fcount, matrixStartRow, matrixStartCol);
                        break;
                    default: //There is a number under cage
                        if(Back[i][j] != 10) {
                            Open(Back, Front, i, j, &Fcount, matrixStartRow, matrixStartCol);
                        }
                        break;            
                }
                break;
        }    
    }
}


#endif
