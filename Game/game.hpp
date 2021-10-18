#ifndef GAME
#define GAME

#include <iostream>
#include "input.hpp"

int const matrix_start_col = 69, matrix_start_row = 14;

//To print a character in green color
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
void printSymbol(char** Front, int const i, int const j)  
{
    switch(Front[i][j]) {
        case 'X':
            //Delete previous character
            gotoxy(matrix_start_col + j*2, matrix_start_row + i);   
            std::cout << "  ";
            //Print new character with its specific color
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
            colorCout("1 ", 2); 
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
            colorCout("4 ", 4);
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
            colorCout("8 ", 9); 
            break;        
    }
}

//Checking for a win
bool checking(char** Front, int const size)
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
void win(int** Back, char** Front, int const size)
{
    gotoxy(matrix_start_col + 3, matrix_start_row - 3);
    colorCout("You are WINNER! \342\230\272", 4);

    gotoxy(matrix_start_col + 1, matrix_start_row + size + 2);
    colorCout("Press R to ", 7);
    gotoxy(matrix_start_col + 12, matrix_start_row + size + 2);
    colorCout("RESTART", 5); 
    gotoxy(matrix_start_col + 1, matrix_start_row + size + 3); 
    colorCout("Press Esc to return to ", 7); 
    gotoxy(matrix_start_col + 24, matrix_start_row + size + 3);
    colorCout("MAIN MENU", 5);

    //Print all mines positions
    gotoxy(matrix_start_col, matrix_start_row);
    for(int i = 1; i < size-1; ++i) {
        for(int j = 1; j < size-1; ++j) {
            if(Back[i][j] == -1)
            {
                Front[i][j] = 'X';
                greenSymbol(Front, i, j);
            }    
        }
        gotoxy(matrix_start_col, matrix_start_row + i);
    }
}

//Open the number
void Open(int **Back, char** Front, int const i, int const j, int* Fcount)
{   
    if(Back[i][j] > 0) {
        if(Front[i][j] == 'F') {
            --(*Fcount);
        }

        //In ASCII table symbol of the number = number + 48
        Front[i][j] = Back[i][j] + 48;
        printSymbol(Front, i, j);        
    }
}

//If there are no mines or numbers under #
void Empty(int** Back, char** Front, int const i, int const j, int* Fcount)
{
    Front[i][j] = '_';
    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
    printSymbol(Front, i, j);

    Back[i][j] = 10;
    
    //Opening all around 
    for(int row_i = i - 1; row_i <= i + 1; ++row_i) {
        for(int col_j = j - 1; col_j <= j + 1; ++col_j) {
            if(Front[row_i][col_j] == '#' || Front[row_i][col_j] == 'F') {
                if(Front[row_i][col_j] == 'F') {
                    //Flag count
                    --(*Fcount);
                }

                if(Back[row_i][col_j] == 0) {
                    Empty(Back, Front, row_i, col_j, &(*Fcount));
                }
                else if(Back[row_i][col_j] < 9 && Back[row_i][col_j] != -2) {
                    Open(Back, Front, row_i, col_j, &(*Fcount));
                }
            }
        }   
    }
}

//Game over, print all mines positions
void Boom(int **Back, char** Front, int const size, bool* exitFromGame, bool* restart)
{   
    for(int i = 1; i < size - 1; ++i) {
        for(int j = 1; j < size - 1; ++j) {
            if(Back[i][j] == -1) {
                Front[i][j] = 'X';
                printSymbol(Front, i, j);
            }
        }
    }

    gotoxy(matrix_start_col + 1, matrix_start_row + size + 2);
    colorCout("Press R to ", 7);
    gotoxy(matrix_start_col + 12, matrix_start_row + size + 2);
    colorCout("RESTART", 5); 
    gotoxy(matrix_start_col + 1, matrix_start_row + size + 3); 
    colorCout("Press Esc to return to ", 7); 
    gotoxy(matrix_start_col + 24, matrix_start_row + size + 3);
    colorCout("MAIN MENU", 5);
    
    gotoxy(matrix_start_col + 3, matrix_start_row - 3);
    colorCout("BOOOOM! GAME OVER", 5);

    //I have a problem here
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
void game(int** Back, char** Front, int const size, int const Bomb_Count, bool* exitFromGame)
{
    int i = 1, j = 1, Fcount = 0;
    bool restart = false;
    for(char key = -1; ; ) {
        //Checking the game status
        cbreak();
        key = keypress();
        
        //Not done yet
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
                gotoxy(matrix_start_col + j*2, matrix_start_row + i);    
                printSymbol(Front, i, j);
                
                //Print the next symbol in green color
                if(i == 1) {
                    i = size - 2;
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                    greenSymbol(Front, i, j);
                } else {
                    gotoxy(matrix_start_col + j*2, matrix_start_row + (--i));
                    greenSymbol(Front, i, j);
                    
                }
                break;

            case 's': case 'S': 
                gotoxy(matrix_start_col + j*2, matrix_start_row + i);    
                printSymbol(Front, i, j);

                if(i == size - 2) {
                    i = 1;
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                    greenSymbol(Front, i, j);
                } else {
                    gotoxy(matrix_start_col + j*2, matrix_start_row + (++i));
                    greenSymbol(Front, i, j);
                    
                }
                break;

            case 'a': case 'A': 
                gotoxy(matrix_start_col + j*2, matrix_start_row + i);    
                printSymbol(Front, i, j);

                if(j == 1) {
                    j = size - 2;
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                    greenSymbol(Front, i, j);
                } else {
                    gotoxy(matrix_start_col + (--j)*2, matrix_start_row + i);
                    greenSymbol(Front, i, j);
                }    
                break;

            case 'd': case 'D':  
                gotoxy(matrix_start_col + j*2, matrix_start_row + i);    
                printSymbol(Front, i, j);

                if(j == size - 2) {
                    j = 1;
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                    greenSymbol(Front, i, j);
                } else {
                    gotoxy(matrix_start_col + (++j)*2, matrix_start_row + i);
                    greenSymbol(Front, i, j);
                }    
                break;

            case 'f': case 'F':    //Flags 
                if(Front[i][j] == '#') {
                    if(Fcount < Bomb_Count) {    
                        ++Fcount;
                        Front[i][j] = 'F';
                        printSymbol(Front, i, j);
                    }      
                } else if (Front[i][j] == 'F') {
                    Front[i][j] = '#';
                    gotoxy(matrix_start_col + j*2, matrix_start_row + i);
                    greenSymbol(Front, i, j);
                    --Fcount;
                }
            
            break;

            case 10:  //10 = Enter
                switch(Back[i][j]) {
                    case -1: //There is mine under cage
                        Boom(Back, Front, size, &(*exitFromGame), &restart);
                        break;
                    case 0: //Empty cage
                        Empty(Back, Front, i, j, &Fcount);
                        break;
                    default: //There is a number under cage
                        if(Back[i][j] != 10) {
                            Open(Back, Front, i, j, &Fcount);
                        }
                        break;            
                }
                break;
        }    
    }
}


#endif
